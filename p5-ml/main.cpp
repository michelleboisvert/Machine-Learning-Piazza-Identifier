// Project UID db1f506d06d84ab787baf250c265e24e

#include <iostream>
#include <map>
#include <cmath>
#include <set>
#include <iterator>
#include "csvstream.h"
#include <string.h>
#include <fstream>
#include <sstream>
#include <cassert>
#include <vector>
#include <regex>
#include <exception>

using namespace std;

class Classifier {   
    private:
        //bool isTrainingData;
        int totalNumPosts = 0;
        set<string> setOfUniqueWords;
        set<string> setOfLabels;
        map<string, int> numPostsWWord;
        map<string, int> numPostsWLabel;
        //looks at label, then word, then num posts
        map<string, map<string,int>> numPostsWLabelAndWord;
        map<string, string> contentWithTag;
    public:
    //constructor->file and it looks through to assign variables
        Classifier(const string &ifile, bool debug, bool isTrain, bool isTest){
        csvstream csvinput(ifile);
        map<string, string> line;
        while(csvinput >> line){
            string tag = line["tag"];
            string content = line["content"];
            if(tag != "tag" && content != "content"){//so doesnt add in header
                totalNumPosts++;
                numPostsWLabel[tag]++;// += 1;//adding num posts to label
                setOfLabels.insert(tag);//adding to set of labels
                set<string> uniqueWords = unique_words(content);
                for(string word : uniqueWords){
                    numPostsWLabelAndWord[tag][word]++;
                }
                //insert({content, tag});
            }
            if(isTrain){    
                if(debug){
                    cout << "training data:" << endl;
                    if(line["tag"]!= "tag" && line["content"] != "content"){
                        cout << "label = " << line["tag"] << ", content = ";
                        cout << line["content"] << endl;
                    }
                }
                
            }
        }
        if(isTrain){
        cout << "trained on " << totalNumPosts << " examples" << endl;
            if(debug)
                cout << "vocabulary size = " << setOfUniqueWords.size() << endl;
            cout << "\n";
            if(debug){
                cout << "classes:" << endl;
                for(string tag : setOfLabels){
                    cout << " . " << tag << ", " << numPostsWLabel[tag]; 
                    cout << " examples, log-prior = " << getLogPrior(tag) << endl;
                }
                cout << "classifier parameters:" << endl;
                for(auto it : numPostsWLabelAndWord){
                    for(auto it2 : it.second){
                        cout << "  " << it.first << ":" << it2.first << ", count = " << 
                        it2.second << ", log-likelihood = ";
                        cout << getLogLikelihood(it.first, it2.first) << endl;
                    }
                }
                cout << "\n";
            }
        }
        if(isTest){
            int correct = 0;
            cout << "test data:" << endl;
            for(auto it : numPostsWLabelAndWord){
                    for(auto it2 : it.second){
                map<string, string> tempPost;
                tempPost.insert({it.first, it2.first});
                //set<string> wordsInPost = unique_words(it2.first);
                //test for best label
                cout << "  " << "correct = " << it.first << ", predicted = " << predictedLabel(tempPost);  
                cout << ", log-probability score = " << getLogProbScore(it.first, setOfUniqueWords) << endl;
                cout << "  content = " << it2.first << endl;
                cout << "\n";
                if(it.first == predictedLabel(tempPost))
                    correct++;
    
            }
            }
            cout << "performance: " << correct << " / " << getTotalNumPosts() << " posts predicted correctly" << endl;
            cout << "\n";
        }
        } 

    //getter functions
    int getTotalNumPosts(){
        return totalNumPosts;
    }
    
    map<string, map<string,int>> getNumPostsWLabelAndWord(){
        return numPostsWLabelAndWord;
    }

    /*void inputLine(map<string, string> line){
        string tag = line["tag"];
        string content = line["content"];
        if(tag != "tag" && content != "content"){//so doesnt add in header
            totalNumPosts++;
            numPostsWLabel[tag]++;// += 1;//adding num posts to label
            setOfLabels.insert(tag);//adding to set of labels
            set<string> uniqueWords = unique_words(content);
            for(string word : uniqueWords){
                numPostsWLabelAndWord[tag][word]++;
            }
        }
    }*/
    
    //separates the content line into individual words
    set<string> unique_words(const string &str) {
        istringstream source(str);
        set<string> words;
        string word;
        while (source >> word){
            words.insert(word);
            numPostsWWord[word]++;
        }
        return words;
    }

    string predictedLabel(map<string, string> post){
        string labelInPost = post["tag"];
        set<string> wordsInPost = unique_words(post["content"]);

        //testing each label with each word
        string bestLabel = "";
        double maxProbForLabel = 0;
        for(auto label : setOfLabels){
            if(maxProbForLabel < getLogProbScore(label, wordsInPost)){
                maxProbForLabel = getLogProbScore(label, wordsInPost);
                bestLabel = label;
            }
        }
        return bestLabel;
    }

    //determines probability for a label from a post
    double getLogProbScore(const string &givenLabel, set<string> wordsInPost) {//[label] to find num of posts for a word
        double probability = getLogPrior(givenLabel);//initial prob of (#posts w/ label C)/(#posts)
        for(auto word : wordsInPost){
            probability += (double)getLogLikelihood(givenLabel, word);
        }
        return probability;
    }
    
    double getLogPrior(const string &label) {
       return log(numPostsWLabel[label]/(double)totalNumPosts);
    }

    double getLogLikelihood(const string &givenLabel, const string &word) {
        double numPosts = numPostsWLabelAndWord[givenLabel][word];
        double nPWW = numPostsWWord[word];
        if(nPWW == 0.0)
            return log(1.0/totalNumPosts);
        else if(numPosts == 0.0)
            return log(nPWW/totalNumPosts);
        else{
            return log(numPosts/numPostsWLabel[givenLabel]);
        }
    }
    ~Classifier() {}
};

int main(int argc, char **argv){
    cout.precision(3);
    if(argc < 3 || argc > 4){
        cout << "Usage: main.exe TRAIN_FILE TEST_FILE [--debug]" << endl;
        return -1;
    }
    else if(argc == 4 && strcmp(argv[3], "--debug") != 0){
        cout << "Usage: main.exe TRAIN_FILE TEST_FILE [--debug]" << endl;
        return -1;
    }
    else{
        bool debug = false;
        if(argc == 4)
            debug = true;
        Classifier train = Classifier(argv[1], debug, true, false);
        Classifier test = Classifier(argv[2], debug, false, true);
    }
}
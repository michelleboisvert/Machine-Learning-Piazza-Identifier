// Project UID db1f506d06d84ab787baf250c265e24e

#include "BinarySearchTree.h"
#include "unit_test_framework.h"

using namespace std;


TEST(test_stub) {
    // Add your tests here
    ASSERT_TRUE(true);
}

TEST(bst_public_test) {
  BinarySearchTree<int> tree;

  tree.insert(5);

  ASSERT_TRUE(tree.size() == 1);
  ASSERT_TRUE(tree.height() == 1);

  ASSERT_TRUE(tree.find(5) != tree.end());

  tree.insert(7);
  tree.insert(3);

  ASSERT_TRUE(tree.check_sorting_invariant());
  ASSERT_TRUE(*tree.max_element() == 7);
  ASSERT_TRUE(*tree.min_element() == 3);
  ASSERT_TRUE(*tree.min_greater_than(5) == 7);

  cout << "cout << tree.to_string()" << endl;
  cout << tree.to_string() << endl << endl;

  cout << "cout << tree" << endl << "(uses iterators)" << endl;
  cout << tree << endl << endl;

  ostringstream oss_preorder;
  tree.traverse_preorder(oss_preorder);
  cout << "preorder" << endl;
  cout << oss_preorder.str() << endl << endl;
  ASSERT_TRUE(oss_preorder.str() == "5 3 7 ");

  ostringstream oss_inorder;
  tree.traverse_inorder(oss_inorder);
  cout << "inorder" << endl;
  cout << oss_inorder.str() << endl << endl;
  ASSERT_TRUE(oss_inorder.str() == "3 5 7 ");
}

TEST(bst_empty_tree) {
  BinarySearchTree<int> tree;

  ASSERT_TRUE(tree.empty());
  ASSERT_TRUE(tree.size() == 0);
  ASSERT_TRUE(tree.height() == 0);

  BinarySearchTree<int>::Iterator findtemp = tree.find(8);
  ASSERT_TRUE(findtemp == tree.end());

  ASSERT_TRUE(tree.min_element() == tree.end());
  ASSERT_TRUE(tree.max_element() == tree.end());
  ASSERT_TRUE(tree.check_sorting_invariant());
  
  ostringstream oss_preorder;
  tree.traverse_preorder(oss_preorder);
  cout << "preorder" << endl;
  cout << oss_preorder.str() << endl << endl;
  ASSERT_TRUE(oss_preorder.str() == "");

  ostringstream oss_inorder;
  tree.traverse_inorder(oss_inorder);
  cout << "inorder" << endl;
  cout << oss_inorder.str() << endl << endl;
  ASSERT_TRUE(oss_inorder.str() == "");

  ASSERT_TRUE(tree.min_greater_than(6) == tree.end());
}

TEST(bst_big_three_empty_tree){

  BinarySearchTree<int> tree;
  //big 3
  BinarySearchTree<int> copy_empty_tree(tree);//copy constructor
  BinarySearchTree<int> assign_empty_tree = tree;//assignment operator

  //copy 
  ASSERT_TRUE(copy_empty_tree.empty());
  ASSERT_TRUE(copy_empty_tree.size() == 0);
  ASSERT_TRUE(copy_empty_tree.height() == 0);

  ASSERT_TRUE(copy_empty_tree.min_element() == copy_empty_tree.end());
  ASSERT_TRUE(copy_empty_tree.max_element() == copy_empty_tree.end());
  ASSERT_TRUE(copy_empty_tree.check_sorting_invariant());
  ostringstream oss_preorder;
  copy_empty_tree.traverse_preorder(oss_preorder);
  cout << "preorder" << endl;
  cout << oss_preorder.str() << endl << endl;
  ASSERT_TRUE(oss_preorder.str() == "");
  
  ostringstream oss_inorder;
  copy_empty_tree.traverse_inorder(oss_inorder);
  cout << "inorder" << endl;
  cout << oss_inorder.str() << endl << endl;
  ASSERT_TRUE(oss_inorder.str() == "");

  ASSERT_TRUE(copy_empty_tree.min_greater_than(6) == copy_empty_tree.end());

  //assignment
  ASSERT_TRUE(assign_empty_tree.empty());
  ASSERT_TRUE(assign_empty_tree.size() == 0);
  ASSERT_TRUE(assign_empty_tree.height() == 0);

  ASSERT_TRUE(assign_empty_tree.min_element() == assign_empty_tree.end());
  ASSERT_TRUE(assign_empty_tree.max_element() == assign_empty_tree.end());
  ASSERT_TRUE(assign_empty_tree.check_sorting_invariant());
  assign_empty_tree.traverse_preorder(oss_preorder);
  cout << "preorder" << endl;
  cout << oss_preorder.str() << endl << endl;
  ASSERT_TRUE(oss_preorder.str() == "");

  assign_empty_tree.traverse_inorder(oss_inorder);
  cout << "inorder" << endl;
  cout << oss_inorder.str() << endl << endl;
  ASSERT_TRUE(oss_inorder.str() == "");

  ASSERT_TRUE(assign_empty_tree.min_greater_than(6) == assign_empty_tree.end());
}

TEST(bst_one_node_tree){

  BinarySearchTree<int> tree;

  tree.insert(4);
  ASSERT_FALSE(tree.empty());
  ASSERT_TRUE(tree.size() == 1);
  ASSERT_TRUE(tree.height() == 1); 
  ASSERT_TRUE(*tree.min_element() == 4);
  ASSERT_TRUE(*tree.max_element() == 4);
  ASSERT_TRUE(tree.check_sorting_invariant());

  ostringstream oss_preorder;
  tree.traverse_preorder(oss_preorder);
  cout << "preorder" << endl;
  cout << oss_preorder.str() << endl << endl;
  ASSERT_TRUE(oss_preorder.str() == "4 ");
  ostringstream oss_inorder;
  tree.traverse_inorder(oss_inorder);
  cout << "inorder" << endl;
  cout << oss_inorder.str() << endl << endl;
  ASSERT_TRUE(oss_inorder.str() == "4 ");

  ASSERT_TRUE(*tree.min_greater_than(3) == 4);
  ASSERT_TRUE(tree.min_greater_than(5) == tree.end());

  tree.insert(3);
  tree.insert(5);

  ASSERT_TRUE(tree.check_sorting_invariant());
}

TEST(bst_big_three_one_node_tree){

  BinarySearchTree<int> tree;
  tree.insert(4);
  //big 3
  BinarySearchTree<int> copy_one_tree(tree);//copy constructor
  BinarySearchTree<int> assign_one_tree = tree;//assignment operator

  //copy 
  ASSERT_FALSE(copy_one_tree.empty());
  ASSERT_TRUE(copy_one_tree.size() == 1);
  ASSERT_TRUE(copy_one_tree.height() == 1);

  ASSERT_TRUE(*copy_one_tree.min_element() == 4);
  ASSERT_TRUE(*copy_one_tree.max_element() == 4);
  ASSERT_TRUE(copy_one_tree.check_sorting_invariant());
  ostringstream oss_preorder1;
  copy_one_tree.traverse_preorder(oss_preorder1);
  cout << "preorder" << endl;
  cout << oss_preorder1.str() << endl << endl;
  ASSERT_TRUE(oss_preorder1.str() == "4 ");
  
  ostringstream oss_inorder1;
  copy_one_tree.traverse_inorder(oss_inorder1);
  cout << "inorder" << endl;
  cout << oss_inorder1.str() << endl << endl;
  ASSERT_TRUE(oss_inorder1.str() == "4 ");

  ASSERT_TRUE(*copy_one_tree.min_greater_than(3) == 4);
  ASSERT_TRUE(copy_one_tree.min_greater_than(5) == tree.end());

  //assignment
  ASSERT_FALSE(assign_one_tree.empty());
  ASSERT_TRUE(assign_one_tree.size() == 1);
  ASSERT_TRUE(assign_one_tree.height() == 1);

  ASSERT_TRUE(*assign_one_tree.min_element() == 4);
  ASSERT_TRUE(*assign_one_tree.max_element() == 4);
  ASSERT_TRUE(assign_one_tree.check_sorting_invariant());
  ostringstream oss_preorder2;
  assign_one_tree.traverse_preorder(oss_preorder2);
  cout << "preorder" << endl;
  cout << oss_preorder2.str() << endl << endl;
  ASSERT_TRUE(oss_preorder2.str() == "4 ");
  ostringstream oss_inorder2;
  assign_one_tree.traverse_inorder(oss_inorder2);
  cout << "inorder" << endl;
  cout << oss_inorder2.str() << endl << endl;
  ASSERT_TRUE(oss_inorder2.str() == "4 ");

  ASSERT_TRUE(*assign_one_tree.min_greater_than(3) == 4);
  ASSERT_TRUE(assign_one_tree.min_greater_than(5) == tree.end());
}

TEST(bst_left_branch){//only nodes in left subtree
    BinarySearchTree<int> tree;
    tree.insert(5);
    tree.insert(4);
    tree.insert(3);

    ASSERT_FALSE(tree.empty());
    ASSERT_TRUE(tree.size() == 3);
    ASSERT_TRUE(tree.height() == 3);

    BinarySearchTree<int> copy_left_tree(tree);//copy constructor
    BinarySearchTree<int> assign_left_tree = tree;//assignment operator
    ASSERT_TRUE(copy_left_tree.size() == 3);
    ASSERT_TRUE(copy_left_tree.height() == 3);
    ASSERT_TRUE(assign_left_tree.size() == 3);
    ASSERT_TRUE(assign_left_tree.height() == 3);

    BinarySearchTree<int>::Iterator findtemp = tree.find(8);
    ASSERT_TRUE(findtemp == tree.end());
    findtemp = tree.find(5);
    ASSERT_TRUE(*findtemp == 5);

    ASSERT_TRUE(*tree.min_element() == 3);
    ASSERT_TRUE(*tree.max_element() == 5);

    ostringstream oss_preorder;
    tree.traverse_preorder(oss_preorder);
    cout << "preorder" << endl;
    cout << oss_preorder.str() << endl << endl;
    ASSERT_TRUE(oss_preorder.str() == "5 4 3 ");
    ostringstream oss_inorder;
    tree.traverse_inorder(oss_inorder);
    cout << "inorder" << endl;
    cout << oss_inorder.str() << endl << endl;
    ASSERT_TRUE(oss_inorder.str() == "3 4 5 ");

    ASSERT_TRUE(*tree.min_greater_than(4) == 5);
}

TEST(bst_right_branch){//only nodes in left subtree
    BinarySearchTree<int> tree;
    tree.insert(5);
    tree.insert(6);
    tree.insert(7);
    tree.insert(8);

    ASSERT_FALSE(tree.empty());
    ASSERT_TRUE(tree.size() == 4);
    ASSERT_TRUE(tree.height() == 4);

    BinarySearchTree<int> copy_right_tree(tree);//copy constructor
    BinarySearchTree<int> assign_right_tree = tree;//assignment operator
    ASSERT_TRUE(copy_right_tree.size() == 4);
    ASSERT_TRUE(copy_right_tree.height() == 4);
    ASSERT_TRUE(assign_right_tree.size() == 4);
    ASSERT_TRUE(assign_right_tree.height() == 4);

    BinarySearchTree<int>::Iterator findtemp = tree.find(2);
    ASSERT_TRUE(findtemp == tree.end());
    findtemp = tree.find(7);
    ASSERT_TRUE(*findtemp == 7);

    ASSERT_TRUE(*tree.min_element() == 5);
    ASSERT_TRUE(*tree.max_element() == 8);

    ostringstream oss_preorder;
    tree.traverse_preorder(oss_preorder);
    cout << "preorder" << endl;
    cout << oss_preorder.str() << endl << endl;
    ASSERT_TRUE(oss_preorder.str() == "5 6 7 8 ");
    ostringstream oss_inorder;
    tree.traverse_inorder(oss_inorder);
    cout << "inorder" << endl;
    cout << oss_inorder.str() << endl << endl;
    ASSERT_TRUE(oss_inorder.str() == "5 6 7 8 ");

    ASSERT_TRUE(*tree.min_greater_than(6) == 7);
}

TEST(bst_complex){//kinda testing everything left
    BinarySearchTree<int> tree;
    tree.insert(5); tree.insert(3); tree.insert(2); tree.insert(4);
    tree.insert(7); tree.insert(6); tree.insert(9); tree.insert(8);

    ASSERT_FALSE(tree.empty());
    ASSERT_TRUE(tree.size() == 8);
    ASSERT_TRUE(tree.height() == 4);

    BinarySearchTree<int>::Iterator findtemp10 = tree.find(10);
    ASSERT_TRUE(findtemp10 == tree.end());

    BinarySearchTree<int>::Iterator findtemp1 = tree.find(1);
    ASSERT_TRUE(findtemp1 == tree.end());

    BinarySearchTree<int>::Iterator findtemp = tree.find(8);
    ASSERT_TRUE(*findtemp == 8);

    ASSERT_TRUE(*tree.min_element() == 2);
    ASSERT_TRUE(*tree.max_element() == 9);
    ASSERT_TRUE(tree.check_sorting_invariant());

    ostringstream oss_preorder;
    tree.traverse_preorder(oss_preorder);
    cout << "preorder" << endl;
    cout << oss_preorder.str() << endl << endl;
    ASSERT_TRUE(oss_preorder.str() == "5 3 2 4 7 6 9 8 ");
    ostringstream oss_inorder;
    tree.traverse_inorder(oss_inorder);
    cout << "inorder" << endl;
    cout << oss_inorder.str() << endl << endl;
    ASSERT_TRUE(oss_inorder.str() == "2 3 4 5 6 7 8 9 ");

    ASSERT_TRUE(*tree.min_greater_than(3) == 4);
    ASSERT_TRUE(*tree.min_greater_than(7) == 8);
    ASSERT_TRUE(*tree.min_greater_than(5) == 6);
}
//testing big three for complex bst
TEST(bst_complex_big_three_part_one){
    BinarySearchTree<int> tree;
    tree.insert(5); tree.insert(3); tree.insert(2); tree.insert(4);
    tree.insert(7); tree.insert(6); tree.insert(9); tree.insert(8);

    BinarySearchTree<int> copy_tree(tree);//copy constructor
    BinarySearchTree<int> assign_tree = tree;//assignment operator

    ASSERT_FALSE(copy_tree.empty());
    ASSERT_FALSE(assign_tree.empty());
    ASSERT_TRUE(copy_tree.size() == 8);
    ASSERT_TRUE(assign_tree.size() == 8);
    ASSERT_TRUE(copy_tree.height() == 4);
    ASSERT_TRUE(assign_tree.height() == 4);

    BinarySearchTree<int>::Iterator findtemp10copy = copy_tree.find(10);
    BinarySearchTree<int>::Iterator findtemp10assign = assign_tree.find(10);
    ASSERT_TRUE(findtemp10copy == copy_tree.end());
    ASSERT_TRUE(findtemp10assign == assign_tree.end());

    BinarySearchTree<int>::Iterator findtemp1copy = copy_tree.find(1);
    BinarySearchTree<int>::Iterator findtemp1assign = assign_tree.find(1);
    ASSERT_TRUE(findtemp1copy == copy_tree.end());
    ASSERT_TRUE(findtemp1assign == assign_tree.end());

    BinarySearchTree<int>::Iterator findtempcopy = copy_tree.find(8);
    BinarySearchTree<int>::Iterator findtempassign = assign_tree.find(8);
    ASSERT_TRUE(*findtempcopy == 8);
    ASSERT_TRUE(*findtempassign == 8);

    copy_tree.insert(12);
    assign_tree.insert(12);
    ASSERT_TRUE(copy_tree.size() == 9);
    ASSERT_TRUE(assign_tree.size() == 9);
    ASSERT_TRUE(copy_tree.height() == 4);
    ASSERT_TRUE(assign_tree.height() == 4);
}

TEST(bst_complex_big_three_part_two){
    BinarySearchTree<int> tree;
    tree.insert(5); tree.insert(3); tree.insert(2); tree.insert(4);
    tree.insert(7); tree.insert(6); tree.insert(9); tree.insert(8);

    BinarySearchTree<int> copy_tree(tree);//copy constructor
    BinarySearchTree<int> assign_tree = tree;//assignment operator

    ASSERT_TRUE(*copy_tree.min_element() == 2);
    ASSERT_TRUE(*assign_tree.min_element() == 2);
    ASSERT_TRUE(*copy_tree.max_element() == 9);
    ASSERT_TRUE(*assign_tree.max_element() == 9);
    ASSERT_TRUE(copy_tree.check_sorting_invariant());
    ASSERT_TRUE(assign_tree.check_sorting_invariant());

    ostringstream oss_preorder_copy;
    copy_tree.traverse_preorder(oss_preorder_copy);
    cout << "preorder" << endl;
    cout << oss_preorder_copy.str() << endl << endl;
    ASSERT_TRUE(oss_preorder_copy.str() == "5 3 2 4 7 6 9 8 ");
    ostringstream oss_inorder_copy;
    copy_tree.traverse_inorder(oss_inorder_copy);
    cout << "inorder" << endl;
    cout << oss_inorder_copy.str() << endl << endl;
    ASSERT_TRUE(oss_inorder_copy.str() == "2 3 4 5 6 7 8 9 ");

    ostringstream oss_preorder_assign;
    assign_tree.traverse_preorder(oss_preorder_assign);
    cout << "preorder" << endl;
    cout << oss_preorder_assign.str() << endl << endl;
    ASSERT_TRUE(oss_preorder_assign.str() == "5 3 2 4 7 6 9 8 ");
    ostringstream oss_inorder_assign;
    assign_tree.traverse_inorder(oss_inorder_assign);
    cout << "inorder" << endl;
    cout << oss_inorder_assign.str() << endl << endl;
    ASSERT_TRUE(oss_inorder_assign.str() == "2 3 4 5 6 7 8 9 ");

    ASSERT_TRUE(*copy_tree.min_greater_than(3) == 4);
    ASSERT_TRUE(*assign_tree.min_greater_than(3) == 4);
    ASSERT_TRUE(*copy_tree.min_greater_than(7) == 8);
    ASSERT_TRUE(*assign_tree.min_greater_than(7) == 8);
    ASSERT_TRUE(*copy_tree.min_greater_than(5) == 6);
    ASSERT_TRUE(*assign_tree.min_greater_than(5) == 6);
}

//test different data types
TEST(bst_double_tree){

  BinarySearchTree<double> tree;

  tree.insert(4.5); tree.insert(9.8);
  ASSERT_FALSE(tree.empty());
  ASSERT_TRUE(tree.size() == 2);
  ASSERT_TRUE(tree.height() == 2); 
  ASSERT_TRUE(*tree.min_element() == 4.5);
  ASSERT_TRUE(*tree.max_element() == 9.8);
  ASSERT_TRUE(tree.check_sorting_invariant());

  ostringstream oss_preorder;
  tree.traverse_preorder(oss_preorder);
  cout << "preorder" << endl;
  cout << oss_preorder.str() << endl << endl;
  ASSERT_TRUE(oss_preorder.str() == "4.5 9.8 ");
  ostringstream oss_inorder;
  tree.traverse_inorder(oss_inorder);
  cout << "inorder" << endl;
  cout << oss_inorder.str() << endl << endl;
  ASSERT_TRUE(oss_inorder.str() == "4.5 9.8 ");

  ASSERT_TRUE(*tree.min_greater_than(3.2) == 4.5);
  ASSERT_TRUE(tree.min_greater_than(10.5) == tree.end());
}

TEST(bst_char_tree){

  BinarySearchTree<char> tree;

  tree.insert('a'); tree.insert('c');
  ASSERT_FALSE(tree.empty());
  ASSERT_TRUE(tree.size() == 2);
  ASSERT_TRUE(tree.height() == 2); 
  ASSERT_TRUE(*tree.min_element() == 'a');
  ASSERT_TRUE(*tree.max_element() == 'c');
  ASSERT_TRUE(tree.check_sorting_invariant());

  ostringstream oss_preorder;
  tree.traverse_preorder(oss_preorder);
  cout << "preorder" << endl;
  cout << oss_preorder.str() << endl << endl;
  ASSERT_TRUE(oss_preorder.str() == "a c ");
  ostringstream oss_inorder;
  tree.traverse_inorder(oss_inorder);
  cout << "inorder" << endl;
  cout << oss_inorder.str() << endl << endl;
  ASSERT_TRUE(oss_inorder.str() == "a c ");

  ASSERT_TRUE(*tree.min_greater_than('b') == 'c');
  ASSERT_TRUE(tree.min_greater_than('d') == tree.end());
}

TEST(bst_string_tree){

  BinarySearchTree<string> tree;

  tree.insert("bird"); tree.insert("dog");
  ASSERT_FALSE(tree.empty());
  ASSERT_TRUE(tree.size() == 2);
  ASSERT_TRUE(tree.height() == 2); 
  ASSERT_TRUE(*tree.min_element() == "bird");
  ASSERT_TRUE(*tree.max_element() == "dog");
  ASSERT_TRUE(tree.check_sorting_invariant());

  ostringstream oss_preorder;
  tree.traverse_preorder(oss_preorder);
  cout << "preorder" << endl;
  cout << oss_preorder.str() << endl << endl;
  ASSERT_TRUE(oss_preorder.str() == "bird dog ");
  ostringstream oss_inorder;
  tree.traverse_inorder(oss_inorder);
  cout << "inorder" << endl;
  cout << oss_inorder.str() << endl << endl;
  ASSERT_TRUE(oss_inorder.str() == "bird dog ");

  ASSERT_TRUE(*tree.min_greater_than("cat") == "dog");
  ASSERT_TRUE(tree.min_greater_than("fish") == tree.end());
}

TEST(bst_const_tree){
  BinarySearchTree<int> tree;
  const BinarySearchTree<int> &const_tree = tree;
  BinarySearchTree<int> tree_copy(const_tree);
  ASSERT_TRUE(const_tree.empty());
  ASSERT_TRUE(const_tree.size() == 0);
  ASSERT_TRUE(const_tree.height() == 0);
  ASSERT_TRUE(const_tree.check_sorting_invariant());
  ASSERT_TRUE(const_tree.min_element() == const_tree.end());
  ASSERT_TRUE(const_tree.max_element() == const_tree.end());
  ASSERT_TRUE(const_tree.check_sorting_invariant());
  ASSERT_TRUE(const_tree.min_greater_than(6) == const_tree.end());

  ostringstream oss_preorder;
  const_tree.traverse_preorder(oss_preorder);
  cout << "preorder" << endl;
  cout << oss_preorder.str() << endl << endl;
  ASSERT_TRUE(oss_preorder.str() == "");
  ostringstream oss_inorder;
  const_tree.traverse_inorder(oss_inorder);
  cout << "inorder" << endl;
  cout << oss_inorder.str() << endl << endl;
  ASSERT_TRUE(oss_inorder.str() == "");


  ASSERT_TRUE(tree_copy.empty());
  ASSERT_TRUE(tree_copy.size() == 0);
  ASSERT_TRUE(tree_copy.height() == 0);
  ASSERT_TRUE(tree_copy.check_sorting_invariant());
  ASSERT_TRUE(tree_copy.min_element() == tree_copy.end());
  ASSERT_TRUE(tree_copy.max_element() == tree_copy.end());
  ASSERT_TRUE(tree_copy.check_sorting_invariant());
  ASSERT_TRUE(tree_copy.min_greater_than(6) == tree_copy.end());

  ostringstream oss_preorder2;
  tree_copy.traverse_preorder(oss_preorder2);
  cout << "preorder" << endl;
  cout << oss_preorder2.str() << endl << endl;
  ASSERT_TRUE(oss_preorder2.str() == "");
  ostringstream oss_inorder2;
  tree_copy.traverse_inorder(oss_inorder2);
  cout << "inorder" << endl;
  cout << oss_inorder2.str() << endl << endl;
  ASSERT_TRUE(oss_inorder2.str() == "");

}

/*TEST(bst_tree_sway){

  BinarySearchTree<int> tree1;
  BinarySearchTree<int> tree2;
  BinarySearchTree<int> tree3;
  BinarySearchTree<int> tree4;

  tree1.insert(4);
  tree1.insert(2);

  int temp = tree1.tree_sway();
  ASSERT_EQUAL(tree1.tree_sway(), -1);

  tree2.insert(4);
  tree2.insert(2);
  tree2.insert(7);
  ASSERT_EQUAL(tree2.tree_sway(), 0);

  tree3.insert(4);
  tree3.insert(7);
  tree3.insert(9);
  ASSERT_EQUAL(tree3.tree_sway(), 2);

  tree4.insert(4);
  tree4.insert(7);
  tree4.insert(5);
  ASSERT_EQUAL(tree4.tree_sway(), 0);

}*/

/*TEST(bst_duck_tree){


  BinarySearchTree<Duck, DuckWealthLess> duck_tree_copy(const_duck_tree);
  BinarySearchTree<Duck, DuckWealthLess> duck_tree_copy(const_duck_tree);

  tree.insert("bird"); tree.insert("dog");
  ASSERT_FALSE(tree.empty());
  ASSERT_TRUE(tree.size() == 2);
  ASSERT_TRUE(tree.height() == 2); 
  ASSERT_TRUE(*tree.min_element() == "bird");
  ASSERT_TRUE(*tree.max_element() == "dog");
  ASSERT_TRUE(tree.check_sorting_invariant());

  ostringstream oss_preorder;
  tree.traverse_preorder(oss_preorder);
  cout << "preorder" << endl;
  cout << oss_preorder.str() << endl << endl;
  ASSERT_TRUE(oss_preorder.str() == "bird dog ");
  ostringstream oss_inorder;
  tree.traverse_inorder(oss_inorder);
  cout << "inorder" << endl;
  cout << oss_inorder.str() << endl << endl;
  ASSERT_TRUE(oss_inorder.str() == "bird dog ");

  ASSERT_TRUE(*tree.min_greater_than("cat") == "dog");
  ASSERT_TRUE(tree.min_greater_than("fish") == tree.end());
}*/


TEST_MAIN()

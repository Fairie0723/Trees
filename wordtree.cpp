
/**********************************
 This is the implementation file
 for the wordtree.h file.
**********************************/
#include "wordtree.h"
#include <iostream>
#include <algorithm>


/**************************************
Function: WordTree()
Input: None
Output: None - Constructor
***************************************/
//constructor – Initializes an empty tree
WordTree::WordTree(){
    root = nullptr; // sets the root to null
}


/**************************************
Function: ~WordTree()
Input: None
Output: None - Destructor
***************************************/
//destructor
WordTree::~WordTree(){
    deleteSubTree(root);
}


/**************************************
Function: addWord()
Input:TreeNode *&, string
Output: recursive function that adds the words to the tree
***************************************/
// The recursive function should add a node containing the word to the tree,
// if the word is not found, or increment the word’s count, if it is already in the tree.
void WordTree::addWord(TreeNode *& node,  std::string& add_word) {
    //if node is empty, create node
    if (node == nullptr) {
        node = new TreeNode();
        node->value = add_word;
        node->left = node->right = nullptr;
    }
    //if word is equal to the node ++ the counter
    if(add_word == node->value){
        node->count++;
    }
    //otherwise navigate to the left node then add it.
    else if (add_word < node->value){
        if (node->left == nullptr){
            node->left = new TreeNode();
            node->left->value = add_word;
            node->left->count = 1;
        }else {
            addWord(node->left, add_word);
        }
    }
    //otherwise navigate to the right side of the tree  and check for that word and then add it
    else {
            addWord(node->right, add_word);
    }
}




/**************************************
Function: getCounts()
Input: TreeNode *, int, int&
Output: prints the number of words according to the query. recursive
        if a word meets or exceeds threshold will also print.
***************************************/

void WordTree::getCounts(TreeNode *node, int threshold , int& query) const {
    if (node == nullptr) {}
    else {
        getCounts(node->left, threshold, query);

        if (node->count >= threshold) {
            std::cout << node->value << "(" << node->count << ")" << std::endl;
            query++;
        }
        getCounts(node->right, threshold, query);

    }
}


/**************************************
Function: addWord (helper)
Input: string
Output: helper function for the addWord function
***************************************/
void WordTree::addWord(std::string word){
    std::transform(word.begin(), word.end(), word.begin(), ::tolower);
    addWord(root, word);
}


/**************************************
Function:findWord();
Input: string
Output:  a loop that traverses the tree. if the word is found
        it prints it. otherwise no text found
***************************************/
// Iterative function that searches for a word in the tree. If the word is found,
// it outputs the word and its occurrence count.
// Otherwise it displays a message stating that the word was not found (see sample output)
void WordTree::findWord(std::string word) {
TreeNode *node = root;
std::cout << "Searching for occurrences of the word '" << word << "'\n";
while(node != nullptr){
    if(node->value == word){
        std::cout << "The word '" << word << "' occurs " << node->count << " time(s) in the text.\n";
        return;
    }
    else if (node->value > word){
        node = node->left;
    }
    else {
        node = node->right;
    }
}
std::cout << "The word '" << word << "' was not found in the text.\n";
}


/**************************************
Function: getsCounts (helper)
Input: int
Output: helper function for the getCounts function
***************************************/
// searches for words that meet or exceed a threshold count.
void WordTree::getCounts(int threshold) {
    int count = 0;
    getCounts(root, threshold, count);
    std::cout << count << " nodes had words with " << threshold << " or more occurrence(s).\n";
}

/**************************************
Function: deleteSubTree ()
Input: TreeNode
Output: recursive function that explicitly deletes node from the tree.
***************************************/
void WordTree::deleteSubTree(TreeNode *node){
    if (node != nullptr){
        deleteSubTree( node-> left);
        deleteSubTree( node-> right);

        delete node;
    }
}

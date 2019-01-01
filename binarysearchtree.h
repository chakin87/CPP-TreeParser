#ifndef BST_H_
#define BST_H_

#include<iostream>
#include <queue>
using namespace std;
#include<string>

#include "Node.h"

//BST class
class BinarySearchTree{

    private:
        Node * root;        //root node pointer

    public:
        BinarySearchTree();                                  //constructor
        ~BinarySearchTree();                                 //destructor
        void Insert(int num, string data);                  //Inserts new number in tree
        void inorderPrint();
        void preorderPrint();
        void postorderPrint();
		void printBTbylevel2();


        //private functions used as helper functions in the public operations
    private:
        void inorderPrintHelper(Node *root);
        void preorderPrintHelper(Node *root);
        void postorderPrintHelper(Node *root);
        void InsertHelper(Node* current, Node* newnode);
        void clear(Node *current);
};

#endif
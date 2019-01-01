#ifndef NODE_H_
#define NODE_H_

#include<iostream>
using namespace std;


class Node{

    private:
        //int data;                       //number
        Node *left;                     //left child
        Node *right;                    //right child
       // std::string num;
       int num;
       string data;
    public:
        Node();                         //constructor
        void setData(int num, string data);         //sets number in node
        string getData();                   //return numbers from node
        string getName();
        int getNumber();
        void setLeft(Node *l);          //sets left child pointer
        Node* getLeft();                //returns left child pointer
        void setRight(Node *r);         //sets right child pointer
        Node* getRight();               //return right child pointer
};


#endif
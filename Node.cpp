#include"Node.h"
#include<string>

Node::Node()
{
    this->left = NULL;
    this->right = NULL;
}


void Node::setData(int num, string data)
{
    this->num = num;
    this->data = data;
}

string Node::getName(){
    return this->data;
}
int Node::getNumber(){
    return this->num;
}

string Node::getData()
{
	return this->data;
}

void Node::setLeft(Node *l)
{
    this->left = l;
}

Node* Node::getLeft()
{
    return this->left;
}

void Node::setRight(Node *r)
{
    this->right = r;
}

Node* Node::getRight()
{
    return this->right;
}
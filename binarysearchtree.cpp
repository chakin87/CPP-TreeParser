#include"binarysearchtree.h"
#include<string>
#include<fstream>

BinarySearchTree::BinarySearchTree()
{
    this->root = NULL;      //root is NULL in the start
}

BinarySearchTree::~BinarySearchTree()
{
    clear(root);            //delete all nodes
}

void BinarySearchTree::clear(Node* current)
{
    if(current == NULL)
        return;

    clear(current->getLeft());          //clear left subtree
    clear(current->getRight());         //clear right subtree
    delete current;                     //delete this node
}

void BinarySearchTree::Insert(int num, string data)
{
    //create new node to be inserted
    Node *n = new Node();
    n->setData(num, data);
    n->setLeft(NULL);
    n->setRight(NULL);


    if(this->root == NULL)      //if root is null, simply add at root
        root = n;

    else
        InsertHelper(root,n);   //call helper to insert
}

void BinarySearchTree::InsertHelper(Node* current, Node* newnode)
{
    if(current == NULL)
        return;

    //node should be inserted at right subtree
    if(current->getNumber() <= newnode->getNumber()){

        //if no node at right
        if(current->getRight() == NULL )
            current->setRight(newnode);     //add at right node

        else
            InsertHelper(current->getRight(), newnode);     //insert in right subtree
    }
    else{

        if(current->getLeft() == NULL){         //if no node at left
            current->setLeft(newnode);          //add at left
        }else{
            InsertHelper(current->getLeft(), newnode);      //insert in left subtree
        }
    }
}




void BinarySearchTree::printBTbylevel2()
{
	///std::cout << "in printTree() " << "<br />";
	if (!root) return;
	queue<Node*> cur_level;
	queue<int> level;
	cur_level.push(root);
	int plev = 1;
	int lr;
	level.push(plev);
	///std::cout << "in printTree() right before while loop starts" << "<br />";
	std::cout << "<br /><br />Level: 1---------------------------------------------------";
	while (!cur_level.empty()) {
	///	std::cout << "in while loop " << "<br />";
		//check the level first,if moved to next level, print a enter
		int clev = level.front();
		level.pop();
		if (plev < clev) {
			std::cout << "<br />" << "Level: " << clev;
			if (clev == 2) { std::cout << "---------------------------------------------"; }
			if (clev == 3) { std::cout << "----------------------------------"; }
			if (clev == 4) { std::cout << "---------------------"; }
			if (clev == 5) { std::cout << "---------"; }
			if (clev == 6) { std::cout << "-"; }
			plev = clev;
		}
		//std::cout << "in while loop after if 1 " << "<br />";
		//pop the node
		Node *p = cur_level.front();
		///std::cout << "after Node* p";
		std::cout << p->getData() << "-------";
		///std::cout << "after p->getData()";
		///printf("%d\t", p->getData());
		cur_level.pop();
		///std::cout << "after cur_level.pop()";
		//push its children
		if (p->getLeft()) {
			cur_level.push(p->getLeft());
			level.push(clev + 1); //update children level
		}
		///std::cout << "in while loop after if 2 " << "<br />";
		if (p->getRight()) {
			cur_level.push(p->getRight());
			level.push(clev + 1);
		}
		///std::cout << "in while loop after if 3 end  " << "<br />";
	}
	std::cout << "<br />";
	///std::cout << "in printTree() out of while loop :) " << "<br />";
	///printf("\n");
}



//POST ORDER
void BinarySearchTree::postorderPrint(){
    cout<< "POST ORDER: " << "<br />" << endl;
    postorderPrintHelper(root);
}
void BinarySearchTree::postorderPrintHelper(Node *current){
     if(current == NULL)     //stop if NULL
        return;

    postorderPrintHelper(current->getLeft());
    postorderPrintHelper(current->getRight());
    cout << "<tr>";
    cout << "<td>" << current->getNumber() << "</td>" << "<td>" << current-> getName() << "</td>";
    cout << "</tr>";
}


//PRE ORDER
void BinarySearchTree::preorderPrint(){
    cout<< "PRE ORDER: " << "<br />" << endl;
    preorderPrintHelper(root);
}
void BinarySearchTree::preorderPrintHelper(Node *current){
     if(current == NULL)     //stop if NULL
        return;
    cout << "<tr>";
    cout << "<td>" << current->getNumber() << "</td>" << "<td>" << current-> getName() << "</td>";
    cout << "</tr>";
    preorderPrintHelper(current->getLeft());
    preorderPrintHelper(current->getRight());
}


//IN ORDER
void BinarySearchTree::inorderPrint()
{
    cout<< "IN ORDER: " << "<br />" << endl;
    inorderPrintHelper(root);
}

void BinarySearchTree::inorderPrintHelper(Node *current)
{
    if(current == NULL)     //stop if NULL
        return; 
    inorderPrintHelper(current->getLeft());        //print left tree
    cout << "<tr>";
    cout << "<td>" << current->getNumber() << "</td>" << "<td>" << current-> getName() << "</td>";
    cout << "</tr>";
    inorderPrintHelper(current->getRight());       //print right tree
}


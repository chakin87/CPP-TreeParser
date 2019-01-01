#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H

#include <iostream>

#define NULLNODE static_cast<Node<T>*>(0)
template <class T>
struct Node
{
	T data;
	Node<T>* right;
	Node<T>* left;
};

template <class T>
class BinarySearchTree
{
public:
	BinarySearchTree()
	{
		m_Root = NULLNODE;
	}
	~BinarySearchTree() { erase(); }
	BinarySearchTree(const BinarySearchTree& other);
	BinarySearchTree& operator=(const BinarySearchTree& other);
	void print();
	void inorder();
	void preorder();
	void postorder();
	bool empty()
	{
		return m_Root == NULLNODE;
	}
	void insert(T data);
	int nodeCount()
	{
		return nodeCountHelper(m_Root);
	}
	int height()
	{
		return heightHelper(m_Root);
	}
	bool find(T lookingFor) { return findHelper(m_Root, lookingFor); }
	void erase() { eraseHelper(m_Root); m_Root = NULLNODE; }

private:
	void insertHelper(Node<T>* &n, T data);
	void printHelper(Node<T>* n);
	int nodeCountHelper(Node<T>* n);
	int heightHelper(Node<T>* n);
	bool findHelper(Node<T>* n, T lookingFor);
	void preorderHelper(Node<T>* n);
	void inorderHelper(Node<T>* n);
	void postorderHelper(Node<T>* n);
	Node<T>* copyHelper(Node<T>* n);
	void eraseHelper(Node<T>* n);

	Node<T>* m_Root;
};

template <class T>
BinarySearchTree<T>& BinarySearchTree<T>::operator=(const BinarySearchTree& rhs)
{
	if (this == &rhs) return *this; // handle self assignment
	//assignment operator
	return *this;


	/// erase the current tree
	erase();

	/// copy the other over the current using copyHelper()
	m_Root = copyHelper(rhs->m_Root);
}

template <class T>
void BinarySearchTree<T>::print()
{
	if (empty())
	{
		std::cout << "Empty Tree" << std::endl;
	}
	else
	{
		printHelper(m_Root);
	}

}

template <class T>
void BinarySearchTree<T>::insertHelper(Node<T>* &n, T data)
{
	/// insert 'data' into a tree pointed to by 'n'

	/// if n is null, it goes here
	if (n == NULLNODE)
	{
		n = new Node<T>;
		n->data = data;
		n->left = NULLNODE;
		n->right = NULLNODE;
		return;
	}
	/// n is not null, so we can check left & right
	if (data < n->data)
	{
		insertHelper(n->left, data);
	}
	else
	{
		insertHelper(n->right, data);
	}

}

template <class T>
void BinarySearchTree<T>::insert(T data)
{
	insertHelper(m_Root, data);
}

template <class T>
void BinarySearchTree<T>::printHelper(Node<T>* n)
{
	if (n == NULLNODE) return;

	/// in order traversal of the tree
	printHelper(n->left);
	std::cout << n->data << " ";
	printHelper(n->right);
}

template <class T>
int BinarySearchTree<T>::nodeCountHelper(Node<T>* n)
{
	if (!n) return 0; /// if n is NULLNODE return 0 node
	return nodeCountHelper(n->left) + nodeCountHelper(n->right) + 1;
}
template <class T>

int BinarySearchTree<T>::heightHelper(Node<T>* n)
{
	if (!n) return 0; /// if n is NULLNODE return 0 height

	int hleft = heightHelper(n->left);
	int hright = heightHelper(n->right);
	/*
	std::cout << "Height visiting: " << n->data
			  << "Left height= " << hleft
			  << "Right height= " << hright
			  << "Returning " << ((hleft<hright)?(hleft+1):(hright+1))
			  << std::endl;
	*/
	return (hleft > hright) ? (hleft + 1) : (hright + 1);
}

template <class T>
bool BinarySearchTree<T>::findHelper(Node<T>* n, T lookingFor)
{
	if (!n) return 0; /// if n is NULLNODE return not found
	if (n->data < lookingFor) return findHelper(n->right, lookingFor);
	else if (n->data > lookingFor) return findHelper(n->left, lookingFor);
	else return 1; /// found, return true
}

template <class T>
void BinarySearchTree<T>::preorder()
{
	if (empty())
	{
		std::cout << "Empty Tree" << std::endl;
	}
	else
	{
		preorderHelper(m_Root);
	}

}

template <class T>
void BinarySearchTree<T>::postorder()
{
	if (empty())
	{
		std::cout << "Empty Tree" << std::endl;
	}
	else
	{
		postorderHelper(m_Root);
	}

}

template <class T>
void BinarySearchTree<T>::inorder()
{
	if (empty())
	{
		std::cout << "Empty Tree" << std::endl;
	}
	else
	{
		inorderHelper(m_Root);
	}

}

template <class T>
void BinarySearchTree<T>::inorderHelper(Node<T>* n)
{
	if (n == NULLNODE) return;

	/// in order traversal of the tree
	inorderHelper(n->left);
	std::cout << n->data << " ";
	inorderHelper(n->right);
}

template <class T>
void BinarySearchTree<T>::preorderHelper(Node<T>* n)
{
	if (n == NULLNODE) return;

	/// pre order traversal of the tree
	std::cout << n->data << " ";
	preorderHelper(n->left);
	preorderHelper(n->right);
}

template <class T>
void BinarySearchTree<T>::postorderHelper(Node<T>* n)
{
	if (n == NULLNODE) return;

	/// post order traversal of the tree
	postorderHelper(n->left);
	postorderHelper(n->right);
	std::cout << n->data << " ";
}

template <class T>
BinarySearchTree<T>::BinarySearchTree(const BinarySearchTree<T>& other)
{
	m_Root = copyHelper(other.m_Root);
}

template <class T>
Node<T>* BinarySearchTree<T>::copyHelper(Node<T>* oldNode)
{
	if (oldNode == NULLNODE) return NULLNODE;
	/// otherwise build a new node
	Node<T>* newNode = new Node<T>();
	newNode->data = oldNode->data;
	newNode->left = copyHelper(oldNode->left);
	newNode->right = copyHelper(oldNode->right);
	return newNode;

}

template <class T>
void BinarySearchTree<T>::eraseHelper(Node<T>* n)
{
	if (!n) return;
	eraseHelper(n->left);
	eraseHelper(n->right);
	delete n;
	return;
}

#endif // BINARYSEARCHTREE_H
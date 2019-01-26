#pragma once

#include <iostream>

using namespace std;

template <class Type>
struct Node
{
    int key;
    int height;
    Type data;
    Node<Type> *parent, *left, *right;
};

template <class Type>
class Tree
{
private:
    //Node<Type> *root;
    //Node<Type> *_SearchNode(int key);

public:
    Node<Type> *root;//!!!private

    Tree();
    Tree(int key, Type data);
    ~Tree();

    void AddNode(int key, Type data);
    Node<Type> DeleteNode(int key);
    //Node<Type> SearchNode(int key);
    void PreOrderTravers();
    void InOrderTravers();
    void PostOrderTravers();
    Node<Type> *_SearchNode(int key);//!!!private
    bool IsAVL();
    void Foo();
    int GetHeight(Node<Type> *tree);//!!!private
};

template <class Type>
Tree<Type>::Tree()
{
    root = NULL;
}

template <class Type>
Tree<Type>::Tree(int key, Type data)
{
    root = new Node<Type>;

    root->key    = key;
    root->data   = data;
    root->parent = NULL;
    root->left   = NULL;
    root->right  = NULL;
    root->height = 1;
}

template <class Type>
Tree<Type>::~Tree()
{
    if (root)
    {
        //дл€ освобожени€ пам€ти из под узлов будет использоватс€ один из методов обхода дерева, например, пр€мой
    }
}

template <class Type>
void Tree<Type>::AddNode(int key, Type data)
{
    static Node<Type> *current = root;
    static Node<Type> *parent  = NULL;
    static int height = 1;

    if(!current)
    {
        //cout << "Create new node: key = " << key << "\n" << endl;
        current = new Node<Type>;

        if(!root)
            root = current;

        if(parent)
        {
            if(key < parent->key)
                parent->left = current;
            if(key > parent->key)
                parent->right = current;
        }

        current->key    = key;
        current->data   = data;
        current->parent = parent;
        current->left   = NULL;
        current->right  = NULL;
        current->height = height;
    }
    else
    {
        parent = current;
        height++;

        if (key < current->key)
        {
            //cout << "go left from: key = " << current->key << endl;
            current = current->left;
            AddNode(key, data);
        }
        else
        {
            //cout << "go right from: key = " << current->key << endl;
            current = current->right;
            AddNode(key, data);
        }
    }

    current = root;
    parent  = NULL;
    height  = 1;
}

template <class Type>
Node<Type> Tree<Type>::DeleteNode(int key)//Ќеобходимо возращать значение
{
    Node<Type> *del   = _SearchNode(key);
    Node<Type> *child = NULL;

    if(del->left && del->right)
    {
        //cout << "left && right" << endl;
        child = del->right;

        while(child->left)
            child = child->left;

        del->key  = child->key;
        del->data = child->data;

        child->parent->left = NULL;

        delete child;
    }
    else if(del->left || del->right)
    {
        //cout << "left || right" << endl;
        del->left ? child = del->left : child = del->right;

        del->key   = child->key;
        del->data  = child->data;
        del->left  = child->left;
        del->right = child->right;

        delete child;
    }
    else if(!del->left && !del->right)
    {
        //cout << "!left && !right" << endl;
        if(del->parent->left)
            if(del->parent->left->key == key)
                del->parent->left = NULL;
                //cout << "del left" << endl;
        if(del->parent->right)
            if(del->parent->right->key == key)
                del->parent->right = NULL;
                //cout << "del right" << endl;
        delete del;
    }
}

template <class Type>
Node<Type> *Tree<Type>::_SearchNode(int key)
{
    static Node<Type> *current = root;
    static Node<Type> *res = NULL;

    if (!current)
    {
        current = root;
        res = NULL;
        return NULL;
    }

    if (key == current->key)
    {
        res = current;
        current = root;
        return res;
    }
    else if (key < current->key)
    {
        //cout << "go left from: key = " << current->key << endl;
        current = current->left;
        res = _SearchNode(key);
    }
    else if (key > current->key)
    {
        //cout << "go right from: key = " << current->key << endl;
        current = current->right;
        res = _SearchNode(key);
    }
}

template <class Type>
void Tree<Type>::PreOrderTravers()
{
    static Node<Type> *current = root;

    if(current)
    {
        cout << "key = " << current->key << endl;
        cout << "height = " << current->height << endl;

        if(current->left)
        {
            cout << "go left" << endl;
            current = current->left;
            PreOrderTravers();
        }

        if(current->right)
        {
            cout << "go right" << endl;
            current = current->right;
            PreOrderTravers();
        }

        cout << "go back" << endl;
        current = current->parent;
    }

    if(!current) current = root;
}

template <class Type>
void Tree<Type>::InOrderTravers()
{
    static Node<Type> *current = root;

    if(current)
    {
        if(current->left)
        {
            cout << "go left" << endl;
            current = current->left;
            InOrderTravers();
        }

        cout << "key = " << current->key << endl;

        if(current->right)
        {
            cout << "go right" << endl;
            current = current->right;
            InOrderTravers();
        }

        cout << "go parent" << endl;
        current = current->parent;
    }

    if(!current) current = root;
}

template <class Type>
void Tree<Type>::PostOrderTravers()
{
    static Node<Type> *current = root;

    if(current)
    {
        if(current->left)
        {
            cout << "go left" << endl;
            current = current->left;
            PostOrderTravers();
        }

        if(current->right)
        {
            cout << "go right" << endl;
            current = current->right;
            PostOrderTravers();
        }

        cout << "key = " << current->key << endl;
        cout << "go back" << endl;

        current = current->parent;
    }

    if(!current) current = root;
}

template <class Type>
void Tree<Type>::Foo()
{
    Node<Type> *current = root;

    while(current)
    {
        if(current->left)
        {
            cout << "go left" << endl;
            current = current->left;
            continue;
        }

        if(current->right)
        {
            cout << "go right" << endl;
            current = current->right;
            continue;
        }

        cout << "key = " << current->key << endl;
        cout << "go back" << endl;

        current = current->parent;
    }
}

template <class Type>
int Tree<Type>::GetHeight(Node<Type> *tree)
{
    /*static int max_height = 0;

    if(tree)
    {
        if(tree->height > max_height)
            max_height = tree->height;

        GetHeight(tree->left);
        GetHeight(tree->right);
    }

    return max_height;*/

    int max_height = 0;
    int height = 0;

    if(tree)
    {
        max_height = tree->height;

        height = GetHeight(tree->left);
        if(height > max_height)
            max_height = height;

        height = GetHeight(tree->right);
        if(height > max_height)
            max_height = height;
    }

    return max_height;

    /*static Node<Type> *current = NULL;
    static int max_height = 0;

    if(!current)
        current = tree;

    if(current)
    {
        if(current->height > max_height)
            max_height = current->height;

        if(current->left)
        {
            current = current->left;
            GetHeight(NULL);
        }

        if(current->right)
        {
            current = current->right;
            GetHeight(NULL);
        }

        current = current->parent;
    }

    if(!current) current = NULL;//???

    return max_height;*/
}

template <class Type>
bool Tree<Type>::IsAVL()
{
    static int max_left_height  = 0;
    static int max_right_height = 0;
    static Node<Type> *current  = NULL;

    if(!root)
        return false;
    else
    {
        if(root->left)
        {
            current = root->left;

            if(current->height > max_left_height)
                max_left_height = current->height;


        }

        if(root->right)
        {
            current = root->right;

            if(current->height > max_right_height)
                max_right_height = current->height;
        }
    }

    max_left_height  = 0;
    max_right_height = 0;
    current          = 0;


}

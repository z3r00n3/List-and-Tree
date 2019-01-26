#include <iostream>
#include "Tree.h"

using namespace std;

int main()
{
    /*Tree<int> a;
    a.AddNode(5, 10);
    a.AddNode(7, 10);
    a.AddNode(3, 10);
    a.AddNode(8, 10);
    a.AddNode(6, 10);*/

    /*cout << endl;*/


Tree<int> a;
    a.AddNode(5, 10);
    a.AddNode(7, 10);
    a.AddNode(3, 10);
    a.AddNode(8, 10);
    a.AddNode(6, 10);
    a.PreOrderTravers();
    //cout << a.GetHeight(a.root) << endl;

    /*Tree<int> b(10, 22);
    b.AddNode(6, 22);
    b.AddNode(15, 22);
    b.AddNode(9, 22);
    b.AddNode(20, 22);
    b.AddNode(1, 22);
    b.AddNode(19, 22);*/

    /*cout << endl;

    const Node<int> *res = b._SearchNode(6);

    if (res)
    {
        cout << "key:    " << res->key << endl;
        cout << "data:   " << res->data << endl;
        cout << "parent: " << res->parent << endl;
        cout << "left:   " << res->left << endl;
        cout << "right:  " << res->right << endl;
    }
    else
        cout << "NULL" << endl;*/
cout << endl;
Tree<int> c;
    c.AddNode(15, 10);
    c.AddNode(21, 10);
    c.AddNode(9, 10);
    c.AddNode(24, 10);
    c.AddNode(18, 10);
    c.PreOrderTravers();

    cout << endl;
    a.PreOrderTravers();
    cout << endl;
    c.PreOrderTravers();

    //cout << c.GetHeight(c.root) << endl;

 /*   cout << endl;
Tree<int> d;
    d.AddNode(10, 10);
    d.AddNode(14, 10);
    d.AddNode(6, 10);
    d.AddNode(16, 10);
    d.AddNode(12, 10);
    d.PreOrderTravers();*/

    /*b.AddNode(2, 22);
    b.AddNode(13, 22);
    b.AddNode(21, 22);
    b.AddNode(18, 22);
    //b.PreOrderTravers();
    cout << b.GetHeight(b.root) << endl;*/

    //b.DeleteNode(13);
   // b.DeleteNode(1);
   // b.DeleteNode(15);
   // b.DeleteNode(2);

  /*  Node<int> *res = b._SearchNode(1);

    if (res)
    {
        cout << "key:    " << res->key << endl;
        cout << "data:   " << res->data << endl;
        cout << "parent: " << res->parent << endl;
        cout << "left:   " << res->left << endl;
        cout << "right:  " << res->right << endl;
    }
    else
        cout << "NULL" << endl;
//cout << endl;*/
    //b.PostOrderTravers();
    //b.Foo();

    return 0;
}

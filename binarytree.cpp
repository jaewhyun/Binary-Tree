//
//  binarytree.cpp
//  binarytree
//
//  Created by Jae Won Hyun on 12/6/16.
//  Copyright © 2016 Jae Won Hyun. All rights reserved.
//
//  treedisplay, treedisplayroot, findmiddle, addtotree, addroot, findaplace functions are from John Maslanka's binary tree files.
//

#include <iomanip>
#include <iostream>
#include <string>
#include "binarytree.h"
#include "node.h"
using namespace std;

// constructor
tree::tree()
{
    // ask for input
    cout << "Please enter in " << numberofnames << " names: \n";
    string nameinput;
    
    for(int i = 0; i < numberofnames; i++)
    {
        cin >> nameinput;
        
        if(!cin.eof() && cin.good())
        {
            listofnames[i] = nameinput;
        }
    }
    
    // sort the names
    sort();
    
    //for(int i = 0; i < numberofnames; i ++)
    //{
    //    cout << listofnames[i] << " ";
    //
    //}

    cout << "\n";
   
    root = NULL;
}

// add a node to the tree
Node* tree::addtotree(Node* x, string nameinput)
{
    // if you can get space for a new node
    if((x = new (Node)))
    {
        // set name
        x->setName(nameinput);
        // set pointer to right and left child to null
        x->setrightName(NULL);
        x->setleftName(NULL);
        
    }
    
    return x;
}

// combine everything together
void tree::puteverythingtogether()
{
    for(int i = 0; i < numberofnames; i++)
    {
        addroot(binaryarray[i]);
    }
}

// add a root
void tree::addroot(string nameinput)
{
    // if there's nothing at the root
    if(root == NULL)
    {
        root = treelocation = addtotree(treelocation, nameinput);
    }
    // if there is a root already
    else
    {
        treelocation = root;
        treelocation = findaplace(treelocation, nameinput);
    }
}

// find a place in the tree to add the node
Node* tree::findaplace(Node* x, string nameinput)
{
    // get the name at the treelocation
    string currentname;
    currentname = x -> returnName();
    cout << "comparing the values: " << nameinput << " and " << currentname << "\n";

    // if the nameinput is smaller than the last node name, put it on the left side
    if(nameinput <= currentname)
    {
        // if there is a left child already
        if(x -> leftName() != NULL)
        {
            x = findaplace(x -> leftName(), nameinput);
            return x;
        }
        // if there is no left child
        else
        {
            Node* temp = NULL;
            temp = addtotree(temp, nameinput);
            x -> setleftName(temp);
        }
    }
    // if the nameinput is bigger than the last node name, put it on the right side
    else
    {
        // if there is a right child already
        if(x -> rightName() != NULL)
        {
            x = findaplace(x -> rightName(), nameinput);
            return x;
        }
        // if there is no right child yet
        else
        {
            Node* temp = NULL;
            temp = addtotree(temp, nameinput);
            x -> setrightName(temp);
        }
    }
    
    return x;
}

// bubble sort
// cs50
void tree::sort()
{
    int swaps;
    
    do
    {
        swaps = 0;
        
        for(int i = 0; i < numberofnames - 1; i++)
        {
            string temp;
            
            if(listofnames[i] > listofnames[i+1])
            {
                temp = listofnames[i];
                listofnames[i] = listofnames[i+1];
                listofnames[i+1] = temp;
            
                swaps++;
            }
        }
    }
    
    while(swaps != 0);
}

// find middle of the branch algorithm
// from Professor Maslanka's program
void tree::FindMiddle(int x, int y, int level, int number, int round)
{
    int mid;
    
    if (abs(x-y)<2)
    {
        if (x==1)
        {
            binaryarray[index] = listofnames[x - 1];
            cout << level << " " << setw(2) << binaryarray[index] << endl;
            index++;
        }
        if (y==number)
        {
            binaryarray[index] = listofnames[y - 1];
            cout << level << " " << setw(2) << binaryarray[index] << endl;
            index++;
        }
        
        return;
    }
    if ((y+x)%2)
    {
        mid=(x+y+round)/2;
        
        binaryarray[index] = listofnames[mid-1];
        
        cout << level << " " << setw(2) << binaryarray[index] << endl;
        
        index++;
    }
    else
    {
        mid = (x+y)/2;
        
        binaryarray[index] = listofnames[mid-1];
        
        cout << level << " " << setw(2) << binaryarray[index] << endl;
        
        index++;
    }
    
    FindMiddle(x,mid,(level+1),number,-1); // round down left
    FindMiddle(mid,y,(level+1),number,1);  // round up right
    return;
}

// from Professor Maslanka's program
void tree::treedisplayroot()
{
    treedisplay(root, 0);
}

// from Professor Maslanka's program
void tree::treedisplay(Node* ref, int depth)
{
    // from Main & Savitch page 506
    cout << setw(4*depth) << ""; // indentation
    if (ref == NULL)
    {
        // reached a NULL reference in an interior node
        cout << "[NULL]" << endl;
    }
    else if (ref->leftName() == NULL && ref->rightName() == NULL)
    {
        // a leaf
        cout << "Value " << ref->returnName() << " at Ref " << ref;
        cout << " [leaf]" << endl;
    }
    else
    {
        // a nonleaf - interior node
        if ( depth == 0 )
            cout << "       Root ";
        cout << "Value " << ref->returnName() << " at Ref " << ref << endl;
        cout << "Left Child  " << depth+1;
        treedisplay(ref->leftName(), depth + 1);
        cout << "Right Child " << depth+1;
        treedisplay(ref->rightName(), depth + 1);
    }
}

//
//  binarytree.h
//  binarytree
//
//  Created by Jae Won Hyun on 12/6/16.
//  Copyright © 2016 Jae Won Hyun. All rights reserved.
//

#ifndef binarytree_h
#define binarytree_h

#include "Node.h"
#include <stdio.h>
#include <array>
#include <string>

class tree{
public:
    tree();
    static const size_t numberofnames = 9;
    void sort();
    void puteverythingtogether();
    void addroot(string);
    void treedisplay(Node*, int);
    void treedisplayroot();
    Node* addtotree(Node*, string);
    Node* findaplace(Node*, string);
    void FindMiddle(int, int, int, int, int);
    void copyarray(string*);
    
private:
    Node* treelocation;
    int index = 0;
    Node* root;
    
    array<string, numberofnames> listofnames;
    array<string, numberofnames> binaryarray;
};

#endif /* binarytree_h */

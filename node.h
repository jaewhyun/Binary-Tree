//
//  node.h
//  binarytree
//
//  Created by Jae Won Hyun on 12/6/16.
//  Copyright © 2016 Jae Won Hyun. All rights reserved.
//

#ifndef node_h
#define node_h

#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;

class Node{
public:
    Node();
    void setleftName(Node*);
    void setrightName(Node*);
    void setName(string);
    string returnName();
    Node* rightName();
    Node* leftName();
private:
    Node* left;
    Node* right;
    string name;
};

#endif /* node_h */

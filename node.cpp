//
//  node.cpp
//  binarytree
//
//  Created by Jae Won Hyun on 12/6/16.
//  Copyright © 2016 Jae Won Hyun. All rights reserved.
//

#include "node.h"

// node constructor
Node::Node()
{
    name = " ";
    right = NULL;
    left = NULL;
    
}

// set left child
void Node::setleftName(Node* goleft)
{
    left = goleft;
}

// set right child
void Node::setrightName(Node * goright)
{
    right = goright;
}

// set name
void Node::setName(string nameinput)
{
    name = nameinput;
}

// get name
string Node::returnName()
{
    return name;
}

// get right child
Node* Node::rightName()
{
    return right;
}

// get left child
Node* Node::leftName()
{
    return left;
}

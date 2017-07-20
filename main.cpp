//
//  main.cpp
//  binarytree
//
//  Created by Jae Won Hyun on 12/6/16.
//  Copyright © 2016 Jae Won Hyun. All rights reserved.
//

#include "binarytree.h"
#include <iostream>
#include <array>
#include <string>
using namespace std;

int main()
{
    tree A;
    
    int level = 0;
    
    A.FindMiddle(1, 9, (level+1), 9, 1);
    
    A.puteverythingtogether();
    
    A.treedisplayroot();
}

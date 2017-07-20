# Binary-Tree
BU MET CS341 Homework 5

When building a binary tree, a tree which is as close to perfectly balanced as possible is the most efficient tree possible for a given input data set.

Given a data set which includes the unique first names of the members of our class, we need to construct a binary tree which is as balanced as possible. The unique given (i.e. first) names of the people in our class are:  Sergio, Thomas, Kyle, Jae, Nico, Ben, Frank, Youcun and John.  There are 9 names in this list.  So, it is six names short of the count which is required to produce a perfectly balanced binary tree structure containing four levels in addition to the root node.  Nevertheless, we can create a tree which contains these names and which is as balanced as possible.  To assist your thinking regarding the balancing, I have attached the program FindMiddleRB.cpp which demonstrates a binary balancing algorithm named FindMiddle, which is very similar to a binary search.  (Please be aware that I am not asking you to use the AVL height-balancing algorithm to solve this problem.)

Here is an outline of a possible solution:
(1)	Enter the unsorted list of names one at a time into a dynamic array, then sort this list in the array.  Be sure to retain the count of array elements. 
(2)	Use the count of array elements and the FindMiddle algorithm to rearrange the sorted array into a second array which contains the middle element in the first position, the elements in the first quarter and third quarter positions in the second and third positions, the elements in the first, third, fifth and seven-eighths positions into the fourth through seventh positions, etc.
(3)	Move each of the elements of the second array in succession into a binary tree structure.
(4)	Display the balanced tree using one of the available binary tree display algorithms.

Historical Note: The FindMiddle algorithm contains the first student enhancement to one of my in-class programs.  As explained in the header comments, the enhancement was done by student Ryan Balter in my CS341 course in the Fall semester of 2002, thereby establishing itself as the primordial student enhancement to one of my in-class demonstration programs.

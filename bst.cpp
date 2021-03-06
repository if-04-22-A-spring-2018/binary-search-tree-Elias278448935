/*-----------------------------------------------------------------------------
 *				HTBLA-Leonding / Class: <your class name here>
 *-----------------------------------------------------------------------------
 * Exercise Number: #exercise_number#
 * File:			bst.cpp
 * Author(s):		Peter Bauer
 * Due Date:		May 31, 2017
 *-----------------------------------------------------------------------------
 * Description:
 * <your description here>
 *-----------------------------------------------------------------------------
*/
#include <stdio.h>
#include "bst.h"
#include <stdlib.h>
#include "general.h"
#define MAX 50

struct Node{
  int data;
   Bst left_subtree;
   Bst right_subtree;
};

Bst new_bst(){
   Bst _head = 0;
   return _head;
}
void delete_bst(Bst bst){
  if(bst == 0)return;
  delete_bst(bst->left_subtree);
  delete_bst(bst->right_subtree);
  sfree(bst);
}

int get_depth(Bst bst)
{
  if (bst == 0)
  {
     return 0;
  }
  else if (bst->left_subtree == 0 && bst->right_subtree== 0 && bst!= 0)
  {
     return 1;
  }
  int depth_left = get_depth(bst->left_subtree) +1;
  int depth_right = get_depth(bst->right_subtree) +1;
  if (depth_right > depth_left)
  {
     return depth_right;
  }
  else return depth_left;
}

void add(Bst* bst, int value){
  Bst &aka = *bst;
  if(aka == 0){
    aka = (Bst)malloc(sizeof(struct Node)); aka->data = value;
    aka->left_subtree =0;
    aka->right_subtree =0;
  }
  else if(value <= aka->data){
    if(aka->left_subtree == 0){
      Bst newBst = (Bst)malloc(sizeof(struct Node));
      aka->left_subtree = newBst;
            newBst->data = value;
      newBst->left_subtree = 0;
      newBst->right_subtree = 0;
    }
    else{
      add(&aka->left_subtree, value);
    }
  }
  else{
    if(aka->right_subtree ==0){
      Bst newBst = (Bst)malloc(sizeof(struct Node));
      aka->right_subtree = newBst;
        newBst->data = value;
      newBst->left_subtree = 0;
      newBst ->right_subtree = 0;
    }
    else{
      add(&aka->right_subtree,value);
    }
  }
}

int root_value(Bst bst)
{
  if(bst == 0)
  {
    return 0;
  }
  return bst->data;
}

Bst left_subtree(Bst root){
  return root->left_subtree;
}

Bst right_subtree(Bst root){
  return root->right_subtree;
}

int traverse_pre_order(Bst bst, int *elements, int start){
    if(bst == 0)return 0;
    int count = 0;
    elements[start] = bst->data;
    count += traverse_pre_order(bst->left_subtree, elements, start+1);
    count+= traverse_pre_order(bst->right_subtree, elements, start+count+1);
    return count+1;
}

int traverse_in_order(Bst bst, int *elements, int start){
    if(bst == 0)return 0;
    int count = 0;
    count += traverse_in_order(bst->left_subtree, elements, start);
    elements[start+count] = bst->data;
    count+= traverse_in_order(bst->right_subtree, elements, start+count+1);
    return count+1;
}

int traverse_post_order(Bst bst, int *elements, int start){
    if(bst == 0)return 0;
    int count = 0;
    count += traverse_post_order(bst->left_subtree, elements, start);
    count += traverse_post_order(bst->right_subtree, elements, start+count);
    elements[start+count] = bst->data;
    return count+1;
}

bool are_equal(Bst bst1, Bst bst2)
{
  if(bst1 == bst2)
  {
    return true;
  }
  if(bst1 != 0 && bst2 != 0)
  {
    int arr1[MAX];
    int length = traverse_in_order(bst1 ,arr1, 0 );
    int arr2[MAX];
    int length2 = traverse_in_order(bst2 ,arr2, 0 );
    if(length == length2)
    {
      bool mau  =true;
      for (int i = 0; i < length; i++)
      {
         if(arr1[i]!= arr2[i]) mau = false;
      }
      return mau;
    }
  }
  return false;

}

void most_left_longest_branch(Bst bst, Bst* branch)
{
  if (bst != 0)
  {
    add(branch, bst->element);
    if (get_depth(bst->left) >= get_depth(bst->right))
    {
      most_left_longest_branch(bst->left,branch);
    }
    else  most_left_longest_branch(bst->right,branch);
  }
}

int get_number_of_subtrees(Bst bst)
{
    if (bst == 0)
    {
      return -1;
    }
   int number_of_subtrees = get_number_of_subtrees(bst->left)+1 + get_number_of_subtrees(bst->right)+1;
   return number_of_subtrees;
}

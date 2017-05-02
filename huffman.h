#ifndef PA15_H
#define PA15_H		 
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#define ASCII_SIZE 256

typedef struct TreeNode {
   int label;
   long count;
   struct TreeNode *left;
   struct TreeNode *right;
} TreeNode;

typedef struct ListNode {
   TreeNode *ptr;
   struct ListNode *next;
} ListNode;

typedef struct NodeHead{
	ListNode * head;
}NodeHead;

NodeHead * create(long * ascii);

TreeNode * pop(NodeHead * thead);

void add(ListNode * list, NodeHead * thead);

void comb(TreeNode * tree1, TreeNode * tree2, NodeHead * thead);

void freeNodes(TreeNode * node);

void freeThead(NodeHead * thead);

#endif

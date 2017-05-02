#include "huffman.h"

NodeHead * create(long * asciiCount){
	NodeHead * thead = malloc(sizeof(NodeHead));
	ListNode * list;
	int x;

	thead -> head = NULL;
	for(x = 0; x < ASCII_SIZE; ++x){
		if(asciiCount[x] != 0){
			list = malloc(sizeof(ListNode));
			list-> ptr = malloc(sizeof(TreeNode));
			list -> ptr -> left = NULL;
			list -> ptr -> right = NULL;
			list -> ptr -> count = asciiCount[x];
			list -> ptr -> label = x;
			add(list, thead);
		}
	}
	return thead;
}

TreeNode * pop(NodeHead * thead){
	if((thead -> head) == NULL){
		return NULL;
	}

	ListNode * list;
	TreeNode * node;

	list = thead -> head;
	thead -> head = list -> next;
	node = list -> ptr;
	
	free(list);

	return node;
}

void add(ListNode * list, NodeHead * thead){
	if(thead -> head == NULL){
		thead -> head = list;
		list -> next = NULL;
		return;
	}

	ListNode * back;
	ListNode * forw;

	back = NULL;
	forw = thead ->head;

	while(forw != NULL){
		if (forw -> ptr -> count > list->ptr->count){
			if(back == NULL){
				thead->head = list;
			}
			else{
				back -> next = list;
			}	
			list -> next = forw;
			return;
		}
		if((forw->ptr->count < list->ptr->count) || ((forw->ptr->label != -1) && (forw->ptr->label < list->ptr->label)) || ((list->ptr-> label == -1) && (forw->ptr ->count == list->ptr->count))){
			back = forw;
			forw = forw-> next;
		}else{
			break;
		}
	}

	back->next = list;
	list->next = forw;

	return;
}

void comb(TreeNode * tree1, TreeNode * tree2, NodeHead * thead){
	ListNode * list = malloc(sizeof(ListNode));
	list->ptr = malloc(sizeof(TreeNode));
	
	list->ptr->left = tree1;
	list->ptr->right = tree2;
	list->ptr->count = tree1->count + tree2->count;
	list->ptr->label = -1;
			
	add(list, thead);
	return;
}

void freeNodes(TreeNode * node){
	if(node == NULL){
		return;
	}

	freeNodes(node ->left);
	freeNodes(node -> right);
	free(node);
}

void freeThead(NodeHead * thead){
	ListNode * temp = thead -> head;
	ListNode * forw;

	while(temp != NULL){
		forw = temp->next;
		freeNodes(temp->ptr);
		free(temp);
		temp = forw;
	}
	free(thead);
	return;
}












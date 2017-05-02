
#include "funcs.h"

TreeNode * huffFunc(NodeHead * thead){
	TreeNode * tree1;
	TreeNode * tree2;

	while((thead->head->next) != NULL){
		tree1 = pop(thead);
		tree2 = pop(thead);

		comb(tree1, tree2, thead);
	}

	tree1 = pop(thead);
	return tree1;
}

void headReader(int * val, TreeNode * node, FILE * file, uint8_t * num){
	if(node == NULL){
		return;
	}

	headPrint(val, node, file, num);
	headReader(val, node->left, file, num);
	headReader(val, node->right, file, num);
	return;
}

void huffPrint(int inc, TreeNode * node, FILE * file, char * root){
	if(node == NULL){
		return;
	}

	root[inc] = '0';
	huffPrint((inc + 1), node -> left, file, root);
	
	root[inc] = '1';
	huffPrint((inc + 1), node -> right, file, root);

	if(node -> left == NULL){
		root[inc] = '\0';
		fprintf(file, "%c:%s\n", node -> label, root);
		return;
	}
	return;
}

void headPrint(int * val, TreeNode * node, FILE * file, uint8_t * num){
	int x;
	char let;

	if(node -> left != NULL){
		*val -= 1;
	}else{
		*val -= 1;
		*num += (int)(pow(2, (*val)));
	
		chck(val, num, file);
		
		let = node -> label;

		for(x = 0; x < 8; x++){
			if((128 & let) == 128){
				*num += (int)(pow(2, (*val)));
			}
			let <<= 1;
			*val -= 1;
			chck(val, num, file);
		}
	}
	chck(val, num, file);
	return;
}


void finPrint(FILE * file, NodeHead * thead){
	ListNode * list = thead -> head;

	while(list != NULL){
		fprintf(file, "%c:%ld\n", ((list -> ptr) -> label), ((list -> ptr) -> count));
		list = list -> next;
	}
	return;
}

void chck(int * val, uint8_t * num, FILE * file){
	if(*val < 0){
		fwrite(num, 1, 1, file);	
		*num = 0;
		*val = 7;
	}
	return;
}




#include <stdint.h>
#include <math.h>
#include "huffman.h"

TreeNode * huffFunc(NodeHead *thead);

void headReader(int * val, TreeNode * node, FILE * file, uint8_t * num);

void huffPrint(int inc, TreeNode * node, FILE * file, char * root);

void headPrint(int * val, TreeNode * node, FILE * file, uint8_t * num);

void finPrint(FILE * file, NodeHead * thead);

void chck(int *val, uint8_t *num, FILE * file);


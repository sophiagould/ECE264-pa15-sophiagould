#include <stdio.h>
#include <stdlib.h>
#include "funcs.h"

/* count the occurrences in a file */

long *countLetters(FILE *fp)
{
   long *asciiCount = (long *)malloc(sizeof(long)*ASCII_SIZE);
   if (asciiCount == NULL) {
      return NULL;
   }
   int ch;
   for (ch = 0; ch < ASCII_SIZE; ch++) {
      asciiCount[ch] = 0;
   }
   fseek(fp, 0, SEEK_SET);
   while ((ch = fgetc(fp)) != EOF) {
      asciiCount[ch] += 1;
   }
   return asciiCount;
}

int main(int argc, char **argv)
{
   if (argc != 5) {
    printf("Not enough arguments");
    return EXIT_FAILURE;
   }
   FILE * inFile = fopen(argv[1], "r");
   if (inFile == NULL) {
      fprintf(stderr, "can't open the input file.  Quit.\n");
      return EXIT_FAILURE;
   }

   /* read and count the occurrences of characters */
   long *asciiCount = countLetters(inFile);
   fclose(inFile);

   if (asciiCount == NULL) {
      fprintf(stderr, "cannot allocate memory to count the characters in input file.  Quit.\n");
      return EXIT_FAILURE;
   }
 
   // Your code should go here

   	NodeHead * thead = create(asciiCount);
   	free(asciiCount);

   	FILE * file = fopen(argv[2], "w");
  	finPrint(file, thead);
   	fclose(file);

	TreeNode * node = huffFunc(thead);
	freeThead(thead);
	
	file = fopen(argv[3], "w");
	char * root = malloc(sizeof(char) * 9);
	huffPrint(0, node, file, root);
	free(root);
	fclose(file);

	file = fopen(argv[4], "w");
	int * val = malloc(sizeof(int));
	uint8_t * num = malloc(sizeof(uint8_t));
	*val = 7;
	*num = 0;

	headReader(val, node, file, num);
	if(*val != 7){
		while(*val >= 0){
			*val -= 1;
		}
		fwrite(num, 1, 1, file);
	}
	free(val);
	free(num);
	freeNodes(node);

	fclose(file);
	return EXIT_SUCCESS;
}

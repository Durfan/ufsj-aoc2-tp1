#include "main.h"

typedef enum {direto,conjunto,full} block_t;
typedef enum {LRU,LFU,FIFO} psubs_t;

typedef struct config {
	uint8_t size;	// 16, 32, 64, 128, 256 e 512 words
	uint8_t blocks;	// 1, 2, 4, 8, 16 e 32 words por bloco
	block_t map;	// direto, associativo por conjunto e totalmente associativo
	uint8_t assoc;	// por conjunto de 2 vias, 4 vias e 8 vias
	psubs_t polS;	// LRU, LFU e FIFO
	bool polW;		// write-through e write-back
} config_t;

config_t config = {16,1,0,0,2,0};

bool isPowerTwo(int x) {
	return(x & (x-1));
}

int main(void) {

	cache_t cache[16];
	initCache(cache,16);

	system("clear");

	getMem();
	//ptrMem();
	
	//quicksort(memory,0,memSize);
	//selection(cache,memory);
	bubbleSrt(cache);

	ptrMem();

	printf("\n\n Memory SIZE = %lu bytes\n", sizeof(memory));
	printf("  Cache SIZE = %lu bytes\n\n", sizeof(cache[0].linha[0])*16);

	return 0;
}
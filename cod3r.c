#include <stdio.h>

#define MAX_FILE_SIZE (1024*1024*4)

int main( int argc, char *argv[] ) {

	int bcode = argv[2];

	if( argc == 3 ) {
		printf("The arguments supplied are %s and %s\n", argv[1], argv[2]);
		
		FILE *fptr;
		char data[MAX_FILE_SIZE];
		
		fptr = fopen(argv[1], "rb");
		
		int i = 0;
		while (!feof(fptr)) {
			data[i++] = fgetc(fptr);
		}
		
		fclose(fptr);
		
		fptr = fopen(argv[1], "wb");
		
		for(int j = 0;j < i-1;j++)
			fputc((data[j] ^ bcode), fptr);
		fclose(fptr);
		
	}
	else if( argc > 3 ) {
		printf("Too many arguments supplied.\n");
	}
	else {
		printf("Two argument expected.\n");
	}
	
	return 0;
}

#include <stdio.h>
#include <string.h> 

/* Prints bits using printf */
void printBits(unsigned char n);

/* Writes bits to a file */
void printBitsToFile(FILE *file, unsigned char n);

int main()
{
    /* Writing to a file */
	FILE *file = fopen("file.txt", "w");
	short int count = 0;

	for(count = 0x01; count <= 0xFF; count++) {
		printBitsToFile(file, count);
		fprintf(file, "\n");
	}

	fclose(file);
    
    /* Printing to printf */
    for(count = 0x01; count <= 0xFF; count++) {
        printBits(count);
        printf("\n");
    }

	return 0;
}

/* Print n as a binary number */
void printBitsToFile(FILE *file, unsigned char n)
{
	unsigned char i;
	i = 1<<(sizeof(n) * 8 - 1);

	while (i > 0) {
		if (n & i)
			fprintf(file, "1");
		else
			fprintf(file, "0");
		i >>= 1;
	}
}

/* Print n as a binary number */
void printBits(unsigned char n)
{
	unsigned char i;
	i = 1<<(sizeof(n) * 8 - 1);

	while (i > 0) {
		if (n & i)
			printf("1");
		else
			printf("0");
		i >>= 1;
	}
}

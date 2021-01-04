#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <assert.h>
#include <ctype.h>
#include <string.h>
#include "sort.h"


int compare (const void * a, const void *b){
		return ( *(unsigned int*)a - *(unsigned int*)b );
}

void
usage(char *prog) 
{
    printf("Usage: %s <inFile> <outFile>\n", prog);
    exit(1);
}


int main(int argc, char *argv[])
{
		// arguments
		char *inFile;
		char *outFile;

		if(argc == 3)
		{      
			inFile = strdup(argv[1]);
			outFile = strdup(argv[2]);
		}
		else {
			//printf("An error has occurred\n");	
			usage(argv[0]);
                        exit(1);
		}
		
		rec_t r;
		
		//Get the file size
		FILE* fp = fopen(argv[1], "r"); 
		if (fp == NULL || fp < 0) { 
			printf("Error: Cannot open file %s\n",argv[1]); 
			exit(1); 
		} 
               
                // program assumes a 4-byte key in a 100-byte record
                assert(sizeof(rec_t) == 100);


		fseek(fp, 0L, SEEK_END); 
		// calculating the size of the file 
		int size = ftell(fp); 
		int count = size/sizeof(rec_t);
//		printf("%d\n",count);
		fclose(fp);	
		
		//Array to store the key
		unsigned int *sorted; 
		sorted = (unsigned int*)malloc(count * sizeof(unsigned int)); 
//		unsigned int sorted[count]; 
		int i = 0;
		
		//Array to store the data 
		rec_t *data;
		data = (rec_t*)malloc(size * sizeof(rec_t)); 
//		rec_t data[count];
		
		
		//Open the file 
		int fileRead = open(inFile, O_RDONLY);
		if (fileRead < 0) {
                       // printf("Error: Cannot open file %s\n",argv[1]);
			printf("An error has occurred\n");		
			exit(1);
		}
		
		for (i = 0; i < count; i++){
				int rc;
				rc = read(fileRead, &r, sizeof(rec_t));
				
				if (rc < 0) {
					printf("%s","An error has occurred\n");
					exit(1);
				}
                                //Store the key value to array sorted for sorting 
				sorted[i] = r.key;
				
                                //Store the data to array
				data[i].key = r.key;
				for(int j = 0; j < NUMRECS; j++){
					data[i].record[j] = r.record[j];
				}
				//i++;
			}
			
		(void) close(fileRead);
		
		qsort(sorted, count, sizeof(unsigned int), compare);
		
		//Open and create output file 
		int out = open(outFile,O_WRONLY|O_CREAT|O_TRUNC, S_IRWXU);
		if(out<0){
			 printf("Error: Cannot open file %s\n", argv[2]);
			 exit(1);
		}
		//Loop the sorted array, compare with 
		for(int k = 0; k < count; k++){
			for(int l = 0; l < count; l++){
				if(sorted[k] == data[l].key){
					int rc = write(out, &data[l], sizeof(rec_t));
					if (rc != sizeof(rec_t)) {
					    printf("%s","An error has occurred\n");
					    exit(1);
					}
				}
			}
		}
                free(data);
                free(sorted);
		(void)close(out);
		return 0;
}

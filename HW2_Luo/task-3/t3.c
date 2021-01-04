#include <stdio.h> 
#include <stdlib.h>
#include<string.h>
  
// function to convert Hexadecimal to Binary Number 
char* HexToBin(char* hexdec, FILE *result) 
{ 
	
	//printf("%s",hexdec);
	
	int i = 0; 
	int len = strlen(hexdec);
	//printf("%i\n",len);
	char *newHexdec;
	
	if((len-1)%4 !=0){
		newHexdec = malloc(len +1+1);
		strcpy(newHexdec,hexdec);
		newHexdec[len]='0';
		newHexdec[len+1]='\0';
	}else{
		newHexdec = malloc(len+1);
		strcpy(newHexdec,hexdec);
		newHexdec[len+1]='\0';
	}
	int len2 = strlen(newHexdec);
	int part_size = len2/4;


	while (newHexdec[i]){


//		char hexdiv[5];
//		memcpy(hexdiv, &newHexdec[i*1], 4);
//		hexdiv[4] = '\0';

		
		
		char hexdiv[5];
		strncpy(hexdiv,&newHexdec[i*1],4);
		hexdiv[4] = '\0'; 



		
		if(strncmp(hexdiv,"1101",4)==0){
			fprintf(result, "D");
		}else if(strncmp(hexdiv,"1110",4)==0){
			fprintf(result, "E");
		}else if(strncmp(hexdiv,"1111",4)==0){
			fprintf(result, "F");
		}else if(strncmp(hexdiv,"1010",4)==0){
			fprintf(result, "A");
		}else if(strncmp(hexdiv,"1011",4)==0){
			fprintf(result, "B");
		}else if(strncmp(hexdiv,"1100",4)==0){
			fprintf(result, "C");
		}else if(strncmp(hexdiv,"1001",4)==0){
			fprintf(result, "9");
		}else if(strncmp(hexdiv,"1000",4)==0){
			fprintf(result, "8");
		}
		else if(strncmp(hexdiv,"0111",4)==0){
			fprintf(result, "7");
		}else if(strncmp(hexdiv,"0110",4)==0){
			fprintf(result, "6");
		}else if(strncmp(hexdiv,"0101",4)==0){
			fprintf(result, "5");
		}else if(strncmp(hexdiv,"0100",4)==0){
			fprintf(result, "4");
		}else if(strncmp(hexdiv,"0011",4)==0){
			fprintf(result, "3");
		}else if(strncmp(hexdiv,"0010",4)==0){
			fprintf(result, "2");
		}else if(strncmp(hexdiv,"0001",4)==0){
			fprintf(result, "1");
		}else if(strncmp(hexdiv,"0000",4)==0){
			fprintf(result, "0");
		}else{
			fprintf(result, "\n");
		}

//		strncpy(newHexdec,newHexdec+i,i);
		i+=4;	
	}
	free(newHexdec);
//	fprintf(result, "\n");
	return newHexdec; 
} 
  
// driver code 
int main(int argc, char *argv[]){
	char line[2014];
	//FILE *sfp = fopen(argv[1], "r");
	//FILE *out = fopen(argv[2], "w");
	FILE *sfp = fopen("sample.in", "r");
	FILE *out = fopen("output", "w");
	
	if(sfp == NULL || out == NULL){
		perror("Open failed\n");
		return -1; 
	}
	//while(!feof(sfp))
	while(fgets(line, sizeof(line), sfp))
	{
		HexToBin(line,out);
	}
	fclose(sfp);
	return 0;
}
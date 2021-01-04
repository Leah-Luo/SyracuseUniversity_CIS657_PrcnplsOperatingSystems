#include <stdio.h> 
#include <stdlib.h>
  
// function to convert Hexadecimal to Binary Number 
char* HexToBin(char* hexdec, FILE *result) 
{ 
        int i = 0; 
	while (hexdec[i]) { 

		switch (hexdec[i]) { 
		case '0':  
			fprintf(result, "0000");
			break; 
		case '1':  
			fprintf(result, "0001");
			break; 
		case '2':  
			fprintf(result, "0010");
			break; 
		case '3':  
			fprintf(result, "0011");
			break; 
		case '4':  
			fprintf(result, "0100");
			break; 
		case '5':  
			fprintf(result, "0101");
			break; 
		case '6':  
			fprintf(result, "0110");
			break; 
		case '7':  
			fprintf(result, "0111");
			break; 
		case '8':  
			fprintf(result, "1000");
			break; 
		case '9':  
			fprintf(result, "1001");
			break; 
		case 'A': 
		case 'a':  
			fprintf(result, "1010");
			break; 
		case 'B': 
		case 'b': 
			fprintf(result, "1011");
			break; 
		case 'C': 
		case 'c':  
			fprintf(result, "1100");
			break; 
		case 'D': 
		case 'd':  
			fprintf(result, "1101");
			break; 
		case 'E': 
		case 'e': 
			//printf("1110"); 
			fprintf(result, "1110");
			break; 
		case 'F': 
		case 'f': 
			fprintf(result, "1111"); 
			break;
                case '\n': 
                        fprintf(result,"\n"); 
                        break; 
		default:  
			//fprintf(result, "\n");
                        printf("An error has occurred\n");
                        //break;
                        exit(1);
		} 
		i++; 
	}
        //fprintf(result,"\n");
	return hexdec; 
} 
  

// driver code 
int main(int argc, char *argv[]){
	char line[2014];

        //If there are more than two comman line arguments 
	if(argc!=3){
		//fprintf(stderr, "An error has occurred\n");
                printf("An error has occurred\n");
		exit(1);
	}
	//Take the first input file 
	FILE *sfp = fopen(argv[1], "r");
	FILE *out = fopen(argv[2], "w");
	//Open file failed 
	if(sfp == NULL || out == NULL){
		printf("An error has occurred\n");
		exit(1);
	}
	
	while(fgets(line, sizeof(line), sfp))
	{
		//fgets(line, 1024, sfp);
		//printf("\n");
		//printf("%s",line);
		//printf("Equivalent Binary value is : "); 
		//fprintf(out, HexToBin(line));
		HexToBin(line,out);
	}
	fclose(sfp);
	return 0;
}

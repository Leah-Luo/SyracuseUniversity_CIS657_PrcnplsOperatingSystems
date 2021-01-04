#include <stdio.h> 
#include <string.h>
#include <stdlib.h>
//int main{
int main(int argc, char *argv[]){
	char line[1024];
	//Read line
	while(fgets(line, sizeof(line), stdin)){
	       //If user input "exit" 	
               if(!strcmp(line,"exit\n")){
			break;
			exit(1);
		}else{
			char *result = NULL;
			result = strtok(line, " \n\t");
			
			while(result != NULL){
			printf("%s",result);
			result = strtok(NULL, " \n\t");
			
                        printf("\n");
			}
			
		}
	}
	return 0;
}

//
//  main.c
//  Hw Q1
//
//  Created by 羅欣 on 2/13/20.
//  Copyright © 2020 羅欣. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>
#define MAX_LINE 1024

int main(int argc, char *argv[]) {
	
	char line[MAX_LINE];
	
        //If there are more than one command line argument 
	if(argc!=2){
//		fprintf(stderr, "An error has occurred\n");
                printf("An error has occured\n");
		exit(1);
	}

	FILE *sfp = fopen(argv[1],"r");
	//Open file failed error
	if(sfp == NULL)
	{
		printf("An error has occurred\n");
		return -1;
	}

	//Read the file line by line 
	while(!feof(sfp))
	{
		fgets(line,MAX_LINE,sfp);
		char *result = NULL;
		result = strtok(line, " \n");
		int i = 0;
		char *my[4];
		while(result!=NULL){
			my[i] = result;
			i++;
			result = strtok(NULL, " \n");
		}
		my[3] = NULL;

		//Print out the content 
		pid_t fpid;
		fpid = fork();
		//Fork failed error
		if(fpid<0){
			printf("An error has occurred\n");
			exit(1);
		}
		//child
		else if(fpid==0){
			execvp(my[0],my);
//			printf("An error has occurred\n");
//                      exit(1);
		} else{
			wait(NULL);
		}
	}
	fclose(sfp);
	printf("\n");

	return 0;
}

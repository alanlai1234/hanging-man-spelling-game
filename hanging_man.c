#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void check(char);
char str[40];
char underline[40];
int wordcount;
int cur_bodypart;
char draw[6][4] ={" | \0", "( )\0", "_|_\0", " | \0", "/ \\\0", "___\0"};
void print(void);

int main(void){
    cur_bodypart=0;
    FILE *fp;
    int random, amount=1;
    if((fp=fopen("hanging_man_dic.txt", "r"))==NULL){
        printf("fail to open file\n");
        exit(1);
    }
    //choose word
    srand(time(NULL));
    random=rand()%33;
    while ((fgets(str, 40, fp))!=NULL){
        if(amount==random){
            break;
        }
        amount++;
    }

    wordcount=strlen(str)-1;
    for(int i=1;i<wordcount-1;i++){
        underline[i]='_';
    }
    underline[0]=str[0];
    underline[wordcount-1]=str[wordcount-1];
    underline[wordcount]='\0';
    str[wordcount]='\0';
    
    print();

    //start
    
    char input;
    while(cur_bodypart<6){
        if(!strcmp(str, underline)){
            printf("correct!\n");
            exit(1);
        }
        fflush(stdin);
        scanf(" %c", &input);
        check(input);
        print();
    }
    printf("bruh..\ncorrect answer is '%s'\n", str);
}

void check (char input){
    int correct=0;
    for(int i=0;i<wordcount;i++){
        if(str[i]==input){
            correct=1;
            underline[i]=str[i];
        }
    }
    if(!correct){
        printf("\033[0;31m");
        cur_bodypart++;
    }
}

void print(void){
    //hanging _structure
    printf("*******\n");
    for (int i = 0; i < cur_bodypart; i++)
    {
        printf("*   %s\n", draw[i]);
    }
    
    for(int i=0;i<6-cur_bodypart;i++){
        printf("*\n");
    }
    //underline
    printf("%s\n", underline);
    // printf("%s\n", str);
    printf("\033[0m");
}
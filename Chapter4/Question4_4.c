#include<stdio.h>
void  judge(int *x,int *y,char a,char b){
    printf(" in function \n");
     if(a =='r') *x=0;
     else if(a=='b') *x=1;
     else if(a=='g') *x=2;
     if(b =='r') *y=0;
     else if( b=='b') *y=1;
     else if( b=='g') *y=2;
}
/*
int main(){
char input[30];
 while(1){
    memset(input,'\0',sizeof(input));
    scanf("%s",input);
    printf(" echo : %s",input);
    if(input[0]=='\0' || input[0]=='\n') break;
    int numA[3][3];
    int numB[3][3];
    memset(numA,0,sizeof(numA));
    memset(numB,0,sizeof(numB));
    int x =0;
    int y =0;
    judge(&x,&y,input[0],input[5]);
    numA[x][y] =1;
    numA[y][x] =1;
    judge(&x,&y,input[1],input[4]);
    numA[x][y] =numA[y][x] =1;
    judge(&x,&y,input[2],input[3]);
    numA[x][y] =numA[y][x] =1;

    judge(&x,&y,input[6],input[11]);
    numB[x][y] =numB[y][x] =1;
    judge(&x,&y,input[7],input[10]);
    numB[x][y] =numB[y][x] =1;
    judge(&x,&y,input[8],input[9]);
    numB[x][y] =numB[y][x] =1;
    int ok =1;
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            printf(" %d ",numA[i][j]);
        }
        printf(" \n");
    }
    printf("****************\n");
        for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            printf(" %d ",numB[i][j]);
        }
        printf(" \n");
    }
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(numA[i][j]!=numB[i][j]){
                ok =0;
                break;
            }
        }
    }
    if(ok ==0){
        printf("FALSE \n");
    }else printf("True \n");

 }
} */

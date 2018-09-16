#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
char print_content[6][300] ={{"Welcome to Student Performance Management System(SPMS)\n1 - Add\n2 - Remove\n3 - Query\n4 - Show ranking\n5 - Show Statistics\n0 - Exit\n"},
{"Please enter the SID,CID,name and four scores.Enter 0 to finish.\n"},{"Please enter SID or name.Enter 0 to finish.\n"},
{"Please enter SID or name.Enter 0 to finish.\n"},{"Showing the ranklist hurts students' self-esteem.Don't do that.\n"},
{"Please enter class ID,0 for the whole statistics\n"}};
int totalNums =0;
struct Student{
 char sid[15];
 int  cid;
 char name[15];
 int chinese;
 int math;
 int english;
 int program;
 int totalscore;
 double averagescore;
 int ranksequence;
}student[120];
void add(){
 char sid_add[15];
 int  cid_add;
 char name_add[15];
 int  chinese_add;
 int  math_add;
 int  english_add;
 int  program_add;
 memset(sid_add,'\0',sizeof(sid_add));
 memset(name_add,'\0',sizeof(name_add));
 scanf("%s",sid_add);

  if(strlen(sid_add)==1) return;
 scanf(" %d %s %d %d %d %d",&cid_add,name_add,&chinese_add,&math_add,&english_add,&program_add);
 //sid compare
 for(int i=0;i<totalNums;i++){
    if(strcmp(student[i].sid,sid_add)==0) {printf("Duplicated SID \n");return;}
 }
 strcpy(student[totalNums].sid,sid_add);
 student[totalNums].cid =cid_add;
 strcpy(student[totalNums].name,name_add);
 student[totalNums].chinese =chinese_add;
 student[totalNums].math =math_add;
 student[totalNums].english=english_add;
 student[totalNums].program =program_add;
 student[totalNums].totalscore =(chinese_add+math_add+english_add+program_add);
 student[totalNums].averagescore =(student[totalNums].totalscore*1.0)/4;
 totalNums++;
/* int ranksnums[totalNums];
 for(int i=0;i<totalNums;i++)
    ranksnums[i] =(i);
 memset(ranksnums,0,sizeof(ranksnums));
 for(int i=0;i<totalNums-1;i++){
    for(int j=i+1;j>0;j--){
        if(student[j].totalscore> student[j-1].totalscore){
            int temp =ranksnums[j];
            ranksnums[j] = ranksnums[j-1];
            ranksnums[j-1] =temp;
        }
    }
 }
 for(int i=0;i<totalNums;i++){
    if(student[ranksnums[i]].totalscore==student[ranksnums[i+1]].totalscore && i<totalNums-1){
        student[ranksnums[i]].ranksequence =student[ranksnums[i+1]].ranksequence =(i+1);
        i++;
    }
    else student[ranksnums[i]].ranksequence =(i+1);
 }*/

}
void remv(){
char sid_name[15];
while(1){
memset(sid_name,'\0',sizeof(sid_name));
scanf("%s",sid_name);
if(strlen(sid_name)==1) return;
//name  some problem for double delete twice or more
    int total =totalNums;
    for(int i=0;i<total;i++){
        if(strcmp(student[i].name,sid_name)==0 || strcmp(student[i].sid,sid_name)==0){
                printf("name: %s sid: %s object: %s\n",student[i].name,student[i].sid,sid_name);
            for(int j=i;j<total-1;j++){

               /* memcpy(&student[j],&student[j+1],sizeof(student[j]));*/
                strcpy(student[j].sid,student[j+1].sid);
                student[j].cid =student[j+1].cid ;
                strcpy(student[j].name,student[j+1].name);
                student[j].chinese =student[j+1].chinese;
                student[j].math =student[j+1].math ;
                student[j].english=student[j+1].english;
                student[j].program =student[j+1].program;
                student[j].totalscore =student[j+1].totalscore;
                student[j].averagescore =student[j+1].averagescore;


            }
            total--;
        }
    }
    printf("%d student(s) removed \n",(totalNums-total));
    totalNums =total;

    }
}
void que(){
    char sid_name[15];
    while(1){
    memset(sid_name,'\0',sizeof(sid_name));
    scanf("%s",sid_name);
    printf("echo : sid_name %s  num: %d \n",sid_name,totalNums);
    if(strlen(sid_name)==1) return;
   int ranksnums[totalNums];
   memset(ranksnums,0,sizeof(ranksnums));
   for(int i=0;i<totalNums;i++)
   {
       ranksnums[i] =i;
  //     printf(" %d \n",i);
     }
   printf("totalNums : %d\n",totalNums);
   for(int i=0;i<totalNums-1;i++){
//        printf(" name: %s  score: %d \n",student[i].name,student[i].totalscore);
    for(int j=i+1;j>0;j--){
//         printf("1\n");
//        printf(" %d(j): %d  %d(j-1): %d \n",j,student[j].totalscore,j-1,student[j-1].totalscore);
        if(student[j].totalscore> student[j-1].totalscore){
//            printf("2\n");
            int temp =ranksnums[j];
            ranksnums[j] = ranksnums[j-1];
            ranksnums[j-1] =temp;
        }
    }
 }
// printf("ovew\n");
// printf("ranksnums \n");

// printf("ranksnums \n");
 for(int i=0;i<totalNums;i++){
//     printf(" i is %d \n ",i);
    if(((i<totalNums-1))&&(student[ranksnums[i]].totalscore==student[ranksnums[i+1]].totalscore)){
//        printf("%d  %d %d \n",i,ranksnums[i],ranksnums[i+1]);
        student[ranksnums[i]].ranksequence =student[ranksnums[i+1]].ranksequence =(i+1);

        i++;
    }
    else {student[ranksnums[i]].ranksequence =(i+1);printf("%d  %d \n",i,ranksnums[i]);}
 }
// printf("ee\n");
    int total =totalNums;
    int find =0;
    for(int i=0;i<total;i++){
 //       printf(" enum :%s  object :%s \n",student[i].name,sid_name);
        if(strcmp(student[i].name,sid_name)==0 || strcmp(student[i].sid,sid_name)==0){

        if(find ==0) {
            find =1;
            printf("R   SID   CID   NAME   C  M   E  P   TOTAL    AVERAGE \n");
            }
            printf("%d  %s     %d   %s     %d  %d  %d %d   %d        %.2f\n",student[i].ranksequence,student[i].sid,student[i].cid,student[i].name,student[i].chinese,student[i].math,student[i].english,student[i].program,student[i].totalscore,student[i].averagescore);

        }
    }
}
}
void rak(){
    return ;
}
int largerthan60(int num1,int num2,int num3,int num4){
 int temp[4];
 memset(temp,0,sizeof(temp));
 if(num1>=60) temp[0]=1;
 if(num2>=60) temp[1]=1;
 if(num3>=60) temp[2]=1;
 if(num4>=60) temp[3]=1;
 return (temp[0]+temp[1]+temp[2]+temp[3]);
}
void stas(){
  int tempNums[4][3]; //0-chinese 1-math 2-english 3-program
  int tempSubs[5];
  int ch=0;
  scanf("%d",&ch);

  memset(tempNums,0,sizeof(tempNums));
  memset(tempSubs,0,sizeof(tempSubs));
  int classSum =0;
  for(int i=0;i<totalNums;i++){
    if(student[i].cid ==ch || (ch==0)){
    classSum++;
    tempSubs[largerthan60(student[i].chinese,student[i].math,student[i].english,student[i].program)]++;
    tempNums[0][0] +=student[i].chinese;
    tempNums[0][1] +=(student[i].chinese>=60);
    tempNums[1][0] +=student[i].math;
    tempNums[1][1] +=(student[i].math>=60);
    tempNums[2][0] +=student[i].english;
    tempNums[2][1] +=(student[i].english>=60);
    tempNums[3][0] +=student[i].program;
    tempNums[3][1] +=(student[i].program>=60);
  }
  }


  for(int i=0;i<4;i++){
    if(i==0) printf("Chinese\n");
    else if(i==1) printf("Math\n");
    else if(i==2) printf("English\n");
    else printf("Program\n");
    printf("Average Score: %.2f\n",(1.0*tempNums[i][0])/totalNums);
    printf("Number of passed students: %d\n",tempNums[i][1]);
    printf("Number of failed students: %d\n",(classSum-tempNums[i][1]));
  }
  printf("Overall:\n");
  printf("Number of students who passed all subjects: %d\n",tempSubs[4]);
  printf("Number of students who passed 3 or more subjects: %d\n",tempSubs[4]+tempSubs[3]);
  printf("Number of students who passed 2 or more subjects: %d\n",tempSubs[4]+tempSubs[3]+tempSubs[2]);
  printf("Number of students who passed 1 or more subjects: %d\n",tempSubs[4]+tempSubs[3]+tempSubs[2]+tempSubs[1]);
  printf("Number of students who failed all subjects: %d\n",tempSubs[0]);


}

/*int main(){
    memset(student,0,sizeof(student));
 while(1){
    printf(print_content[0]);
    int  ch;
    while(scanf("%d",&ch)!=1);
    printf(print_content[ch]);    if(ch==0) break;else{
        switch(ch){
      case 1:add();break;
      case 2:remv();break;
      case 3:que();break;
      case 4:rak();break;
      case 5:stas();break;
      default:break;


        }
    }
    fflush(stdin);
    Sleep(4000);
    system("cls");
 }
 return 0;
}*/
//当初本科没有写出来的东西没想到6年还是5年后在清华些出来，可笑当时还上网四处求题目，压根没有心思好好学习，自己罪过不小。2019/8/21
//幼稚不知轻重的时刻，代价沉重，自己一开始把路走好该多好，随大流，没有主见，注定完蛋。了解债务，荒废时间，要加倍夺回来。
//逻辑中短路运算特性，吃亏了。

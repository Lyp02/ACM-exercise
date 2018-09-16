#include<stdio.h>
#include<math.h>
void Test4_1_1(){
int maxn =120;
int s1chars[26];
int s2chars[26];
char s1[maxn];
char s2[maxn];
memset(s1chars,0,sizeof(s1chars));
memset(s2chars,0,sizeof(s2chars));
memset(s1,'\0',sizeof(s1));
memset(s2,'\0',sizeof(s2));
scanf("%s",s1);
scanf("%s",s2);
//printf("s1 %s  s2 %s",s1,s2);
int n1 =strlen(s1);
int n2 =strlen(s2);
if(n1!=n2) return;
for(int i=0;i<n1;i++){
    if(s1[i]=='A') s1chars['Z'-'A'] +=1;
    else s1chars[s1[i]-'A'-1] +=1;
    s2chars[s2[i]-'A'] +=1;
}
printf(" 1\n");
int flag =1;
for(int i=0;i<26;i++){
    if(s1chars[i]!=s2chars[i]){flag =0;break;}
}
if(flag ==1) {printf("YES \n");return;}

else {
    memset(s1chars,0,sizeof(s1chars));
    memset(s2chars,0,sizeof(s2chars));
    for(int i=0;i<n2;i++){
    if(s2[i]=='A') s2chars['Z'-'A'] +=1;
    else s2chars[s2[i]-'A'-1] +=1;
    s1chars[s1[i]-'A'] +=1;
}
printf(" 2\n");
flag =1;
for(int i=0;i<26;i++){
    if(s1chars[i]!=s2chars[i]){flag =0;break;}
      }
if(flag ==1) {printf("YES \n");return;}
else printf("NO \n");
return;
   }
   return ;
}
int  goA(int p,int k,int* a,int n){
int left =k;
int t =p;
int r =0;
while(k>0){
    while(a[t]==0) t =((t+1)%n);
    r =t;
    t=(t+1)%n;
    k--;
}
return r;
}
int  goB(int p,int m,int *a,int n){
int t =p;
int r=0;
while(m>0){
    while(a[t]==0) if(t>0){
        t =(t-1)%n;
    }else t =n-1;
    r =t;
    t =(t>0)?((t-1)%n):(n-1);

    m--;
}
return r;
}
void Test4_3(){
 int  n=0;
 int left =0;
 int k=0;
 int m=0;
 scanf("%d",&n);
 scanf("%d",&k);
 scanf("%d",&m);
 int a[n];
 memset(a,0,sizeof(a));
 for(int i=0;i<n;i++){
    a[i] =(i+1);
 }
 left =n;
 int p1 =0,p2=n-1;
 while(left >0){
    p1 =goA(p1,k,a,n);
    p2 =goB(p2,m,a,n);

    if(p1==p2){

        if(left>1)printf("%3d,",a[p1]);
        else printf("%3d",a[p1]);
        left --;
    }
    else{
        left =left -2;
        printf("%3d %3d,",a[p1],a[p2]);
    }
    a[p1] =0;
    a[p2] =0;
 }
}
int pow2(int i){
 int sum =1;
 if(i<0) return 1;
 else {
    for(int j=i;j>=1;j--)
        sum =sum *2;
 }
 return sum;
}
int chars2int(char *s,int slen,int begin,int len){
  if((begin +len)>slen ) return -1;
  int sum =0;
  for(int i=0;i<len;i++){
    sum =((s[begin++]-'0')*pow2(len-1-i))+sum;
  }
  return sum;
}
void Test4_4(){
 char arr[8][127];
 char head[127];
 char content[300];
 memset(arr,'\0',sizeof(arr));
 memset(head,'\0',sizeof(head));
 memset(content,'\0',sizeof(content));
 scanf("%s",head);
 scanf("%s",content);
 int begin=0;
 int end =0;
 int count =0;
 for(int i=0;i<8;i++){
   for(int j=0;j<(pow2(i+1)-1);j++){
    if(count<strlen(head))arr[i][j] =head[count++];
    else end=1;
   }
   if(end==1) break;
 }
/* for(int i=0;i<8;i++){
    printf(" %d :",i);
    for(int j=0;j<strlen(arr[i]);j++){
        printf(" %c",arr[i][j]);
    }
    printf(" \n");
 }
 */
  int len =0;
  int a ,b=0;
  char res[200];
  memset(res,'\0',sizeof(res));
  int index =0;
  for(int i=0;i<strlen(content);){
    len =chars2int(content,strlen(content),i,3);
    if(len ==0) break;
    a =len;//
    i =i+3;
    while(1){
        b =chars2int(content,strlen(content),i,len);
        if(b!=(pow2(len)-1)){
            res[index++] =arr[len-1][b];
            i =i+len;
        }else {
            i =i+len;
            break;
        }
    }
  }
  printf("\n Decoding : %s\n",res);
}


void Test4_5(){ //字符串这边太糟糕，要字符串练习，同时这道题目我思路理解错了，我是立即更新，审题还是要多看看
 int r =0;
 int c =0;
 char cmds[7][5];
 int  nums[7][50];
 memset(cmds,'\0',sizeof(cmds));
 memset(nums,0,sizeof(nums));
 int cmdCounts=0;
 int queCounts=0;
 int x=0,y=0;
 int flag =1;
 scanf("%d",&r);
 scanf("%d",&c);
 char buf[4];
 memset(buf,'\0',sizeof(buf));
 scanf("%d",&cmdCounts);
 for(int i=0;i<cmdCounts;i++){
    scanf("%s",cmds[i]);
    int j=0;
    int ch;
    while((ch=getchar())!=EOF) if(isdigit(ch)){
        nums[i][j++] =ch-'0';
    }else if(ch=='\n') break;


 }
 printf(" after cmds input \n");
 scanf("%d",&queCounts);
 int ques[queCounts][2];
 int cps[queCounts][2];
 memset(ques,0,sizeof(ques));
 memset(cps,0,sizeof(cps));
 for(int i=0;i<queCounts;i++){
    scanf("%d",&ques[i][0]);
    scanf("%d",&ques[i][1]);
    cps[i][0] =ques[i][0];
    cps[i][1] =ques[i][1];
 }
 printf(" after ques input \n");

 int ans[queCounts][2];
 int gones[queCounts];
 memset(ans,0,sizeof(ans));
 memset(gones,0,sizeof(gones));
 printf(" CONTENT \n");
 for(int i=0;i<cmdCounts;i++){
    printf("cmd %s :",cmds[i]);
    int j=0;
    while(nums[i][j]!=0) {printf(" %d",nums[i][j]);j++;}
    printf("\n");
 }
 for(int j=0;j<queCounts;j++){
    printf(" %d. (%d,%d) \n",j,ques[j][0],ques[j][1]);

 }
 printf(" OVER\n");

 for(int i=0;i<cmdCounts;i++){
    if(cmds[i][0]=='D'){
        if(cmds[i][1]=='R'){
            if(r<1) break;
            r--;
            for(int m=0;m<nums[i][0];m++){
                for(int k=0;k<queCounts;k++){
                    if(ques[k][0] ==nums[i][m+1]) gones[k] =1;
                    else if(ques[k][0]>nums[i][m+1]) ques[k][0]--;
                }
            }

        }
        else if(cmds[i][1]=='C'){
                if(c<1) break;
                c--;
             for(int m=0;m<nums[i][0];m++){
                for(int k=0;k<queCounts;k++){
                    if(ques[k][1] ==nums[i][m+1]) gones[k] =1;
                    else if(ques[k][1]>nums[i][m+1]) ques[k][1]--;
                }
             }
        }
        else break;
    }
    else if(cmds[i][0]=='I'){
        if(cmds[i][1]=='R'){
                r++;
            for(int m=0;m<nums[i][0];m++){
                for(int k=0;k<queCounts;k++){
                    if(ques[k][0]>=nums[i][m+1]) ques[k][0]++;
                }
             }

        }
        else if(cmds[i][1]=='C'){
            for(int m=0;m<nums[i][0];m++){
                c++;
                for(int k=0;k<queCounts;k++){
                    if(ques[k][1]>=nums[i][m+1]) ques[k][1]++;
                }
             }

        }
        else break;
    }
    else if(cmds[i][0]=='E' &&cmds[i][1]=='X'){
         for(int k=0;k<queCounts;k++){
            if(nums[i][0] ==ques[k][0] && nums[i][1]==ques[k][1]){
                ques[k][0] =nums[i][2];
                ques[k][1] =nums[i][3];
            }
            else if(nums[i][2]==ques[k][0] && nums[i][3]==ques[k][1]){
                ques[k][0] =nums[i][0];
                ques[k][1] =nums[i][1];
            }

         }
    }
    else break;
 }
 int times =1;
 printf("Spreadsheet #%d\n",times++);
 for(int k=0;k<queCounts;k++){
    if(gones[k]==1){
        printf("Cell data in (%d,%d) GONE\n",cps[k][0],cps[k][1]);
    }else{
        printf("Cell data in  (%d,%d) moved to (%d,%d)\n",cps[k][0],cps[k][1],ques[k][0],ques[k][1]);
    }
 }

}

void Test4_5_1(){//按照书上思路，“各个x值不同，且顺序任意”
 int r =0;
 int c =0;
 char cmds[7][5];
 int  nums[7][50];
 memset(cmds,'\0',sizeof(cmds));
 memset(nums,0,sizeof(nums));
 int cmdCounts=0;
 int queCounts=0;
 int x=0,y=0;
 int flag =1;
 scanf("%d",&r);
 scanf("%d",&c);
 char buf[4];
 memset(buf,'\0',sizeof(buf));
 scanf("%d",&cmdCounts);
 for(int i=0;i<cmdCounts;i++){
    scanf("%s",cmds[i]);
    int j=0;
    int ch;
    while((ch=getchar())!=EOF) if(isdigit(ch)){
        nums[i][j++] =ch-'0';
    }else if(ch=='\n') break;


 }
 printf(" after cmds input \n");
 scanf("%d",&queCounts);
 int ques[queCounts][2];
 int cps[queCounts][2];
 memset(ques,0,sizeof(ques));
 memset(cps,0,sizeof(cps));
 for(int i=0;i<queCounts;i++){
    scanf("%d",&ques[i][0]);
    scanf("%d",&ques[i][1]);
    cps[i][0] =ques[i][0];
    cps[i][1] =ques[i][1];
 }
 printf(" after ques input \n");

 int ans[queCounts][2];
 int gones[queCounts];
 memset(ans,0,sizeof(ans));
 memset(gones,0,sizeof(gones));
 printf(" CONTENT \n");
 for(int i=0;i<cmdCounts;i++){
    printf("cmd %s :",cmds[i]);
    int j=0;
    while(nums[i][j]!=0) {printf(" %d",nums[i][j]);j++;}
    printf("\n");
 }
 for(int j=0;j<queCounts;j++){
    printf(" %d. (%d,%d) \n",j,ques[j][0],ques[j][1]);

 }
 printf(" OVER\n");

 for(int i=0;i<cmdCounts;i++){
    if(cmds[i][0]=='D'){
        if(cmds[i][1]=='R'){
            if(r<1) break;
            r--;
            for(int m=0;m<nums[i][0];m++){
                for(int k=0;k<queCounts;k++){
                    if(cps[k][0] ==nums[i][m+1]) gones[k] =1;
                    else if(cps[k][0]>nums[i][m+1]) ques[k][0]--;
                }
            }

        }
        else if(cmds[i][1]=='C'){
                if(c<1) break;
                c--;
             for(int m=0;m<nums[i][0];m++){
                for(int k=0;k<queCounts;k++){
                    if(cps[k][1] ==nums[i][m+1]) gones[k] =1;
                    else if(cps[k][1]>nums[i][m+1]) ques[k][1]--;
                }
             }
        }
        else break;
    }
    else if(cmds[i][0]=='I'){
        if(cmds[i][1]=='R'){
                r++;
            for(int m=0;m<nums[i][0];m++){
                for(int k=0;k<queCounts;k++){
                    if(cps[k][0]>=nums[i][m+1]) ques[k][0]++;
                }
             }

        }
        else if(cmds[i][1]=='C'){
            for(int m=0;m<nums[i][0];m++){
                c++;
                for(int k=0;k<queCounts;k++){
                    if(cps[k][1]>=nums[i][m+1]) ques[k][1]++;
                }
             }

        }
        else break;
    }
    else if(cmds[i][0]=='E' &&cmds[i][1]=='X'){
         for(int k=0;k<queCounts;k++){
            if(nums[i][0] ==ques[k][0] && nums[i][1]==ques[k][1]){
                ques[k][0] =nums[i][2];
                ques[k][1] =nums[i][3];
            }
            else if(nums[i][2]==ques[k][0] && nums[i][3]==ques[k][1]){
                ques[k][0] =nums[i][0];
                ques[k][1] =nums[i][1];
            }

         }
    }
    else break;
 }
 int times =1;
 printf("Spreadsheet #%d\n",times++);
 for(int k=0;k<queCounts;k++){
    if(gones[k]==1){
        printf("Cell data in (%d,%d) GONE\n",cps[k][0],cps[k][1]);
    }else{
        printf("Cell data in  (%d,%d) moved to (%d,%d)\n",cps[k][0],cps[k][1],ques[k][0],ques[k][1]);
    }
 }

}


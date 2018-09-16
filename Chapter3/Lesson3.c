#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include<math.h>
  const char* rev ="A   3  HIL JM O   2TUVWXY51SE Z  8 ";
  const char* msg[] ={"not a palindrome","a regular palindrome","a mirrored string","a mirrored palindrome"};
void Question3_1(){
   int maxn =105;
   int a[maxn];
   int x=0;
   int n=0;
   while(scanf("%d",&x)==1)
    a[n++] =x;
   for(int i=n-1;i>=1;i--)
    printf("%d",a[i]);
   printf("%d\n",a[0]);
   return ;
}
void Question3_2(){
   int n=0;
   int k=0;
   while((scanf("%d",&n)==1)&&(scanf("%d",&k)==1)){
    if((k<=n)&&(n<=100)){
            int arr[n];
            for(int k=0;k<n;k++){
                arr[k]=0;
            }
            for(int i=1;i<=k;i++){
        for(int j=0;j<n;j++){
            if(((j+1)%i)==0)
                arr[j] =!arr[j];
        }
    }
    for(int m=0;m<n;m++){
        if(arr[m]!=0){
            printf("%d ",(m+1));
        }

    }
    printf("\n");
    }

   }
}
void Question3_3(){
 int maxn =20;
 int a[maxn][maxn];
 int n,x,y,tot =0;
 scanf("%d",&n);
 memset(a,0,sizeof(a));
 tot =a[x=0][y=n-1]=1;
 while(tot<n*n){
    while(x+1<n && !a[x+1][y]) a[++x][y] =++tot;
    while(y-1>=0 && !a[x][y-1]) a[x][--y] =++tot;
    while(x-1>=0 &&!a[x-1][y])  a[--x][y] =++tot;
    while(y+1<n && !a[x][y+1])  a[x][++y]=++tot;
 }
 for(x =0;x<n;x++){
    for(y=0;y<n;y++){
        printf("%3d",a[x][y]);
    }
    printf("\n");
 }
 return ;
}
void Question3_4(){
  int count =0;
  char s[20],buf[99];
  scanf("%s",s);
  for(int abc =111;abc<=999;abc++){
    for(int de=11;de<=99;de++){
        int x =abc*(de%10),y=abc*(de/10),z=abc*de;
        sprintf(buf,"%d%d%d%d%d",abc,de,x,y,z);
        int ok=1;
        for(int i=0;i<strlen(buf);i++)
            if(strchr(s,buf[i])==NULL) ok=0;
        if(ok){
            printf("<%d>\n",++count);
            printf("%5d\nX %4d\n----\n%5d\n%4d\n----\n%5d\n\n",abc,de,x,y,z);
        }


    }
    printf("The number of solutions =%d\n",count);
    return ;
  }
}
void Question3_5(){
 int c,q=1;
 while((c=getchar())!=EOF){
    if(c=='"'){
        printf("%s",q?"¡°":"¡±");
        q =!q;
    }
    else printf("%c",c);
 }
 return ;

}
void Question3_6(){
  char s[] ="`1234567890-=QWERTYUIOP[]\ASDFGHJKL;'ZXCVBNM,./";
  int c;
  int i;
  while((c=getchar())!=EOF){
        for(i=1;s[i]&&s[i]!=c;i++);
        if(s[i]) putchar(s[i-1]);
        else putchar(c);
  }
  return ;
}
char r(char ch){
 if(isalpha(ch)) return rev[ch-'A'];
 return rev[ch -'0'+25];
}
void Question3_7(){
  char s[30];
  while((scanf("%s",s)==1)){
    int len =strlen(s);
    int p=1,m=1;
    for(int i=0;i<(len+1)/2;i++){
        if(s[i]!=s[len-1-i]) p=0;
        if(r(s[i])!=s[len-1-i]) m=0;
    }
    printf("%s -- is %s.\n\n",s,msg[m*2+p]);
  }
  return;
}
void Question3_8(){
  int n =0;
  int maxn =1010;
  int a[maxn],b[maxn];
  int kase =0;
   while(scanf("%d",&n)==1 && n){
    printf("Game %d:\n",++kase);
    for(int i=0;i<n;i++) scanf("%d",&a[i]);
    for(;;){
        int A =0,B=0;
        for(int i=0;i<n;i++){
            scanf("%d",&b[i]);
            if(a[i]==b[i]) A++;
        }
        if(b[0]==0) break;
        for(int d =1;d<=9;d++){
            int c1 =0,c2=0;
            for(int i=0;i<n;i++){
                if(a[i]==d) c1++;
                if(b[i]==d) c2++;
            }
            if(c1<c2) B+=c1;
            else B+=c2;
        }
        printf("   (%d,%d\n)",A,B-A);
    }
   }
   return;
}
void Question3_9(){
  int maxn =100005;
  int ans[maxn];
  int T,n;
  memset(ans,0,sizeof(ans));
  for(int m=1;m<maxn;m++){
    int x =m;
    int y=m;
    while(x>0){
        y +=x%10;
        x=x/10;
    }
    if(ans[y]==0 || m<ans[y]) ans[y]=m;
  }
  scanf("%d",&T);
  while(T--){
    scanf("%d",&n);
    printf("%d\n",ans[n]);
  }
  return ;
}
int less(const char *s,int p,int q){
 int n =strlen(s);
 for(int i=0;i<n;i++)
    if(s[(p+i)%n]!=s[(q+i)%n])
    return s[(p+i)%n] < s[(q+i)%n];
 return 0;
}
void Question3_10(){
  int T;
  int maxn =100005;
  char s[maxn];
  scanf("%d",&T);
  while(T--){
    scanf("%s",s);
    int ans =0;
    int n =strlen(s);
    for(int i=1;i<n;i++){
        if(less(s,i,ans)) ans= i;
    }
    for(int i=0;i<n;i++)
        putchar(s[(i+ans)%n]);
    putchar('\n');
  }
}
void Test3_1(){
   char content [100];
   int sum =0;
  // while((scanf("%s",content)!=0)){
     scanf("%s",content);
     int num =0;
     for(int i=0;i<strlen(content);i++){
        if(content[i]=='O'){
            ++num;
            sum +=num;
        }
        else if(content[i]=='X'){
             num =0;
        }
     }
     printf("Score : %d",sum);
     sum =0;
 //  }
}
int  chars2num(char *s,int i,int j){
  int result =0;
  for(int k=i;k<=j;k++){
    result =result*10 +(s[i]-'0');
  }
  return result;
}
void Test3_2(){
 double weignt[4] ={12.01,1.008,16.00,14.01};
 int element [4] ={0,0,0,0};
 double mol =0.0;
 char content[300];

  while(1){
    memset(content,'\0',300);
    memset(element,0,sizeof(element));
    scanf("%s",content);
    if(content[0]=='\0') break;
    int i=0;
    printf(" IS alphabet %d \n",isalpha(content[i]));
    while(isalpha(content[i])){
        int index =0;
        if(content[i]=='C') index =0;
        else if(content[i]=='H') index =1;
        else if(content[i]=='O') index =2;
        else if(content[i]=='N') index =3;
        else index =0;
        printf("index %d \n",index);
        int j=i+1;
        while(isdigit(content[j])) j++;
        printf(" i:%d  j:%d \n",i+1,j-1);
        if(j>i+1){
            int num =chars2num(content,i+1,j-1);
            element[index] +=num;
            printf("num  %d \n",num);
        }else element[index] +=1;
        i =j;
        if(content[j]=='\0') break;

    }
    for(int w =0;w<4;w++){
        printf(" element[%d] : %d  weight[%d] : %f \n",w,element[w],w,weignt[w]);
    }
    mol =element[0]*weignt[0]+element[1]*weignt[1]+element[2]*weignt[2]+element[3]*weignt[3];
    printf(" %s mol : %.3f g/mol \n",content,mol);
  }

  }
void splitAndadds(int num,int* arr){
    int x =num;
    int temp =0;
    while(x>0){
        temp =x%10;
        x=x/10;
        arr[temp]++;
    }
    return ;
}
void Test3_3(){
 int element[10];
 int n=1;
 memset(element,0,sizeof(element));
 while((n<=23)){
    if(n>23) break;
    splitAndadds(n++,element);
 }
 for(int i=0;i<10;i++){
    printf(" %d : times :%d \n ",i,element[i]);
 }
}
void Test3_4(){
  char content[90];
  memset(content,'\0',sizeof(content));
  int min =0;
  int n =0;
  while(1){
   scanf("%s",content);
   if(content[0]=='\0') break;
   min =strlen(content);
   n =strlen(content);
   int k=1;
 //  printf(" min : %d \n",min);
   for(k=1;k<=(n/2);k++){
    int i=0;
    printf(" k :%d \n",k);
    while((content[i]==content[i+k])&&((i+k)<n)){i++;}
    printf(" i  :%d \n",i);
   if((i+k)>=n) {
   if(min > k) min =k;
//    printf(" min: %d  k: %d",min,k);
   }
   }
   printf(" Minmum Periodic is %d ",min);
  }
}
void swap(char a[5][5],int x1,int y1,int x2,int y2){
  // printf(" in swap \n");
   char temp =a[x1][y1];
   a[x1][y1]=a[x2][y2];
   a[x2][y2]=temp;
  // printf(" out swap \n");
}
void Test3_5(){
  int xmin =0,xmax=4;
  int ymin =0,ymax=4;
  int x=0,y=0;
  int counts =0;
  int ch;
  char element[5][5];
  char comands[30];
  memset(element,'\0',sizeof(element));
  memset(comands,'\0',sizeof(comands));
  while((counts <25)&&((ch =getchar())!=EOF)){
   // ch =getchar();
    if(ch=='\n') break;
    else{
        if(ch==' '){x=counts/5;y=counts%5;}
        element[counts/5][counts%5] =ch;
        counts++;
    }
  }
    for(int i=0;i<25;i++){
    printf(" %c",element[i/5][i%5]);
    if(i>0 && (i+1)%5==0) printf("\n");
  }
  printf("*****\n");
  scanf("%s",comands);
  //printf(" comands :%s  \n",comands);
  for(int i=0;i<strlen(comands);i++){
    //printf(" comands[%d] : %c ",i,comands[i]);
    if(comands[i]=='0') break;
    else {
        if(comands[i]=='A' &&(x>=1)){swap(element,x,y,x-1,y);x=x-1;}
        else if(comands[i]=='B' &&(x<=3)){swap(element,x,y,x+1,y);x=x+1;}
        else if(comands[i]=='L' &&(y>=1)){swap(element,x,y,x,y-1);y=y-1;}
        else if(comands[i]=='R' &&(y<=3)){swap(element,x,y,x,y+1);y=y+1;}
        else {
            printf("This puzzle has no final configuration\n");
        }

  printf("*****\n");
    }
  }
  for(int i=0;i<25;i++){
    printf(" %c",element[i/5][i%5]);
    if(i>0 && (i+1)%5==0) printf("\n");
  }
}
void Test3_6(){
  while(1){
    int r =0;
    int c=0;
    scanf("%d",&r);
    scanf("%d",&c);
    char content[r][c+10];
    int  marked[r][c];
    memset(content,'\0',sizeof(content));
    memset(marked,-1,sizeof(marked));
    for(int i=0;i<r;i++){
        scanf("%s",content[i]);
    }
    int times =1;
    int counts =1;
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            if(content[i][j]=='*') marked[i][j] =0;
            else if((j==0 || i==0)&&(content[i][j]!='*')) {marked[i][j] =counts;counts++;}
            else if(content[i][j-1]=='*' || content[i-1][j]=='*') {marked[i][j]=counts;counts++;}
            else marked[i][j]=-1;
        }
    }
    printf("puzzle #%d:\n" ,times);
    times++;
    printf("Across\n");
    for(int i=0;i<r;i++)
    for(int j=0;j<c;j++){
        if(marked[i][j]>0){
            printf("  %d.",marked[i][j]);
            while(marked[i][j]!=0 &&(j<c))
            {putchar(content[i][j]);j++;}
            printf("\n");
        }
    }
/*    printf("Down\n");
    for(int j=0;j<c;j++){
        for(int i=0;i<r;i++){
            if(marked[i][j] >0){
                printf("  %d.",marked[i][j]);
                while(marked[i][j]!=0 &&(i<r)){
                    putchar(content[i][j]);
                    i++;
                }
                printf("\n");
            }
        }
    }
    */
     printf("Down\n");
     for(int i=0;i<r;i++)
    for(int j=0;j<c;j++){
        if(marked[i][j]>0){
            printf("  %d.",marked[i][j]);
            int m =i;
            while(marked[m][j]!=0 &&(m<r))
            {putchar(content[m][j]);marked[m][j]=0;m++;}
            printf("\n");
        }
    }
  }
}
int Hammingdist(char* s1,char* s2,int n){
   int temp =0;
   for(int i=0;i<n;i++){
    if(s1[i]!=s2[i]) temp++;
   }
   return temp;
}
void Test3_7(){
    while(1){
        int m =0;
        int n=0;
        scanf("%d",&m);
        scanf("%d",&n);
        char element[m][n+10];
        int sum[m];
        memset(element,'\0',sizeof(element));
        memset(sum,0,sizeof(sum));
        for(int i=0;i<m;i++){
            scanf("%s",element[i]);
            for(int j=0;j<m;j++){
                sum[i]+=Hammingdist(element[i],element[j],n);
            }
        }
        int minIndex =0;
        for(int k =0;k<m;k++){
            if(sum[minIndex] > sum[k]) minIndex =k;
            else if(sum[minIndex]==sum[k]){
                if(strcmp(element[minIndex],element[k])>0) minIndex =k;
            }
        }
        printf("Minimum Solution %s  Sum:%d \n",element[minIndex],sum[minIndex]);
    }
}
void Test3_8(){
 int maxn =3020;
  int r[maxn];
  int u[maxn];
  int s[maxn];
  int n,m,t,i;
  while(1){
     t =n;
    memset(r,0,sizeof(r));
    memset(u,0,sizeof(u));
    memset(s,0,sizeof(s));
    scanf("%d",&n);
    scanf("%d",&m);
    int cnt =0;
    r[cnt++] =n/m;
    n =n%m;
    while(!u[n]&&n){
        u[n] =cnt;
        s[cnt] =n;
        r[cnt++] =10*n/m;
        n =(10*n)%m;
    }
    printf("%d/%d = %d.",t,m,r[0]);
  for(i=1;i<cnt&&i<=50;++i){
    if(n && s[i]==n) printf("(");
    printf("%d",r[i]);
  }
  if(!n) printf("(0");
  if(cnt>50) printf("...");
  printf(")\n");
  printf("%3d = number of digits in repeating cycle",!n?1:cnt -u[n]);
  }
}
void Test3_9(){

    char s[120];
    char t[60];
    int flag =0;
    memset(s,'\0',sizeof(s));
    memset(t,'\0',sizeof(t));
    scanf("%s",s);
    scanf("%s",t);
   //  printf(" s :%s  t :%s  --",s,t);
    int j=0;
    for(int i=0;i<strlen(s);i++){

        if(s[i]==t[j]) j++;
        if(j==strlen(t)){
            flag =1;
            break;
        }
    }
  //  printf(" j: % d \n",j);
    if(flag ==1) printf(" get it \n");
    else printf("not get it \n");

}

void Test3_10(){
int groups[3][2];
int inputs[6][2];
int divide[6];
int counts =0;
int flag =0;
while(1){
    memset(groups,0,sizeof(groups));
    memset(inputs,0,sizeof(inputs));
    memset(divide,0,sizeof(divide));
    flag =0;
    while(counts<6){
        scanf("%d",&inputs[counts][0]);
        scanf("%d",&inputs[counts][1]);
        counts++;
    }
 //    printf("input end \n");
    counts =0;
    int grp =0;
    for(int i=0;i<6;i++){
        for(int j=i+1;j<6;j++){
            if((divide[i]==0 && divide[j]==0)){
               if(((inputs[i][0]*inputs[i][1])==(inputs[j][0]*inputs[j][1])) &&((inputs[i][0]+inputs[i][1])==(inputs[j][0]+inputs[j][1]))){
              divide[i] =1;
               divide[j]=1;
               groups[grp][0] =i;
               groups[grp][1] =j;
               grp++;
                  }
               }

        }
        if(divide[i]==0) {flag =0;break;}
    }
   // printf(" for end \n");
    if(grp ==3) flag =1;
     if(flag==1) {
       //     printf("flag has be 1 \n");
        if(inputs[groups[0][0]][0] ==inputs[groups[1][0]][0]){
            if(inputs[groups[0][0]][1] ==inputs[groups[2][0]][0] && inputs[groups[1][0]][1]==inputs[groups[2][0]][1])
                flag =1;
            else if(inputs[groups[0][0]][1] ==inputs[groups[2][0]][1] && inputs[groups[1][0]][1]==inputs[groups[2][0]][0])
                flag =1;
            else flag=0;
        }
        else  if(inputs[groups[0][0]][1] ==inputs[groups[1][0]][0]){
            if(inputs[groups[0][0]][0] ==inputs[groups[2][0]][0] && inputs[groups[1][0]][1]==inputs[groups[2][0]][1])
                flag =1;
            else if(inputs[groups[0][0]][0] ==inputs[groups[2][0]][1] && inputs[groups[1][0]][1]==inputs[groups[2][0]][0])
                flag =1;
            else flag=0;
        }
        else  if(inputs[groups[0][0]][0] ==inputs[groups[1][0]][1]){
            if(inputs[groups[0][0]][1] ==inputs[groups[2][0]][0] && inputs[groups[1][0]][0]==inputs[groups[2][0]][1])
                flag =1;
            else if(inputs[groups[0][0]][1] ==inputs[groups[2][0]][1] && inputs[groups[1][0]][0]==inputs[groups[2][0]][0])
                flag =1;
            else flag=0;
        }
        else  if(inputs[groups[0][0]][1] ==inputs[groups[1][0]][1]){
            if(inputs[groups[0][0]][0] ==inputs[groups[2][0]][0] && inputs[groups[1][0]][0]==inputs[groups[2][0]][1])
                flag =1;
            else if(inputs[groups[0][0]][0] ==inputs[groups[2][0]][1] && inputs[groups[1][0]][0]==inputs[groups[2][0]][0])
                flag =1;
            else flag=0;
        }
        else flag =0;
    }
    if(flag ==0) {printf(" IMPOSSIBLE\n");}
    else printf(" POSSIBLE\n");

}
}
int maxf(char *max,char *min){
  int maxvalue =0;
  int l1 =strlen(min);
  int l2 =strlen(max);
  int flag =1;
  //left
  for(int i=0;i<=l1-1;i++){
        flag =1;
    for(int k=l1-1-i,m=0;k<=l1-1,m<=i;k++,m++){
        if((max[m]+min[k]-'0'-'0')>3){
            flag =0;
            break;
        }
    }
    if(flag ==1){
        int update =i+1;
        if(maxvalue <update) maxvalue =update;
    }
  }
  //right
  for(int i=l2-l1;i<=l2-1;i++){
    flag =1;
    for(int k=0,m=i;k<=l2-1-i,m<=l2-1;k++,m++){
        if((max[m]+min[k]-'0'-'0')>3){
            flag =0;
            break;
        }
    }
    if(flag ==1){
        int update =l2-i;
        if(maxvalue <update) maxvalue =update;
    }
  }
  //middle
  for(int i=0;i<=l2-l1;i++){
        flag =1;
    for(int k=0,m=i;k<=l1-1,m<l1-1+i;k++,m++){
        if((max[m]+min[k]-'0'-'0')>3){
            flag =0;
            break;
        }
    }
    if(flag==1){
        int update =l1;
        maxvalue =update;
        break;
    }
  }
  return maxvalue;
}
void  Test3_11(){
   char n1[120];
   char n2[120];
   char max[120];
   char min[120];
   char rev[120];
   int  maxvalue =0;
   memset(n1,'\0',sizeof(n1));
   memset(n2,'\0',sizeof(n2));
   memset(max,'\0',sizeof(max));
   memset(min,'\0',sizeof(min));
   memset(rev,'\0',sizeof(rev));
   scanf("%s",n1);
   scanf("%s",n2);
   if(strlen(n1)>strlen(n2)){
    strcpy(max,n1);
    strcpy(min,n2);
   }else{
    strcpy(max,n2);
    strcpy(min,n1);
   }
   strcpy(rev,min);
   for(int i=0;i<=(strlen(rev)/2);i++){
     char temp= rev[i];
     rev[i] =rev[strlen(rev)-1-i];
     rev[strlen(rev)-1-i] =rev[i];
   }
   int max1 =maxf(max,min);
   int max2 =maxf(max,rev);
   if(max1<max2) maxvalue =max2;
   else maxvalue =max1;
   printf("Minimum Length  is %d : \n",(strlen(max)+strlen(min)-maxvalue));

}
void Test3_12(){
  double M[20][40];
  long long E[20][40];
  //打表
  for(int i=0;i<=9;i++)
  for(int j=1;j<=30;j++){
    double m =1-pow(2,-1-i),e=pow(2,j)-1;
    double t =log10(m) + e*log10(2);
    E[i][j] =t,M[i][j]=pow(10,t-E[i][j]);
  }
  char input[200];
  memset(input,'\0',sizeof(input));
  while(1){
    scanf("%s",input);
    if(strcmp(input,"0e0")==0) break;
    char s1[40];
    char s2[40];
    memset(s1,'\0',sizeof(s1));
    memset(s2,'\0',sizeof(s2));
    sscanf(input,"%[^e]",s1);
    sscanf(input,"%*[^e]e%s",s2);
    double a;
    double b;
    sscanf(s1,"%f",&a);
    sscanf(s2,"%d",&b);
    if(a<1){
        a*=10;
        b-=1;
    }
    for(int i=0;i<=9;i++){
        for(int j=1;j<=30;j++){
            if(b==E[i][j] &&(fabs(a -M[i][j])<1e-4 || fabs(a/10 -M[i][j])<1e-4)){
                printf("%d %d",i,j);
            }
        }
    }

  }
}


#include <stdio.h>
#include <math.h>
void Question2_3(){
  for(int a=1;a<=9;a++)
  for(int b=0;b<=9;b++){
    int n =a*1100+b*11;
    int m =floor(sqrt(n)+0.5);
    if(m*m==n) printf("%d\n",n);
 }
 return ;
}
void Question2_9(){
 int x=0;
 int n=0;
 int min =999;
 int max =-999;
 double s =0;

 while(scanf("%d",&x)==1){
    if(x=='\n') break;
    s +=x;
    if(x<min) min =x;
    if(x>max) max =x;
    n++;
 }
 printf("%d %d %.3f\n",min,max,(double)s/n);
 return;
}
void Question2_10(){
  freopen("data.in","r",stdin);
  freopen("data.out","w",stdout);
  int x =0;
  int n =0;
  int INF =10000000;
  int min =INF;
  int max =-INF;
  double s =0;
  while(scanf("%d",&x)==1){
    s +=x;
    if(x<min) min =x;
    if(x>max) max =x;
    n++;
  }
  printf("%d %d %.3f\n",min,max,(double)s/n);
  return ;
}
void Question2_11(){
  int INF =100000000;
  FILE *fin,*fout;
  fin = fopen("data.in","rb");
  fout =fopen("data.out","wb");
  int x =0;
  int n=0;
  int min =INF;
  int max =-INF;
  double s =0;
  while(fscanf(fin,"%d",&x)==1){
    s +=x;
    if(x<min) min =x;
    if(x>max) max =x;
    n++;
  }
  fprintf(fout,"%d %d %.3f\n",min,max,(double)s/n);
  fclose(fin);
  fclose(fout);
}
void Question2_12(){
 int INF =10000000;
 int x =0;
 int n =0;
 int min =INF;
 int max =-INF;
 double s =0;
 int kase =0;
 while(scanf("%d",&n)==1&&n){

    s =0;
    for(int i=0;i<n;i++){
        scanf("%d",&x);
        s +=x;
        if(x<min) min =x;
        if(x>max) max =x;
    }
    if(kase) printf("\n");
    printf("Case %d: %d %d %.3f\n",++kase,min,max,(double)s/n);
 }
 return ;

}
void Test2_1(){
 for(int i=1;i<=9;i++)
    for(int j=0;j<=9;j++)
      for(int k=0;k<=9;k++){
       int sum =100*i+10*j+k;
       int result =i*i*i +j*j*j+k*k*k;
       if(sum ==result){
         printf(" daffodil find : %d \n",sum);
       }
 }
}
void Test2_2(){
  int a =0;
  int b=0;
  int c =0;
  int num =0;
  int times =0;
  int find =0;
/*  while((scanf("%d",&a)==1)&&(scanf("%d",&b)==1)&&(scanf("%d",&c)==1)){
    for(int i =10;i<=100;i++){
        if(((i%3)==a)&&((i%5)==b)&&(((i%7)==c)))
            {printf("Case %d: %d\n",++times,i);}
    }
  }
  */
  while(1){
    find =0;
    scanf("%d",&a);scanf("%d",&b);scanf("%d",&c);
    printf(" a:%d b:%d c:%d \n",a,b,c);
    for(int i =10;i<=100;i++){
        if(((i%3)==a)&&((i%5)==b)&&(((i%7)==c)))
            {if(times==0){
            printf("Case %d: %d",++times,i);
            }
            else{
                printf("Case %d: %d",++times,i);
            }

             find =1;
               }
    }

   if(find ==0){
    printf("\nCase %d:No answer",++times);
   }
}
}
void Test2_3(){
   int n =0;
   while(scanf("%d",&n)&&(n>0)&&(n<=20)){
     char arr[n][2*n-1];
     for(int i=0;i<n;i++){
        for(int j=0;j<2*n-1;j++)
            arr[i][j]=' ';
     }
     for(int i=0;i<n;i++){
        for(int j=i;j<2*n-1-i;j++){
            arr[i][j]='*';
        }
     }
     for(int i=0;i<n;i++){
        for(int j=0;j<2*n-1;j++){
            printf("%c",arr[i][j]);
        }
        printf("\n");
            }

   }
   return;
}
void Test2_4(){
 int n=0;
 int m=0;
 double temp =0.0;
 int times =0;
 int nums =0;
 while(1){
    while((scanf("%d",&n)==1)&&(scanf("%d",&m)==1)){
        if(n==0 & m==0) {return;}
        else{
            printf("n: %d  m: %d\n",n,m);
            if((n<m) &&(m<1000000)){
                for(int i=n;i<=m;i++){
                    temp = temp + ((1.0)/((i*1.0)*(i*1.0)));
                }
                printf("Case %d: %.5f\n",++times,temp);

            }
        }

    }

 }
}
void Test2_5(){
  int a =0;
  int b=0;
  int c =0;
  int times =0;
  while((scanf("%d",&a)==1)&&(scanf("%d",&b)==1)&&(scanf("%d",&c)==1)){
    double result =0.0;
    if(a==0&&b==0&c==0) return;
    if((0<a)&&(a<=1000000)&&(0<b)&&(b<=1000000)&&(0<c)&&(c<=100)){
        result =(1.0*a)/(1.0*b);

        printf("Case %d: %.*f\n",++times,c,result);
    }
  }
}

void Test2_6(){
 int result[9]={0,0};
 for(int i=123;i<=329;i++){
    int a =i;
    int b=i*2;
    int c =i*3;
    result[(a%10)]=result[(a/10)%10]=result[a/100]=1;
    result[(b%10)]=result[(b/10)%10]=result[b/100]=1;
    result[(c%10)]=result[(c/10)%10]=result[c/100]=1;
    int sum =0;
    for(int j=0;j<9;j++){
        sum +=result[j];
        result[j]=0;
    }
    if(sum ==9){
        printf("%d %d %d\n",a,b,c);
    }
 }
}
void Test2_7(){
  double i;
  for(i=0;i!=10;i+=0.1)
    printf("%.1f\n",i);
  return 0;
}


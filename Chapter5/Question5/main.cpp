#include<iostream>
#include<cstring>
#include<fstream>
#include<string>
#include<stdio.h>
#include<stdlib.h>
#include<vector>
#include<cmath>
#include<set>
#include<queue>
#include<map>
#include<algorithm>
#include<sstream>
using namespace std;
void printspace(int num){
  while(num--){
    cout<<" ";
  }
}

void Question5_1(){
 /* C语言重定向读取字符串*/
/* freopen("input.txt","r",stdin);
 freopen("output.txt","w",stdout);
 int size =1024;
 char *line =(char*)malloc(size);
 while(NULL!=gets(line)){
    printf("%s \n",line);
 }
 free(line);*/
 char line[200];
 int ranks[1000];
 vector<string> content[1000];
 char word[80];
 memset(line,'\0',sizeof(line));
 memset(ranks,0,sizeof(ranks));
 memset(content,0,sizeof(content));
 ifstream fin("input.txt",ios::in);
 ofstream fout("output.txt",ios::trunc);
 streambuf* cinbackup;
 streambuf* coutbackup;
 cinbackup =cin.rdbuf(fin.rdbuf());
 coutbackup=cout.rdbuf(fout.rdbuf());
 int index =0;
 int rankse =0;
 char seps[] =" \n";
 while(NULL!=fin.getline(line,200)){
    char* temp =new char[80];
    rankse =0;
    temp = strtok(line,seps);
    while(temp!=NULL){
       // cout<<temp<<" "<<strlen(temp);
        if(ranks[rankse++]<strlen(temp)) ranks[rankse-1]=strlen(temp);
        content[index].push_back(string(temp));
     //   cout<< content[index][rankse-1]<<" ";
       // cout<<temp<<" ";
        temp = strtok(NULL,seps);
    }
    index++;
   // cout<<endl;
 }
 //cout<<" index is "<<index<<endl;
 for(int i=0;i<index;i++){
    for(int j=0;j<content[i].size();j++){
        string a1 =content[i][j];
        cout<<content[i][j];
        printspace(ranks[j]-a1.length()+1);
    }
    cout<<endl;
 }
 fin.close();
 fout.close();
}
int nums2int(int* arr,int n){
  int sum =0;
  for(int i=0;i<n;i++){
    sum =sum*10+arr[i];
  }
  return sum;
}
void numsDucci(int *arr,int n){
  int temp[n];
  memset(temp,0,sizeof(temp));
  for(int i =0;i<n;i++){
    temp[i] =abs((arr[i%n]-arr[(i+1)%n]));
  }
  for(int i=0;i<n;i++){
    arr[i] =temp[i];
  }
}
void Question5_2(){
  int times =0;
  int n =0;
  scanf(" %d ",&times);
  while(times){
    scanf("%d",&n);
    int num[n];
    memset(num,0,sizeof(num));
    for(int i=0;i<n;i++){
        scanf("%d",&num[i]);
     //   printf("index:%d  value : %d \n",i,num[i]);
    }
   // printf("ok\n");
    set<int> dict;
    dict.clear();
    int cnt =1000;
    while(cnt){
        int sum =nums2int(num,n);
        if(sum ==0) {
            cout<<"ZERO"<<endl;
            break;
        }
        else if(!dict.count(sum)){
            dict.insert(sum);
            numsDucci(num,n);
        }else{
        cout<<"LOOP"<<endl;
        break;
        }
        cnt--;
    }
    times--;
  }

}
void Question5_3(){
  queue<int> card;
 // card.clear();
  int n;
  while(scanf("%d",&n)!=1);
  for(int i=1;i<=n;i++){
    card.push(i);
  }
  while(card.size()>=2){
    card.pop();
    int temp =card.front();
    card.pop();
    card.push(temp);

  }
  cout<<"remained card : "<<card.front();
}
void Question5_4(){
int n =0;
while((scanf("%d",&n)==1)&(n!=0)){
    map<int,int> student;
    student.clear();
    for(int i=0;i<n;i++){
        int from,to;
        scanf("%d %d",&from,&to);
        if(!student.count(from*10000+to)){
            student[from*10000+to] =1;
            if(!student.count(to*10000+from)){
                student[to*10000+from]=-1;
            }else{
                student[to*10000+from]--;
            }
        }else{
           student[from*10000+to]++;
            if(!student.count(to*10000+from)){
                student[to*10000+from]=-1;
            }else{
                student[to*10000+from]--;
            }
        }
    }
    map<int,int>::iterator it;
    it =student.begin();
    while(it!=student.end()){
       // printf(" <%d  ,%d>\n",it->first/10000,it->first%10000);
        if(it->second!=0){
            printf("NO\n");
            break;
        }
        it++;
    }
   if(it==student.end()) printf("YES\n");
}
}
void Question5_5(){
   char dict[40][100];
   memset(dict,'\0',sizeof(dict));
   char temp[100];
   memset(temp,'\0',sizeof(temp));
   int index =0;
   set<string> has;
   set<string> combine;
   while(NULL!=cin.getline(temp,100)){
    strcpy(dict[index++],temp);
    string a =temp;
    has.insert(a);
   }


  /* for(int i=0;i<index;i++){
    string a1;
    //a1 =dict[index];这样的方式不能将字符串数组变成字符串
   // sscanf(dict[index],"%s",a1);//必须是完整字符串才行，后面还带有许多‘\0’这样不行
    cout<<"--"<<a1<<endl;
    has.insert(a1);
   }
   */
 //  printf("********\n");
   /*
   for(int i=0;i<index;i++){
     printf("%s\n",dict[i]);
   }
   */


   for(int i=0;i<index-1;i++){
    for(int j=i+1;j<index;j++){
        string a2 =dict[i];
        string a3 =dict[j];
        string a4 =a2+a3;
        string a5 =a3+a2;
        //printf("%s %s %s %s \n",a2,a3,a4,a5);
        // cout<<a2<<" "<<a3<<" "<<a4<<" "<<a5<<endl;
       // cout<<has.count(a4)<<"  "<<has.count(a5)<<endl;
        if(has.count(a4)!=0) {combine.insert(a4);}
        if(has.count(a5)!=0) {combine.insert(a5);}
    }

   }

   set<string>::iterator it;
   for(it =combine.begin();it!=combine.end();it++){
    cout<<*(it)<<endl;
   }



}
void Question5_6(){
  int cases =0;
  int eachnum =0;
  set<pair<int,int> > dict;
  double middle =0;
  int x,y;
  scanf("%d",&cases);
  while(cases>0){
    scanf("%d",&eachnum);
    dict.clear();
    middle =0;
    for(int i=0;i<eachnum;i++){
        scanf("%d %d",&x,&y);
        middle=middle+x;
        dict.insert(make_pair(x,y));
        }
        middle =middle/eachnum;
        printf("%f \n",middle);
     set<pair<int,int> >::iterator it;
     it =dict.begin();
     while(it!=dict.end()){
        pair<int,int> temp =*it;
        int xother =floor(2*middle -temp.first+0.002);//保证是整数
        int yother =temp.second;
        if(dict.count(make_pair(xother,yother))==0){
            cout<<"NO"<<endl;
            break;
        }
        it++;
     }
     if(it==dict.end()) cout<<"YES"<<endl;
     cases--;
  }
}
void Question5_7(){
 queue<int> print;
 priority_queue<int> pq;
 int cases;
 int nums;
 int pos;
 //scanf("%d",&cases);
 while(cases>0){
    print =queue<int>();
    pq    =priority_queue<int>();
    nums =0;
    pos =0;
    scanf("%d %d",&nums,&pos);
   // printf("nums:%d  pos:%d\n",nums,pos);
    int arrs[nums];
    memset(arrs,0,sizeof(arrs));
    for(int i=0;i<nums;i++){
        int a;
        while(scanf("%d",&a)!=1);
       // printf(" index:%d  priority:%d\n",i,a);
        arrs[i]=a;
        print.push(i);
        pq.push(a);
    }
    int time =0;
    while(1){
        int test =print.front();
        print.pop();
        if(arrs[test]==pq.top()){
            time++;
            pq.pop();
            if(test==pos) break;
        }else{
          print.push(test);
        }
    }
    printf("%d\n",time);
    cases--;
 }
}
struct Book{
  string title;
  string authors;
};
bool compare(Book a,Book b){
 if(strcmp(a.authors.c_str(),b.authors.c_str())<0) return 1;
 else if(strcmp(a.authors.c_str(),b.authors.c_str())==0){
    if(strcmp(a.title.c_str(),b.title.c_str())) return 1;
    else return 0;
 }else return 0;
}
void Question5_8(){
  ifstream fin("library.txt");
  cin.rdbuf(fin.rdbuf());
  //vector 删除元素
  vector<Book> inshelve;
  vector<Book> returnshelve;
  map<string,Book> dict;
  string bookname;
  string authors;
  string line;
  //读取图书
  while(getline(cin,line)){
    if(strcmp(line.c_str(),"END")==0) break;
     int k =line.find(" by ");
     bookname =line.substr(0,k);
     authors=line.substr(k+4);
 //    cout<<"title: "<<bookname<<" authors: "<<authors<<endl;
     Book book;
     book.authors=authors;
     book.title  =bookname;
     inshelve.push_back(book);
     dict[bookname] =book;
  }
  /*for(int i=0;i<inshelve.size();i++){
    cout<<" "<<inshelve[i].authors<<" "<<inshelve[i].title<<endl;
  }*/
  //执行借书还书
  while(getline(cin,line)){
    if(strcmp(line.c_str(),"END")==0) break;
    if(strcmp(line.c_str(),"SHELVE")!=0){
    int k =line.find("\"");
    string cmd =line.substr(0,k-1);
    Book   booksel;
    bookname =line.substr(k);
    cout<<cmd<<" "<<bookname<<endl;
    //删除
    if(strcmp(cmd.c_str(),"BORROW")==0){
       cout<<"before borrow"<<inshelve.size()<<endl;
        booksel =dict[bookname];
        int length =inshelve.size();
        for(int i=0;i<length;i++){
            if(strcmp(inshelve[i].title.c_str(),bookname.c_str())==0){
                inshelve.erase(inshelve.begin() +i);
                break;
            }
        }
        cout<<"after borrow"<<inshelve.size()<<endl;
    }
    else if(strcmp(cmd.c_str(),"RETURN")==0){
        returnshelve.push_back(dict[bookname]);
        cout<<returnshelve.size()<<endl;
    }


    }else{
        sort(returnshelve.begin(),returnshelve.end(),compare);
        //插入将要归还的书
        cout<<" before shelve: "<<inshelve.size()<<endl;
        for(int i=0;i<returnshelve.size();i++){
            inshelve.push_back(returnshelve[i]);
        }
        cout<<" after shelve: "<<inshelve.size()<<endl;
        sort( inshelve.begin(),inshelve.end(),compare);
        int index =0;
        for(int i=0;i<inshelve.size();i++){
            if(strcmp(inshelve[i].title.c_str(),returnshelve[index].title.c_str())==0){
                if(i==0){
                    cout<<"Put"<<" "<<returnshelve[index].title<<" first"<<endl;
                    }
                    else {
                        cout<<"Put"<<" "<<returnshelve[index].title<<" after "<<inshelve[i-1].title<<endl;
                    }
                    index++;
            }
            if(index ==returnshelve.size()) break;
        }


        cout<<"END"<<endl;
        break;

    }



  }


}
 void Question5_15(){
   int fibon[100000];
   memset(fibon,0,sizeof(fibon));
   string input;
   cin>>input;
   //input ="12";
   cout<<input<<endl;
   fibon[0]=1;
   fibon[1]=1;
   int i=2;
   int length =input.length();
   if(input=="1") {printf("index : 1 \n");return;}
   while(i<100000){
    fibon[i] =fibon[i-1]+fibon[i-2];
    stringstream stream;
   stream<<fibon[i];
    string temp ;
    stream>>temp;
    cout<<temp<<endl;
    if(temp.length()<length) {i++;continue;}
    else{
        string cmp;
        cmp =temp.substr(0,length);
       // cout<<" cmp "<<cmp<<endl;
        if(strcmp(cmp.c_str(),input.c_str())==0){
            printf("index : %d \n",i);
            break;
        }else i++;
    }

   }
 }
int arrlist[50][10];
/*
int dp(int i,int k,int n,int ability[],int d){
  int ans =arrlist[i][k-1];
  cout<<"before"<<ans<<endl;
  if(ans!=0)  return ans;
  ans = 1;
  cout<<" after"<<ability[i]<<endl;
  for(int j=0;j<i;j++){
    if((i-j)<d) ans =max(ans,dp(j,k-1,n,ability,d)*ability[i]);
    cout<<"["<<i<<"]"<<"["<<k<<"]"<<"---"<<ans<<endl;
  }
  arrlist[i][k-1]=ans;
  return ans;

}
*/
int dp(int i,int k,int n,int ability[],int d){
 int ans=arrlist[i][k];
 if(ans!=0) return ans;
 if(k==0) return 1;
 ans =1;
 for(int j=i+1;j<i+d+1 && j<=n-k+1 && k>0;j++){
    ans = max(ans,dp(j,k-1,n,ability,d)*ability[i]);
    cout<<"["<<i<<"]"<<"["<<k<<"]"<<" "<<ans<<endl;
 }
 arrlist[i][k] =ans;
 cout<<"["<<i<<"]"<<"["<<k<<"]"<<" "<<ans<<endl;
 return ans;
}
int main(){
  //Question5_1();
  //  Question5_2();
 //  Question5_3();
//  Question5_4();
 //   Question5_5();
 //   Question5_6();
 // Question5_7();
  //  Question5_8();
  //  Question5_15();
  int n,k,d;
  cin>>n;
  cout<<" n: "<<n<<endl;
  int ability[n];
  memset(ability,0,sizeof(ability));
  for(int i=0;i<n;i++){
    cin>>ability[i];
    cout<<" ability["<<i<<"]"<<" "<<ability[i]<<endl;
  }
  cin>>k>>d;
  cout<<" k "<<k<<" d"<<d<<endl;
  memset(arrlist,0,sizeof(arrlist));

  int max =-999999;
  for(int i=0;i<n+1-k;i++){
    int temp =dp(i,k,n,ability,d);
    if(max<temp) max =temp;
  }
/*  for(int i=0;i<n;i++){
    arrlist[i][k-1] =1;
  }
  */
  for(int i=0;i<n;i++){
    for(int j=1;j<=k;j++){
        cout<<" ["<<i<<"]"<<"["<<j<<"] "<<arrlist[i][j];
    }
    cout<<endl;
  }
  cout<<"MAX : "<<max<<endl;


}


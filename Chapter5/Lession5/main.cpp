#include<cstdio>
#include<algorithm>
#include<string>
#include<iostream>
#include<set>
#include<sstream>
#include<map>
#include<cctype>
#include<vector>
#include<algorithm>
#include<cstring>
#define  ALL(x) x.begin(),x.end()
#define  INS(x) inserter(x,x.begin())
using namespace std;
const int maxn =30;
int n;
typedef set<int> Set;
map<Set,int>IDcache;
vector<Set> Setcache;
vector<int> pile[maxn];
set<string> dict;
map<string,int> cnt;
const int maxt =1000+10;
typedef long long LL;
const int coeff[3]={2,3,5};
const int maxcol =60;
string filenames[maxn];
void Test5_9(){
 //¶ÁÈ¡ÐÐ×Ö·û´®²ð½â
 char line[1000];
 char word[100];
 map<string,int> dict;
 map<int ,int> scan;
 int n,m;
 scanf(" %d %d ",&n,&m);
 int arrs[n][m];
 memset(arrs,0,sizeof(arrs));
 int index =0;
 int k =0;
 int cn =0;
 for(int i=0;i<n;i++){
    memset(line,'\0',sizeof(line));
    cin.getline(line,1000);
    //printf(" %d : %s \n",i,line);
    int j =0;
    memset(word,'\0',sizeof(word));
    cn =0;
    int loop =1;
    while(cn<m){
        if(line[j] ==',' || j==strlen(line)-1){
            if(j ==strlen(line)-1){
                word[k++] =line[j++];
            }
            string a1;
            a1 =word;
          //  cout<<a1<<" ";
            if(!dict.count(a1)){
                dict[a1] =index++;
            }
            j++;
            arrs[i][cn++] =dict[a1];
            memset(word,'\0',sizeof(word));
            k=0;
            if(j==strlen(line)) {loop =0;break;}

        }else{
             word[k++]=line[j++];
        }

     //cout<<endl;
 }


}
/*
 for(int i =0;i<n;i++){
    for(int j =0;j<m;j++){
        cout<<arrs[i][j]<<" ";
    }
    cout<<endl;
 }*/
 int c1,c2,r;
 int ok =0;
 for(int c1 =0;c1<m-1;c1++){

    for(int c2=c1+1;c2<m;c2++){
     scan.clear();
     int nums =0;
     for(int r=0;r<n;r++){
        int sumindex = arrs[r][c1]*10000+arrs[r][c2];
        if(!scan.count(sumindex)){
            scan[sumindex] =r;
        }
        else{
            if(ok==0){
                printf("NO\n");
                ok=1;
            }
            printf("%d %d\n",scan[sumindex]+1,r+1);
            printf("%d %d\n",c1+1,c2+1);
        }
     }
    }
 }
 if(ok==0) printf("YES\n");

}
/*
void print(const string& s,int len,char extra){
   cout<<s;
   for(int i=0;i<len-s.length();i++)
    cout<<extra;
}
*/
/*
void Test5_8(){
 int n;
 while(cin>>n){
    int M =0;
    for(int i=0;i<n;i++){
        cin>>filenames[i];
        M =max(M,(int)filenames[i].length());
    }
    int cols =(maxcol -M)/(M+2) +1,rows =(n-1)/cols +1;
    print("",60,'-');
    cout<<"\n";
    sort(filenames,filenames+n);
    for(int r =0;r<rows;r++){
        for(int c=0;c<cols;c++){
            int idx =c*rows +r;
            if(idx < n) print(filenames[idx],c==cols-1?M:M+2,' ');
        }
        cout<<"\n";
    }
 }
 return;
}
void Test5_7(){
  priority_queue<LL,vector<LL>,greater<LL>> pq;
  set<LL> s;
  pq.push(1);
  s.insert(1);
  for(int i=1;;i++){
    LL x =pq.top();pq.pop();
    if(i==1500){
        cout<<"The 1500'th ugly number is"<<x<<".\n";
        break;
    }
    for(int j=0;j<3;j++){
        LL x2 =x*coeff[j];
        if(!s.count(x2)){
            s.insert(x2);
            pq.push(x2);
        }
    }
  }
  return;
}
void Test5_6(){
   int t,kase =0;
   while(scanf("%d",&t)==1 & t){
    printf("Scenario #%d \n",++kase);
    map<int,int> team;
    for(int i=0;i<t;i++){
        int n,x;
        scanf("%d",&n);
        while(n--){
            scanf("%d",&x);
            team[x] =i;
        }
    }
     queue<int> q,q2[maxt];
     for(;;){
        int x;
        char cmd[10];
        scanf("%s",cmd);
        if(cmd[0]=='S') break;
        else if(cmd[0]=='D'){
            int t =q.front();
            printf("%d\n",q2[t].front());
            q2[t].pop();
            if(q2[t].empty()) q.pop();
        }
        else if(cmd[0]=='E'){
            scanf("%d",&x);
            int t =team[x];
            if(q2[t].empty()) q.push(t);
            q2[t].push(x);
        }
     }
     print("\n");
   }
   return;
}
int ID(Set x){
 if(IDcache.count(x)) return IDcache[x];
 Setcache.push_back(x);
 return IDcache[x]=Setcache.size()-1;
}
void Test5_5(){
  stack<int> s;
  int n;
  cin>>n;
  for(int i=0;i<n;i++){
    string op;
    cin>>op;
    if(op[0]=='P') s.push(ID(Set()));
    else if(op[0]=='D') s.push(s.top());
    else{
        Set x1 =Setcache[s.top()];s.pop();
        Set x2 =Setcache[s.top()];s.pop();
        Set x;
        if(op[0]=='U') set_union(ALL(x1),ALL(x2),INS(x));
        if(op[0]=='I') set_intersection(ALL(x1),ALL(x2),INS(x));
        if(op[0]=='A') {x =x2;x.insert(ID(x1));}
        s.push(ID(x));
    }
    cout<<Setcache[s.top()].size()<<endl;
  }
}

void Test5_3(){
  string s,buf;
  while(cin>>s){
    for(int i=0;i<s.length();i++)
        if(isalpha(s[i])) s[i] =tolower(s[i]);else s[i]=' ';
    stringstream ss(s);
    while(ss>>buf) dict.insert(buf);
  }
  for(set<string>::iterator it =dict.begin();it!=dict.end();++it)
    cout<<*it<<"\n";
  return;
}
void find_block(int a,int& p,int& h){
  for(p=0;p<n;p++)
    for(h=0;h<pile[p].size();h++)
    if(pile[p][h]==a) return;
}
void clear_above(int p,int h){
  for(int i=h+1;i<pile[p].size();i++){
    int b =pile[p][i];
    pile[b].push_back(b);
  }
  pile[p].resize(h+1);
}*/
/*

void pile_onto(int p,int h,int p2){
 for(int i=h;i<pile[p].size();i++)
    pile[p2].push_back(pile[p][i]);
 pile[p].resize(h);
}
*/
/*

void print(){
 for(int i=0;i<n;i++){
    printf("%d:",i);
    for(int j=0;j<pile[i].size();j++) printf(" %d",pile[i][j]);
    printf("\n");
 }
}
*/
/*
void Test5_2(){
  int a,b;
  cin>>n;
  string s1,s2;
  for(int i=0;i<n;i++) pile[i].push_back(i);
  while(cin>>s1>>a>>s2>>b){
    int pa,pb,ha,hb;
    find_block(a,pa,ha);
    find_block(b,pb,hb);
    if(pa==pb) continue;
    if(s2 =="onto") clear_above(pb,hb);
    if(s1 =="move") clear_above(pa,ha);
    pile_onto(pa,ha,pb);

  }
  print();
  return;
}*/
/*
void Test5_1(){
  int n,q,x,a[maxn],kase =0;
  while(scanf("%d %d",&n,&q)==2 && n){
    printf("CASE# %d:\n",++kase);
    for(int i=0;i<n;i++) scanf("%d",&a[i]);
    sort(a,a+n);
    while(q--){
        scanf("%d",&x);
        int p =lower_bound(a,a+n,x)-a;
        if(a[p]==x) printf("%d found at %d \n",x,p+1);
        else printf("%d not found\n",x);
    }
  }
  return;
}*/
 /*int main(){
     Test5_9();
 return 0;
 }*/

#include <iostream>
#include<deque>
#include<cstring>
#include<queue>
#include<map>
#include<fstream>
#include<sstream>
#include<cstdlib>
#include<stack>
#include<set>
using namespace std;
map<string,string> asi;
void split(const string& s, vector<string>& v,const string& c){
   string::size_type pos1,pos2;
   pos2 =s.find(c);
   pos1 =0;
   while(string::npos != pos2){
    v.push_back(s.substr(pos1,pos2-pos1));
    pos1 =pos2 +c.size();
    pos2 =s.find(c,pos1);
   }
   if(pos1!=s.length())
    v.push_back(s.substr(pos1));
}
int cmdrun(string cmd,int index){
    string word;
    vector<string> res;
    stringstream ss;
    ss<<cmd;
    while(ss>>word){
        if(word.empty()) break;
        res.push_back(word);
    }
    if(strcmp(res[0].c_str(),"lock")==0) return 3;
    else if(strcmp(res[0].c_str(),"unlock")==0) return 4;
    else if(strcmp(res[0].c_str(),"end")==0) return 5;
    else if(strcmp(res[0].c_str(),"print")==0){
        cout<<index<<": "<<asi[res[1]]<<endl;
        return 2;
    }
    else{
        asi[res[0]]=res[2];
        return 1;
    }
    return 0;
}
void Test6_1(){
  queue<string> q[10];
  int timeused[10];
  int cmdtime[6];
  memset(cmdtime,0,sizeof(cmdtime));
  memset(timeused,0,sizeof(timeused));
  deque< queue<string> > sim;
  queue< queue<string> > block;
  int index =0;
  ifstream fin("data.txt");
  cin.rdbuf(fin.rdbuf());
  string line;
  string time;
  getline(cin,time);
  int nums;
  sscanf(time.c_str(),"%d %d %d %d %d %d %d",&nums,&cmdtime[1],&cmdtime[2],&cmdtime[3],&cmdtime[4],&cmdtime[5],&cmdtime[0]);
  //cout<<nums<<" "<<cmdtime[1]<<" "<<cmdtime[2]<<" "<<cmdtime[3]<<" "<<cmdtime[4]<<" "<<cmdtime[5]<<" "<<cmdtime[0]<<endl;
  while(getline(cin,line)){
    if(strcmp(line.c_str(),"end")==0){
        q[index].push(line);
         string temp;
         stringstream ss;
         ss<<(index+1);
         ss>>temp;
        q[index].push(temp);
        index++;
    }
    else q[index].push(line);
  }
 /* for(int i=0;i<index;){
  //  cout<<"queue "<<i<<": "<<endl;
    while(q[i].size()>0){

    string temp =q[i].front();
    cout<<temp<<endl;
    int num =cmdrun(temp,i);
    cout<<" return "<<num<<endl;
    q[i].pop();
    }
    i++;
 //   cout<<"-----------------------"<<endl;
  }
 */
  for(int i=0;i<index;i++){
    sim.push_back(q[i]);
  }
  int islock =0;
  while(sim.size()>0 || block.size()>0){
    if(sim.size()>0){
        queue<string> first =sim.front();
        string cmdline =first.front();
        int ind =atoi((first.back()).c_str());
        //cout<<"ind "<<ind<<endl;
        int retval =cmdrun(cmdline,ind);
        if(timeused[ind]>0){
            timeused[ind] =timeused[ind] -cmdtime[0];
        }else{
           timeused[ind]=cmdtime[retval];
           timeused[ind]=timeused[ind] -cmdtime[0];
        }
        // 为什么一定要这样做才行？
       // ind =0;

        //cout<<" retrun "<<retval<<endl;

        if(cmdline.compare("lock")==0) {
               // cout<<" lock"<<endl;
            if(islock ==0){
               // cout<<" is lock"<<endl;
                islock =ind;
               // cout<<" "<<islock<<endl;
                if(timeused[ind]==0) first.pop();
                if(first.size()<=1) sim.pop_front();
                else {sim.pop_front();sim.push_back(first);}
                continue;
            }else{
            sim.pop_front();
            block.push(first);
            continue;
            }
        }
        else if(cmdline.compare("unlock")==0){
            islock =0;
            if(timeused[ind]==0) first.pop();
            //cout<<" unlock"<<endl;
            if(first.size()<=1) sim.pop_front();
            else {sim.pop_front();sim.push_back(first);}
            if(block.size()==0) continue;
            queue<string> blockfirst =block.front();
            sim.push_front(blockfirst);
            block.pop();
            continue;

        }
        else if(cmdline.compare("end")==0){
            if(timeused[ind]==0) first.pop();
           // cout<<" in end"<<endl;
            sim.pop_front();
        }
        else{
        if(timeused[ind]==0)first.pop();
       // cout<<" in pop "<<endl;
        if(first.size()<=1) sim.pop_front();
        else {sim.pop_front();sim.push_back(first);}
        }
        //ind =0;

    }
    else{
        queue<string> blockback =block.front();
        sim.push_back(blockback);
        block.pop();
    }
    if(sim.size()==0 && block.size()==0) break;
  }


}
void Test6_2(){
 int maxn =1000+10;
 int n,target[maxn];
 while(scanf("%d",&n)==1 && n){
    while(1){
    stack<int> s;
    int A =1,B=1;
    scanf("%d",&target[1]);
    if(target[1]==0) break;
    for(int i=2;i<=n;i++)
        scanf("%d",&target[i]);
    int ok=1;
    while(B<=n){
        if(A==target[B]){A++;B++;}
        else if(!s.empty() && s.top()==target[B]){s.pop();B++;}
        else if(A<=n) s.push(A++);
        else{ok =0;break;}
    }
    printf("%s\n",ok?"Yes":"No");
 }
 printf("\n");
 }
 return;
}
struct matrix{
 int r;
 int c;
};
int mul(matrix a,matrix b,matrix& result){
   // cout<<" a r"<<a.r<<" c"<<a.c<<endl;
   // cout<<" b r"<<b.r<<" c"<<b.c<<endl;
   if(a.c!=b.r) return -1;
   else{
    result.r =a.r;
    result.c =b.c;
   }
   return (a.r) *(a.c)*(b.c);
}
void matrixInit(matrix &a,int r,int c){
  a.r =r;
  a.c =c;
  return;
}
map<string,matrix> dict;
int matrixstring(string line,stack<string>& s){
  int n =line.length();
  int i =0;
  int sum =0;
  while(i<n || s.size()>1){
        //cout<<line[i]<<" *"<<endl;
    while(line.substr(i,1)!=")"&& i<n){//内循环中边界条件不可少，不要认为外循环有了这里就可以省略
      //  cout<<" substr "<<line[i]<<" "<<line.substr(i,1)<<endl;
        s.push(line.substr(i,1));
       // string str =s.top();
       // cout<<" top is "<<str<<endl;
        i++;
    }
    i++;
        if(s.size()>=2){
        string val2 =s.top();
        s.pop();
        string val1=s.top();
        s.pop();
      //  cout<<dict[val1].r<<" "<<dict[val1].c<<" "<<" "<<val1<<endl;
        matrix newmatrix;
        int temp =mul(dict[val1],dict[val2],newmatrix);
        //cout <<"temp "<<temp<<endl;
        if(temp==-1){
            cout<<"error"<<endl;
            return -1;
        }
        else sum =sum +temp;
        s.pop();
        string newstr =val1+val2;
       // cout<<" "<<newstr<<endl;
        dict[newstr] =newmatrix;
        s.push(newstr);

        }



  }
  return sum;
}
void Test6_3(){
  ifstream fin("matrix.txt");
  cin.rdbuf(fin.rdbuf());
  int n =0;
  string line;
  int rtemp;
  int ctemp;
  char name[5];
  memset(name,'\0',sizeof(name));
  string nametemp;
  getline(cin,line);
  //把回车读走
  sscanf(line.c_str(),"%d",&n);
 // cout<<" "<<n<<endl;

  for(int i=0;i<n;i++){
    getline(cin,line);
   // cout<<"*"<<line<<endl;
    sscanf(line.c_str(),"%s %d %d",name,&rtemp,&ctemp);
   // cout<<name<<" "<<rtemp<<" "<<ctemp<<endl;
    nametemp =string(name);
    matrix newmatrix;
    newmatrix.r =rtemp;
    newmatrix.c =ctemp;
    dict[nametemp] =newmatrix;
  }
 /* map<string,matrix>::iterator it;
  it =dict.begin();
  while(it!=dict.end()){
    cout<<it->first<<" "<<it->second.r<<" "<<it->second.c<<endl;
    it++;
  }
  */
  stack<string> s;
  while(getline(cin,line)){
    if(line =="") break;
    int sum =0;
    //cout<<line<<endl;
    while(s.size()>0) s.pop();
    if(line.length() ==1){
        cout<<"0"<<endl;
        continue;
    }
    else{
        int res =matrixstring(line,s);
        //int res =0;
        if(res>0){
            cout<<res<<endl;
        }
    }

  }
}
void Test6_4(){
  int maxn =100000+5;
  int last,cur,next[maxn];
  char s[maxn];
  while(scanf("%s",s+1)==1){
    int n =strlen(s+1);
    last =cur =0;
    next[0] =0;
    for(int i=1;i<=n;i++){
        char ch =s[i];
        if(ch=='[') cur =0;
        else if(ch==']') cur =last;
        else{
            next[i] = next[cur];
            next[cur] =i;
            if(cur ==last) last =i;
            cur =i;
        }
    }
    for(int i =next[0];i!=0;i=next[i])
        printf("%c",s[i]);
    printf("\n");
  }
  return;
}
/*
int left[5000],right[5000];
void link(int L,int R){
 int right[L]=R;
 int left[R] =L;
}

void Test6_5(){
  int maxn =10000+5;
 // int left[maxn],right[maxn];
  int m,kase =0;
  while(scanf("%d%d",&n,&m)==2){
    for(int i=1;i<=n;i++){
        left[i]=i-1;
        right[i] =(i+1)%(n+1);
    }
    right[0] =1;left[0]=n;
    int op,X,Y,inv =0;
    while(m--){
        scanf("%d",&op);
        if(op == 4) inv =!inv;
        else{
            scanf("%d%d",&X,&Y);
            if(op==3 && right[Y]==X) swap(X,Y);
            if(op!=3 && inv ) op =3-op;
            if(op ==1 && X==left[Y]) continue;
            if(op ==2 && X==right[Y]) continue;
            int LX =left[X],RX=right[X],LY =left[Y],RY=right[Y];
            if(op==1){
                link(LX,RX);link(LY,X);link(X,Y);
            }else if(op==2){
                link(LX,RX);link(Y,X);link(X,RY);
            }else if(op==3){
                if(right[X]==Y){link(LX,Y);link(Y,X);link(X,RY);}
                else {link(LX,Y);link(Y,RX);link(LY,X);link(X,RY);}
            }
        }
    }
    int b =0;
    long long ans =0;
    for(int i=1;i<=n;i++){
        b =right[b];
        if(i%2 ==1) ans +=b;
    }
    if(inv && n%2==0) ans =(long long)(n*(n+1)/2 -ans);
    printf("Case %d: %lld\n",++kase,ans);
  }
  return;
}*/
void Test6_6_1(){
   int maxd =20;
   int s[1<<maxd];
   int D,I;
   while(scanf("%d%d",&D,&I)==2){
    memset(s,0,sizeof(s));
    int k,n=(1<<D)-1;
    for(int i=0;i<I;i++){
        k =1;
        for(;;){
            s[k] =!s[k];
            k =s[k]?k*2:k*2+1;
            if(k>n) break;
        }
    }
    printf("%d\n",k/2);
   }
   return;
}
void Test6_6_2(){
   int D,I;
   int k =1;
   for(int i=0;i<D-1;i++){
    if(I%2){k =k*2;I=(I+1)/2;}
    else{ k=k*2+1;I/=2;}
    printf("%d\n",k);
   }
}
void Test01(){
 set<string> dict;
 stringstream ss;
 string line;
 string word;
 while(getline(cin,line)){
    cout<<line;
    ss<<line;
    while(ss>>word){
        cout<<word<<endl;
        dict.insert(word);
    }
 ss.clear();
 }
 cout<<dict.size()<<endl;
 }
int main()
{
  //   Test6_1();
 // Test6_2();
 //   Test6_3();
 //Test6_4();
 //  Test6_6_1();
   Test01();
    return 0;
}

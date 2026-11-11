#include<bits/stdc++.h>
using namespace std;
bitset<100>vis;
int genres[100];
int genn;
void gen(const int&n,const int&k){
    random_device rd;
    mt19937 getrd(rd());
    for(int i=1;i<=n;++i){
        vis[i]=0;
    }
    genn=0;
    int x;
    while(genn<k){
        x=getrd()%n+1;
        if(!vis[x]){
            vis[x]=1;
            ++genn;
            genres[genn]=x;
        }
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    random_device rd;
    mt19937 getrd(rd());
    int n=getrd()%3+1,m=getrd()%2+2;//
    int q=10;//
    cout<<"0 "<<n<<' '<<m<<" 3 "<<q<<'\n';//
    for(int i=1;i<=m;++i){
        cout<<getrd()%10+1<<' ';//
    }
    cout<<'\n';
    int ki;
    for(int i=1;i<=n;++i){
        ki=getrd()%m+1;
        cout<<ki<<' ';
        gen(m,ki);
        for(int j=1;j<=ki;++j){
            cout<<genres[j]<<' '<<getrd()%10+1<<' ';//
        }
        cout<<'\n';
    }
    int x1,x2;
    for(;q;--q){
        x1=getrd()%m+1;
        do{
            x2=getrd()%m+1;
        }while(x1==x2);
        cout<<x1<<' '<<x2<<'\n';
    }
    return 0;
}
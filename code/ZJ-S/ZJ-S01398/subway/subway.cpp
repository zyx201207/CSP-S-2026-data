#include<bits/stdc++.h>
#define gc getchar_unlocked
#define pc putchar_unlocked
#define pb push_back
#define endl '\n'
using namespace std;
using pii=array<int,2>;
using ll=long long;
const int N=505,M=5e5+10;
const ll inf=5e17;
inline void read(){}
template<class T,class...T2>
inline void read(T&ret,T2&...rest){
    ret=0;char c=gc();bool f=0;
    for(;!isdigit(c)&&c!=EOF;c=gc())f=c=='-';
    for(;isdigit(c);c=gc())ret=ret*10+c-'0';
    if(f)ret=-ret;
    read(rest...);
}
#define cin(...) read(__VA_ARGS__)
template<class T>
inline void print(T x){
    static int stk[40];
    int t=0,f=(x<0);
    if(f)x=-x;
    do stk[t++]=x%10;while(x/=10);
    if(f)pc('-');
    for(;t;pc(stk[--t]+'0'));
}
int ID,n,m,d,q,w[M];
ll f[N][N];
vector<pii>e[M];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin(ID,n,m,d,q);
    for(int u=1;u<=m;u++)
        cin(w[u]);
    for(int i=1;i<=n;i++)
        fill(f[i]+1,f[i]+n+1,inf),f[i][i]=0;
    for(int i=1,sz;i<=n;i++){
        cin(sz);
        for(int j=1,u,vl;j<=sz;j++)
            cin(u,vl),e[u].pb({vl,i});
    }
    for(int u=1;u<=m;u++){
        for(int k1=0;k1<(int)e[u].size();k1++){
            auto[v1,i]=e[u][k1];
            for(int k2=0;k2<k1;k2++){
                auto[v2,j]=e[u][k2];
                f[j][i]=f[i][j]=min(f[i][j],(ll)v1+v2);
            }
        }
    }
    for(int k=1;k<=n;k++)
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
    for(int u,v;q;q--){
        cin(u,v);
        ll res=inf;
        for(auto[v1,i]:e[u])
            for(auto[v2,j]:e[v])
                res=min(res,f[i][j]+v1+v2);
        print(res+w[u]+w[v]),pc(endl);
    }
    return 0;
}
//g++ subway.cpp -o subway -std=c++14 -Wall -Wextra -Og -g -Dlocal -fsanitize=address,undefined
//g++ subway.cpp -o subway -std=c++14 -O2
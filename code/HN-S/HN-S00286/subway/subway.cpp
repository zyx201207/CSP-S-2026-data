// subway
#include<bits/stdc++.h>
using namespace std;
#define debug(...) fprintf(stderr,__VA_ARGS__)
namespace FASTIO{
    template<typename T>
    void read(T &x){
        x=0;bool f=1;int ch=getchar();
        for(;!isdigit(ch);ch=getchar())f=ch=='-'?0:f;
        for(; isdigit(ch);ch=getchar())x=(x<<3)+(x<<1)+(ch^48);
        x=f?x:-x;
    }
    void read(){}
    template<typename T,typename ...Args>
    void read(T &x,Args &...args){read(x),read(args...);}
}
namespace Solve{
using FASTIO::read;
constexpr int M=5e5+5,N=505;
using ll=long long;
constexpr ll inf=0x3f3f3f3f3f3f3f3f;
int c,n,m,d,q;
ll w[M],dis[N][N];
vector<pair<int,ll> >b[M];
int main(){
    read(c,n,m,d,q);
    for(int i=1;i<=m;++i)read(w[i]);
    for(int i=1;i<=n;++i){
        int k;read(k);
        for(int j=1;j<=k;++j){
            int a;ll t;read(a,t);
            b[a].emplace_back(i,t);
        }
    }
    memset(dis,0x3f,sizeof(dis));
    for(int i=1;i<=n;++i)dis[i][i]=0;
    for(int i=1;i<=m;++i){
        for(int j=0;j<b[i].size();++j){
            for(int k=0;k<j;++k){
                int u=b[i][j].first,v=b[i][k].first;
                dis[u][v]=dis[v][u]=min(dis[u][v],b[i][j].second+b[i][k].second);
            }
        }
    }
    for(int k=1;k<=n;++k){
        for(int i=1;i<=n;++i){
            if(i==k)continue;
            for(int j=1;j<=n;++j){
                if(j==k||i==j)continue;
                dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
            }
        }
    }
    while(q--){
        int x,y;read(x,y);ll s=inf;
        for(auto u:b[x]){
            for(auto v:b[y]){
                s=min(s,dis[u.first][v.first]+u.second+v.second);
            }
        }
        s+=w[x]+w[y];
        printf("%lld\n",s);
    }
    return 0;
}
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    return Solve::main();
}
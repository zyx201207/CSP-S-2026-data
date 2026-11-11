#include<bits/stdc++.h>
using namespace std;
using i64=long long;
void Min(i64&x,const i64&y){y<x&&(x=y,0);}
const int N=500+10,M=5e5+10;
const i64 inf=1e17;
i64 dis[N][N];
int W[M];
struct Edge{int v,w;};
vector<Edge>g[M];
signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int Cid,n,m,d,q;cin>>Cid>>n>>m>>d>>q;
    for(int i=1;i<=m;i++)cin>>W[i];
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            dis[i][j]=(i==j?0:inf);  
    for(int u=1;u<=n;u++){
        int cnt;cin>>cnt;
        while(cnt--){
            int i,w1;cin>>i>>w1;
            for(auto[v,w2]:g[i])
                Min(dis[u][v],w1+w2);
            g[i].push_back({u,w1});
        }
    }
    for(int i=1;i<=n;i++)
        for(int j=1;j<i;j++)
            dis[j][i]=dis[i][j];
    for(int k=1;k<=n;k++)
        for(int i=1;i<=n;i++)if(dis[i][k]!=inf)
            for(int j=1;j<i;j++)
                Min(dis[i][j],dis[i][k]+dis[k][j]),
                dis[j][i]=dis[i][j];
    while(q--){
        int x,y;cin>>x>>y;
        i64 ans=inf;
        for(auto[u,w1]:g[x])for(auto[v,w2]:g[y])
            Min(ans,w1+w2+dis[u][v]);
        cout<<ans+W[x]+W[y]<<'\n';
    }
    return 0;
}
//g++ -g subway.cpp -o exe -std=c++14 -O2 -Wall -Wextra -Wshadow -Wconversion -fsanitize=address,undefined
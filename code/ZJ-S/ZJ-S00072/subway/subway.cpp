#include <bits/stdc++.h>
using namespace std;
#define ll long long
constexpr int N=5e2+2,M=5e5+5;
int c,n,m,d,q;
ll dis[N][N],g[N][N],w[M];
bool vis[N];
vector<pair<int,int>>e[M];
void _main(){
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++)cin>>w[i];
    for(int i=1;i<=n;i++){
        int k;cin>>k;
        for(int j=1,x,v;j<=k;j++)cin>>x>>v,e[x].push_back({v,i});
    }
    memset(g,0x3f,sizeof(g));
    for(int i=1;i<=n;i++)g[i][i]=0;
    for(int i=1;i<=m;i++){
        assert(e[i].size()<=d);
        for(int j=0;j<e[i].size();j++)for(int k=j+1;k<e[i].size();k++){
            auto [vx,x]=e[i][j];
            auto [vy,y]=e[i][k];
            // cerr<<x<<' '<<y<<' '<<vx+vy<<'\n';
            g[y][x]=g[x][y]=min(g[x][y],1ll*vx+vy);
        }
    }
    // for(int i=1;i<=n;i++){for(int j=1;j<=n;j++)cout<<g[i][j]<<' ';cout<<'\n';}
    memset(dis,0x3f,sizeof(dis));
    for(int i=1;i<=n;i++){
        memset(vis,0,sizeof(vis));
        dis[i][i]=0;
        for(int w=1;w<=n;w++){
            int p=0;
            for(int j=1;j<=n;j++)if(!vis[j]&&dis[i][j]<dis[i][p])p=j;
            vis[p]=1;
            for(int j=1;j<=n;j++)dis[i][j]=min(dis[i][j],dis[i][p]+g[p][j]);
        }
    }
    // for(int i=1;i<=n;i++){for(int j=1;j<=n;j++)cout<<dis[i][j]<<' ';cout<<'\n';}
    for(int i=1,x,y;i<=q;i++){
        cin>>x>>y;
        if(x==y){cout<<"0\n";continue;}
        ll ans=0x3f3f3f3f3f3f3f3f;
        for(int j=0;j<e[x].size();j++)for(int k=0;k<e[y].size();k++){
            int u=e[x][j].second,v=e[y][k].second;
            ans=min(ans,w[x]+w[y]+e[x][j].first+e[y][k].first+dis[u][v]);
        }
        cout<<ans<<'\n';
    }
}
signed main(){
    clock_t _st=clock();
#ifndef LOCAL
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int t=1;
    while(t--)_main();
    clock_t _ed=clock();
    cerr<<(_ed-_st)*1.0/CLOCKS_PER_SEC<<'\n';
    return 0;
}
/*
g++ subway.cpp -o subway -O2 -std=c++14 -DLOCAL -Wall -Wextra
g++ subway.cpp -o subway -std=c++14 -DLOCAL -fsanitize=address,undefined -Wall -Wextra
g++ subway.cpp -o subway -std=c++14 -DLOCAL -fsanitize=address,undefined -pg -Wall -Wextra
g++ subway.cpp -o subway -std=c++14 -DLOCAL -fsanitize=address,undefined -g -Wall -Wextra
*/
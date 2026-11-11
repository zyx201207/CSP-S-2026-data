#include <bits/stdc++.h>
using namespace std;
#define ll long long
constexpr int N=1e3+3;
int c,n,m,d,q;
ll dis[N][N],g[N][N],w[N];
bool vis[N];
void _main(){
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++)cin>>w[i];
    memset(g,0x3f,sizeof(g));
    for(int i=1;i<=n+m;i++)g[i][i]=0;
    for(int i=1;i<=n;i++){
        int k;cin>>k;
        for(int j=1,x,v;j<=k;j++)cin>>x>>v,g[i+m][x]=g[x][i+m]=min(g[x][i+m],1ll*v);
    }
    memset(dis,0x3f,sizeof(dis));
    for(int i=1;i<=m;i++){
        memset(vis,0,sizeof(vis));
        dis[i][i]=0;
        for(int w=1;w<=n+m;w++){
            int p=0;
            for(int j=1;j<=n+m;j++)if(!vis[j]&&dis[i][j]<dis[i][p])p=j;
            vis[p]=1;
            for(int j=1;j<=n+m;j++)dis[i][j]=min(dis[i][j],dis[i][p]+g[p][j]);
        }
    }
    for(int i=1,x,y;i<=q;i++){
        cin>>x>>y;
        if(x==y){cout<<"0\n";continue;}
        if(dis[x][y]==0x3f3f3f3f3f3f3f3f)cout<<dis[x][y]<<'\n';
        else cout<<dis[x][y]+w[x]+w[y]<<'\n';
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
g++ std.cpp -o std -O2 -std=c++14 -DLOCAL -Wall -Wextra
g++ std.cpp -o std -std=c++14 -DLOCAL -fsanitize=address,undefined -Wall -Wextra
g++ std.cpp -o std -std=c++14 -DLOCAL -fsanitize=address,undefined -pg -Wall -Wextra
g++ std.cpp -o std -std=c++14 -DLOCAL -fsanitize=address,undefined -g -Wall -Wextra
*/
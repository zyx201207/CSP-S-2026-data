#include <bits/stdc++.h>
using namespace std;
#define int long long

int c,n,m,d,q;
int w[500010];

int dis[80010][80010];

// void add(int u,int v,int w) {
//     go[++ecnt]=v;nxt[ecnt]=adj[u];adj[u]=ecnt;
//     val[ecnt]=w;
//     // cout<<ecnt<<" "<<go[ecnt]<<" "<<adj[u]<<" "<<nxt[ecnt]<<" "<<val[ecnt]<<"\n";
//     return ;
// }

// void dijkstra(int u) {
//     if (u==adj[u]) return ;
//     // cout<<1<<"\n";
//     // int fa=adj[u];
//     // cout<<fa<<"\n";
//     for (int i=adj[u];i;i=nxt[i]) {
//         // cout<<i<<" "<<go[i]<<" "<<nxt[i]<<" ";
//         if (vis[go[i]]) continue;
//         dis[go[i]]=min(dis[go[i]],dis[i]+val[i]);
//     }
//     return ;
// }

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(),cout.tie();
    
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);

    cin>>c>>n>>m>>d>>q;
    for (int i=1;i<=m;i++) cin>>w[i];
    for (int i=1;i<=n;i++) {
        int k;cin>>k;
        int a,t,al,tl;
        for (int j=1;j<=k;j++) {
            al=a,tl=t;
            cin>>a>>t;
            // cout<<a<<" "<<al<<" "<<t<<" "<<tl<<"\n";
            if (j==1) continue;
            // add(a,al,t+tl);
            // add(al,a,t+tl);
            dis[a][al]=t+tl;
            dis[al][a]=t+tl;

        }
    }
    // cout<<ecnt<<"\n";
    // for (int i=1;i<=ecnt;i++) {
    //     cout<<go[i]<<" "<<adj[i]<<" "<<nxt[i]<<" "<<val[i]<<"\n";
    // }
    while (q--) {
        // memset(dis,0x3f,sizeof(dis));
        // memset(vis,0,sizeof(vis));
        int x,y;
        cin>>x>>y;
        // dis[y]=0;
        // dijkstra(y);
        if (x==y) cout<<2*w[x]<<"\n";
        else cout<<dis[x][y]+w[x]+w[y]<<"\n";
    }
    return 0;
}
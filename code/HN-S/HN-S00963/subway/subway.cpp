#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=510,M=5e5+510;
bool A1;
int c,n,m,d,q,inf=1e18;
int val[M],dis[N][N];
bool vis[M];
struct edge{
    int y,w;
};
vector<edge> g[M],e[M];
bool A2;
inline void solve(){
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++) dis[i][j]=inf;
    for(int i=1;i<=n;i++){
        dis[i][i]=0;
        for(edge x:g[i+m]){
            int u=x.y;
            for(edge y:g[u]){
                int j=y.y-m;
                dis[i][j]=dis[j][i]=min(dis[i][j],x.w+y.w);
            }
        }
    }
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            for(int k=1;k<=n;k++) dis[i][j]=dis[j][i]=min(dis[i][j],dis[i][k]+dis[j][k]);
    return;
}
signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++) cin>>val[i];
    for(int i=1;i<=n;i++){
        int k;
        cin>>k;
        for(int j=1;j<=k;j++){
            int x,w;
            cin>>x>>w;
            g[x].push_back({i+m,w});
            g[i+m].push_back({x,w});
            e[x].push_back({i,w});
        }
    }
    solve();
    while(q--){
        int x,y,ans=inf;
        cin>>x>>y;
        for(edge i:e[x])
            for(edge j:e[y]){
                int u=i.y,v=j.y;
                ans=min(ans,dis[u][v]+i.w+j.w+val[x]+val[y]);
            }
        cout<<ans<<"\n";
    }
    return 0;
}
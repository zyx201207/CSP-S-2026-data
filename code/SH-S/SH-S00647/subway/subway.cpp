#include<bits/stdc++.h>
//Things will always be better, just let time plays
using namespace std;
#define HACKILLER_FAST ios::sync_with_stdio(false),cin.tie(0)
#define int long long
#define ull unsigned long long
#define vc vector
#define pii pair<int,int>
#define pb push_back
#define ls x<<1
#define rs x<<1|1
constexpr int INF = 1e18;
struct node{
    int ti,wi;
};
int id,n,m,d,q,w[500050],a[505][505],k[505],t[505][505],dis[505][505],x,y;
vc<node> es[500050];

signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    HACKILLER_FAST;
    cin>>id>>n>>m>>d>>q;
    for(int i = 1;i <= m;++i) cin>>w[i];
    for(int i = 1;i <= n;++i){
        cin>>k[i];
        for(int j = 1;j <= k[i];++j){
            cin>>a[i][j]>>t[i][j];
            es[a[i][j]].pb({i,t[i][j]});
        }
    }
    for(int i = 1;i <= n;++i){
        for(int j = 1;j <= n;++j) dis[i][j] = INF;
    }
    for(int i = 1;i <= n;++i) dis[i][i] = 0;
    for(int i = 1;i <= m;++i){
        for(int j = 0;j < es[i].size();++j){
            for(int k = j+1;k < es[i].size();++k){
                int u = es[i][j].ti,v = es[i][k].ti;
                dis[u][v] = dis[v][u] = es[i][j].wi+es[i][k].wi;
            }
        }
    }
    for(int k = 1;k <= n;++k){
        for(int i = 1;i <= n;++i){
            for(int j = 1;j <= n;++j) dis[i][j] = min(dis[i][j],dis[i][k]+dis[k][j]);
        }
    }
    while(q--){
        cin>>x>>y;
        int ans = INF;
        for(int i = 0;i < es[x].size();++i){
            for(int j = 0;j < es[y].size();++j){
                int u = es[x][i].ti,v = es[y][j].ti;
                ans = min(ans,dis[u][v]+es[x][i].wi+es[y][j].wi);
            }
        }
        cout<<ans+w[x]+w[y]<<'\n';
    }
    return 0;
}
//ForEverLOVE

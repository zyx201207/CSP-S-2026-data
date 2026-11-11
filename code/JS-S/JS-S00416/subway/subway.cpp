#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef pair<int,int> pii;
const int M=500555,N=555;
int c,n,m,d,q,www[M],dis[N][N],vis[N];
vector<pii> g[N],e[M];
void dij(int s){
    priority_queue<pii,vector<pii>,greater<pii>> pq;
    for(int i=0;i<=n+10;i++){
        dis[i][s]=4e18;
        vis[i]=0;
    }
    dis[s][s]=0;
    vis[s]=1;
    pq.push({0,s});
    while(pq.size()){
        auto [d,u]=pq.top();
        pq.pop();
        if(dis[u][s]!=d)continue;
        vis[u]=1;
        for(auto [v,w]:g[u]){
            if(!vis[v]&&dis[v][s]>d+w){
                dis[v][s]=d+w;
                pq.push({dis[v][s],v});
            }
        }
    }
}
signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);cin.tie(0);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>www[i];
    }
    for(int i=1,k;i<=n;i++){
        cin>>k;
        for(int j=1,a,t;j<=k;j++){
            cin>>a>>t;
            e[m+i].push_back({a,t});
            e[a].push_back({m+i,t});
        }
    }
    for(int x=1;x<=m;x++){
        for(int i=0;i<e[x].size();i++){
            for(int j=i+1;j<e[x].size();j++){
                auto [u,w1]=e[x][i];
                auto [v,w2]=e[x][j];
                g[u-m].push_back({v-m,w1+w2});
                g[v-m].push_back({u-m,w1+w2});
            }
        }
    }
    for(int i=1;i<=n;i++){
        dij(i);
    }
    for(int i=1,x,y;i<=q;i++){
        cin>>x>>y;
        int ans=4e18;
        for(auto [ax,tx]:e[x]){
            for(auto [ay,ty]:e[y]){
                ans=min(ans,tx+ty+dis[ax-m][ay-m]);
            }
        }
        cout<<ans+www[x]+www[y]<<'\n';
    }
    return 0;
}

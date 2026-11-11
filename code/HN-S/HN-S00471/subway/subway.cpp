#include <bits/stdc++.h>
using namespace std;

struct Edge {
    int v,w;
    bool operator <(const Edge&e) const {
        return w>e.w;
    }
};
const int MAXN=5*1e5;
const int MAXM=505;
vector<Edge>G[3*MAXN+MAXM*22];
int dis[3*MAXN+MAXM*22];
int vis[3*MAXN+MAXM*22];
// u地铁站口
// m+u地铁站厅
// k为路线编号，d为最多单站，2*m+k*d+u地铁站台

int dijkstra(int s,int e) {
    memset(dis,0x3f,sizeof(dis));
    memset(vis,0,sizeof(vis));
    priority_queue<Edge> q;
    dis[s]=0;
    q.push({s,0});
    while(!q.empty()) {
        int u=q.top().v;q.pop();
        if(vis[u])continue;
        vis[u]=1;
        for(auto&e:G[u]) {
            if(dis[e.v]>dis[u]+e.w) {
                dis[e.v]=dis[u]+e.w;
                q.push({e.v,dis[e.v]});
            }
        }
    }
    return dis[e];
}

int main() {
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    int c,n,m,d,q;
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++) {
        int w;cin>>w;
        G[i].push_back({m+i,w});
        G[m+i].push_back({i,w});
    }
    for(int i=1;i<=n;i++) {
        int k;cin>>k;
        vector<int>a(k+1),t(k+1);
        for(int j=1;j<=k;j++) {
            cin>>a[j]>>t[j];
            G[m+a[j]].push_back({2*m+i*d+a[j],t[j]});
            G[2*m+i*d+a[j]].push_back({m+a[j],t[j]});
        }

        for(int j=1;j<k;j++) {
            G[2*m+i*d+a[j]].push_back({2*m+i*d+a[j+1],0});
            G[2*m+i*d+a[j+1]].push_back({2*m+i*d+a[j],0});
        }
    }
    while(q--) {
        int x,y;cin>>x>>y;
        cout<<dijkstra(x,y)<<'\n';
    }
}


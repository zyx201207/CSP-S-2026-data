#include<bits/stdc++.h>
using namespace std;
struct edge {
    int v,w;
};
vector<edge>g[2000010];
int p[500010],dis[500010];
bool vis[500010];
queue<pair<int,int>>qu;
int main() {
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    int c,n,m,d,q;
    cin >> c >> n >> m >> d >> q;
    for(int i=1;i<=m;i++) {
        int t;
        cin >> t;
        g[i+m].push_back({i,t});
        g[i].push_back({i+m,t});
    }
    int cnt=2*m;
    for(int i=1;i<=n;i++) {
        int k;
        cin >> k;
        for(int j=1;j<=k;j++) {
            int t;
            cin >> p[j] >> t;
            cnt++;
            g[cnt].push_back({p[j]+m,t});
            g[p[j]+m].push_back({cnt,t});
            if(j!=1) {
                g[cnt-1].push_back({cnt,0});
                g[cnt].push_back({cnt-1,0});
            }
        }
    }
    while(q--) {
        int s,t;
        cin >> s >> t;
        for(int i=1;i<=500000;i++) {
            dis[i]=INT_MAX;
        }
        dis[s]=0;
        memset(vis,0,sizeof(vis));
        vis[s]=1;
        qu.push({s,0});
        while(!qu.empty()) {
            int u=qu.front().first;
            int d=qu.front().second;
            qu.pop();
            for(edge ed:g[u]) {
                int v=ed.v;
                int w=ed.w;
                if(dis[v]>dis[u]+w) {
                    dis[v]=dis[u]+w;
                    qu.push({v,dis[u]+w});
                }
            }
        }
        cout << dis[t] << "\n";
    }
    return 0;
}
#include<bits/stdc++.h>
using namespace std;
vector<pair<int,int>> g[3276800]; // first : end || second : cost
int cnt[163840];
int c, n, m, d, q;
long long spfa(int s, int e);
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>c>>n>>m>>d>>q;
    // for i: a->i, b->i+m, c->i+2m,i+3m,ect.
    for(int i=1;i<=m;i++){
        int a;
        cin>>a;
        g[i].push_back({i+m, a});
        g[i+m].push_back({i, a});
        cnt[i] ++;
    }
    for(int i=1;i<=n;i++){
        int k;
        cin>>k;
        int s, t;
        cin>>s>>t;
        g[s+m].push_back({s+(cnt[s]+1)*m, t});
        g[s+(cnt[s]+1)*m].push_back({s+m, t});
        cnt[s] ++;
        for(int i=0;i<k;i++){
            int u, w;
            cin>>u>>w;
            g[u+(cnt[u]+1)*m].push_back({s+(cnt[s]+1)*m, 0});
            g[s+(cnt[s]+1)*m].push_back({u+(cnt[u]+1)*m, 0});
            g[u+m].push_back({u+(cnt[u]+1)*m, w});
            g[u+(cnt[u]+1)*m].push_back({u+m, w});
            cnt[s] ++;
            cnt[u] ++;
            s = u;
        }
    }
    while(q--){
        int s,e;
        cin>>s>>e;
        int ans = spfa(s, e);
        cout<<ans<<'\n';
    }
    return 0;
}
long long spfa(int s, int e){
    long long dist[163840];
    memset(dist, 0x3f, 20*m*sizeof(long long));
    dist[s] = 0;
    queue<pair<int,int>> qp;
    bool vis[3276800] = {0};
    vis[s] = 1;
    qp.push(g[s].front());
    while(!qp.empty()){
        auto p = qp.front(); qp.pop();
        for(auto l : g[p.first]){
            if(!vis[l.first]){
                qp.push(l);
            }
            vis[l.first] = 1;
            int r = l.first;
            dist[r] = min(dist[r], dist[p.first]+p.second);
        }
    }
    return dist[e];
}

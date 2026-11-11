#include<bits/stdc++.h>
using namespace std;
long long op, n, m, d, q, a[500010], c[510], t1, t2, dis[500510];
vector<pair<long long, long long>> g[500010];
bool vis[500010];
struct node{
    long long u, du;
};
bool operator<(const node& n1, const node& n2){ return n1.du > n2.du; }
long long bfs(long long s, long long t){
    memset(vis, 0, sizeof(vis));
    memset(dis, 0x3f, sizeof(dis));
    priority_queue<node> pq;
    pq.push({s, 0});
    dis[s] = 0;
    while(!pq.empty()){
        long long u = pq.top().u;
        pq.pop();
        if(vis[u]) continue;
        vis[u] = true;
        if(u == t) return dis[u];
        for(auto v : g[u]){
            if(dis[v.first] > dis[u] + v.second){
                dis[v.first] = dis[u] + v.second;
                pq.push({v.first, dis[v.first]});
            }
        }
    }
}
int main(){
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);

    cin >> op >> n >> m >> d >> q;
    for(long long i = 1; i <= m; i++) cin >> a[i];
    for(long long i = 1; i <= n; i++){
        cin >> c[i];
        for(long long j = 1; j <= c[i]; j++){
            cin >> t1 >> t2;
            g[t1].push_back({m + i, t2});
            g[m + i].push_back({t1, t2});
        }
    }
    while(q--){
        long long x, y;
        cin >> x >> y;
        cout << a[x] + a[y] + bfs(x, y) << '\n';
    }

    return 0;
}

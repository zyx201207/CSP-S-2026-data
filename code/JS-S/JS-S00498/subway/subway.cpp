#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 5e5 + 5;
const int M = 2e3 + 3;
int g[M][M];
int w[N], k[M];
int c, n, m, d, qq;
struct Edge{
    int y, v;
    bool operator < (const Edge &rhs) const {
        return v > rhs.v;
    }
};
vector<Edge> G[N];
int dis[N];
priority_queue<Edge> Q;
inline void Dijkstra(int s){
    memset(dis, 0x3f, sizeof dis);
    while(!Q.empty()) Q.pop();
    dis[s] = 0;
    Q.push({s, 0});
    while(!Q.empty()){
        auto u = Q.top().y;
        Q.pop();
        for(auto e : G[u]){
            int y = e.y, v = e.v;
            if(dis[y] > dis[u] + v){
                dis[y] = dis[u] + v;
                Q.push({y, dis[y]});
            }
        }
    }
}
queue<Edge> q;
inline void bfs(int s){
    memset(dis, 0x3f, sizeof dis);
    while(!q.empty()) q.pop();
    dis[s] = 0;
    q.push({s, 0});
    while(!q.empty()){
        auto u = q.front().y;
        q.pop();
        for(auto e : G[u]){
            int y = e.y, v = e.v;
            if(dis[y] > dis[u] + v){
                dis[y] = dis[u] + v;
                q.push({y, dis[y]});
            }
        }
    }
}
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    cin >> c >> n >> m >> d >> qq;
    for(int i = 1; i <= m; i++) cin >> w[i];
    int T = 0, flg = 1;
    for(int i = 1; i <= n; i++){
        cin >> k[i];
        for(int j = 0; j < k[i]; j++){
            int a, t;
            cin >> a >> t;
            if(!T) T = t;
            if(t ^ T) flg = 0;
            G[a].push_back({m + i, t});
            G[m + i].push_back({a, t});
        }
    }
    if(m <= 2000){
        for(int i = 1; i < m; i++){
            Dijkstra(i);
            for(int j = i + 1; j <= m; j++) g[i][j] = dis[j] + w[i] + w[j];
        }
    }
    while(qq--){
        int x, y;
        cin >> x >> y;
        if(x > y) swap(x, y);
        if(m <= 2000) cout << g[x][y] << "\n";
        else if(flg){
            bfs(x);
            cout << w[x] + w[y] + dis[y] << "\n";
        }
    }
    return 0;
}

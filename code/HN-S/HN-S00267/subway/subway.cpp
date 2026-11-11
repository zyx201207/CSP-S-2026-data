#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 505, M = 5e5 + 5, INF = 1e18;
int n, m, d, q, w[M], K[N];
struct node{
    int p, t;
};
map <pair<int, int>, int> pos;
vector <node> g[N];
namespace baoli{
    vector <int> lt[1005];
    int dis[N];
    struct Node{
        int u, dv;
        bool operator <(const Node &T) const{
            return dv > T.dv;
        }
    };
    void dij(int st){
        priority_queue <Node> pq;
        for(int i = 1; i <= n; i++){
            if(pos.count({i, st})){
                dis[i] = w[st] + g[i][pos[{i, st}]].t;
                pq.push({i, w[st] + g[i][pos[{i, st}]].t});
            }
            else dis[i] = INF;
        }
        while(!pq.empty()){
            int u = pq.top().u, dv = pq.top().dv;
            pq.pop();
            if(dv != dis[u]) continue;
            for(int i = 0; i < K[u]; i++){
                int p = g[u][i].p, t = g[u][i].t;
                for(int j = 0; j < (int)lt[p].size(); j++){
                    int v = lt[p][j];
                    if(v == u || !pos.count({v, p})) continue;
                    int t2 = g[v][pos[{v, p}]].t;
                    if(dis[u] + t + t2 < dis[v]){
                        dis[v] = dis[u] + t + t2;
                        pq.push({v, dis[v]});
                    }
                }
            }
        }
        return ;
    }
    void solve(){
        for(int i = 1; i <= n; i++){
            for(int j = 0; j < K[i]; j++){
                int u = g[i][j].p;
                lt[u].push_back(i);
            }
        }
        while(q--){
            int l, r;
            cin >> l >> r;
            dij(l);
            int ans = INF;
            for(int i = 1; i <= n; i++){
                if(pos.count({i, r})){
                    ans = min(ans, dis[i] + g[i][pos[{i, r}]].t);
                }
            }
            cout << ans + w[r] << '\n';
        }
        return ;
    }
}
namespace baoli2{
    vector <int> rg[M];
    struct edge{
        int to, val;
    };
    vector <edge> g2[N];
    int dist[N][N], dis[N];
    struct Node{
        int u, dv;
        bool operator <(const Node &T) const{
            return dv > T.dv;
        }
    };
    void dij(int st){
        priority_queue <Node> pq;
        for(int i = 1; i <= n; i++) dis[i] = INF;
        dis[st] = 0;
        pq.push({st, 0});
        while(!pq.empty()){
            int u = pq.top().u, dv = pq.top().dv;
            pq.pop();
            if(dv != dis[u]) continue;
            for(int i = 0; i < (int)g2[u].size(); i++){
                int v = g2[u][i].to, t = g2[u][i].val;
                if(dis[u] + t < dis[v]){
                    dis[v] = dis[u] + t;
                    pq.push({v, dis[v]});
                }
            }
        }
        for(int i = 1; i <= n; i++){
            dist[st][i] = dis[i];
        }
        return ;
    }
    void solve(){
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= K[i]; j++){
                int p = g[i][j - 1].p;
                rg[p].push_back(i);
            }
        }
        for(int i = 1; i <= m; i++){
            if((int)rg[i].size() >= 2){
                int u = rg[i][0], v = rg[i][1];
                int t1 = g[u][pos[{u, i}]].t, t2 = g[v][pos[{v, i}]].t;
                g2[u].push_back({v, t1 + t2});
                g2[v].push_back({u, t1 + t2});
            }
        }
        for(int i = 1; i <= n; i++){
            dij(i);
        }
        while(q--){
            int l, r;
            cin >> l >> r;
            int ans = INF;
            for(int u : rg[l]){
                for(int v : rg[r]){
                    int res = g[u][pos[{u, l}]].t + g[v][pos[{v, r}]].t + dist[u][v];
                    ans = min(ans, res + w[l] + w[r]);
                }
            }
            cout << ans << '\n';
        }
        return ;
    }
}
namespace baoli3{
    bool canto[M][3];
    void solve(){
        int mn = INF;
        for(int i = 1; i <= m; i++){
            if(pos.count({1, i})) canto[i][1] = true;
            if(pos.count({2, i})) canto[i][2] = true;
            if(canto[i][1] && canto[i][2]){
                int dis = g[1][pos[{1, i}]].t + g[2][pos[{2, i}]].t;
                mn = min(mn, dis);
            }
        }
        while(q--){
            int l, r;
            cin >> l >> r;
            int ans = INF;
            if(canto[l][1] && canto[r][1]) ans = min(ans, g[1][pos[{1, l}]].t + g[1][pos[{1, r}]].t);
            if(canto[l][2] && canto[r][2]) ans = min(ans, g[2][pos[{2, l}]].t + g[2][pos[{2, r}]].t);
            if(canto[l][1] && canto[r][2]) ans = min(ans, g[1][pos[{1, l}]].t + g[2][pos[{2, r}]].t + mn); 
            if(canto[l][2] && canto[r][1]) ans = min(ans, g[2][pos[{2, l}]].t + g[1][pos[{1, r}]].t + mn);
            cout << ans + w[l] + w[r] << '\n';
        }
    }
}

signed main(){
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int C;
    cin >> C >> n >> m >> d >> q;
    for(int i = 1; i <= m; i++) cin >> w[i];
    for(int i = 1; i <= n; i++){
        cin >> K[i];
        for(int j = 1, u, v; j <= K[i]; j++){
            cin >> u >> v;
            g[i].push_back({u, v});
            pos[{i, u}] = j - 1;
        }
    }
    if(C <= 8){
        baoli::solve();
        return 0;
    }
    if(C >= 20 && C <= 21){
        baoli3::solve();
        return 0;
    }
    if(C >= 22 && C <= 23){
        baoli2::solve();
        return 0;
    }
    return 0;
}
/*
【机构名称】你赢了。
40分我写了两百行。
给我写吐了。
*/
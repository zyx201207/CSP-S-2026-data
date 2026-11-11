#include<bits/stdc++.h>
using namespace std;
#define int long long

const int N = 1e6 + 10;
int c, n, m, d, q;
int dis[N];
bool vis[N];
vector<vector<pair<int, int>>> g(N);
int scnt[N];
int k[N];
struct cmp{ 
    bool operator () (const pair<int, int> &x, const pair<int, int> &y) const {
        return x.second > y.second;
    }
};
void dijkstra(int s){
    priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> heap;
    memset(dis, 127, sizeof(dis));
    memset(vis, false, sizeof(vis));
    dis[s] = 0;
    heap.push({s, 0});
    while(!heap.empty()){
        int u = heap.top().first;
        heap.pop();
        if(vis[u]) continue;
        vis[u] = true;
        for(auto p : g[u]){
            int v = p.first;
            int w = p.second;
            if(dis[u] + w < dis[v]){
                dis[v] = dis[u] + w;
                heap.push({v, dis[v]});
            }
        }
    }
}
signed main(){
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    cin >> c >> n >> m >> d >> q;
    for(int i = 1;i <= m;i++){
        int x;
        cin >> x;
        g[i].push_back({i + m, x});
        g[i + m].push_back({i, x});
    }
    for(int i = 1;i <= n;i++){
        cin >> k[i];
        if(i > 1) scnt[i] = scnt[i - 1] + k[i - 1];
        for(int j = 1;j <= k[i];j++){
            int a, t;
            cin >> a >> t;
            g[a + m].push_back({scnt[i] + j + 2 * m, t});
            g[scnt[i] + j + 2 * m].push_back({a + m, t});
        }
    }
    for(int i = 1;i <= n;i++){
        for(int j = 1;j < k[i];j++){
            g[scnt[i] + j + 2 * m].push_back({scnt[i] + j + 1 + 2 * m, 0});
            g[scnt[i] + j + 1 + 2 * m].push_back({scnt[i] + j + 2 * m, 0});
        }
    }
    while(q--){
        int s, t;
        cin >> s >> t;
        dijkstra(s);
        cout << dis[t] << "\n";
    }
    return 0;
}
/*
0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3
*/
#include<bits/stdc++.h>

using namespace std;
using ll = long long;

const int N = 1e6 + 5, INF = 1e9;

int c, t, n, k, dis[N];
vector<int> g[N];
queue<int> qp;
bool vis[N];

struct node{
    int ma1, ma2;
    void Insert(int x){
        if(ma1 < x) ma2 = ma1, ma1 = x;
        else if(ma2 < x) ma2 = x;
    }
}hma[N];

void bfs1(int s){
    for(int i = 0; i < n; i++) dis[i] = INF;
    for(int i = 0; i < n; i++) if((s >> i) & 1) qp.push(i), dis[i] = 0;
    while(qp.size()){
        int u = qp.front();
        qp.pop();
        for(int v : g[u + 1]){
            if(dis[v - 1] != INF) continue;
            dis[v - 1] = dis[u] + 1, qp.push(v - 1);
        }
    }
}

void dfs1(int s, int u){
    vis[u] = 1;
    for(int v : g[u + 1]) if(((s >> (v - 1)) & 1) && !vis[v - 1]) dfs1(s, v - 1);
}

void solve(){
    for(int i = 1; i <= n; i++) g[i].clear();
    cin >> n >> k;
    for(int i = 1, u, v; i < n; i++) cin >> u >> v, g[u].push_back(v), g[v].push_back(u);
    if(n <= 10){
        int ans = INF, sum = 0;
        for(int mask = 0; mask < (1 << n); mask++){
            int cnt = 0;
            for(int i = 0; i < n; i++) cnt += (mask >> i) & 1, vis[i] = 0;
            if(cnt != k) continue;
            cnt = 0;
            for(int i = 0; i < n; i++) if(((mask >> i & 1)) && !vis[i]) dfs1(mask, i), cnt++;
            if(cnt > 2) continue;
            bfs1(mask), sum = 0;
            for(int i = 0; i < n; i++) sum = max(sum, dis[i]);
            ans = min(ans, sum);
        }
        cout << ans << '\n';
        return ;
    }
}

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    freopen("hub.in", "r", stdin);
    freopen("hub.out", "w", stdout);
    cin >> c >> t;
    while(t--) solve();
    return 0;
}
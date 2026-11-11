#include <bits/stdc++.h>

using namespace std;

const int N = 1050;
const int INF = 1e9;
int n, K;
int mp[N][N];
bool vis[N], choose[N];
vector <int> gra[N];

void init(){
    for(int i = 1; i <= n; i++){
        gra[i].clear();
        for(int j = 1; j <= n; j++){
            mp[i][j] = 0;
        }
    }
}

void dfs(int u, int fa, int *dist){
    for(auto v : gra[u]){
        if(v == fa) continue;
        dist[v] = dist[u] + 1;
        dfs(v, u, dist);
    }
}

void color(int u, int fath){
    vis[u] = true;
    for(auto v : gra[u]){
        if(v == fath) continue;
        if(!choose[v]) continue;
        color(v, u);
    }
}

void solve2(){
    int ans = INT_MAX;
    for(int u = 1; u <= n; u++){
        for(int v = 1; v <= n; v++){
            if(u == v) continue;
            int ma = 0;
            for(int to = 1; to <= n; to++){
                int len = min(mp[u][to], mp[v][to]);
                ma = max(ma, len);
            } 
            ans = min(ans, ma);
        }
    }
    cout << ans << "\n";
}

void solve(){
    cin >> n >> K;
    init();
    for(int i = 1; i < n; i++){
        int u, v;
        cin >> u >> v;
        gra[u].push_back(v);
        gra[v].push_back(u);
    }
    for(int i = 1; i <= n; i++){
        dfs(i, 0, mp[i]);
    }   
    if(K == 2){
        solve2();
        return ;
    }
    int max_state = 1 << n;
    int ans = INT_MAX;
    for(int S = 0; S < max_state; S++){
        int cnt = __builtin_popcount(S);
        if(cnt != K) continue;
        vector <int> have;
        for(int i = 0; i < n; i++){
            vis[i + 1] = false;
            if((S >> i) & 1){
                have.push_back(i + 1);
                choose[i + 1] = true;
                continue;
            }
            choose[i + 1] = false;
        }
        int bcnt = 0;
        for(int i = 1; i <= n; i++){
            if(((S >> (i - 1)) & 1) && !vis[i]){
                bcnt++;
                color(i, 0);
            }
        }
        if(bcnt > 2) continue;
        vector <int> dis(n + 1, INF);
        for(auto u : have){
            for(int v = 1; v <= n; v++){
                dis[v] = min(dis[v], mp[u][v]);
            }
        }
        int ma = 0;
        for(int v = 1; v <= n; v++){
            ma = max(ma, dis[v]);
        }
        ans = min(ans, ma);
    }
    cout << ans << "\n";
}

int main(){ 
    freopen("hub.in", "r", stdin);
    freopen("hub.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int c, T;
    cin >> c >> T;
    while(T--) solve();
    return 0;
}
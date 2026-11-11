#include <bits/stdc++.h>
using namespace std;

const int N = 4e3 + 12;

int c, n, k, dis[110][110], res;

vector<int> nbr[N];

bool flg[N], vis[N];

void DFS(int x, int fa){ vis[x] = true;
    for(auto ed : nbr[x]){
        if(!flg[ed] || ed == fa) continue;
        DFS(ed, x);
    }
}

void Dfs(int x, int s, int fa){ dis[s][x] = dis[s][fa] + 1;
    for(auto ed : nbr[x]){
        if(ed == fa) continue;
        Dfs(ed, s, x);
    }
}

void dfs(int x, int cnt){
    if(cnt == k){
        int C = 0;
        for(int i = 1; i <= n; i ++) vis[i] = false;
        for(int i = 1; i <= n; i ++){
            if(flg[i] && !vis[i]){
                ++ C; DFS(i, 0);
            }
        }
        if(C > 2) return;
        int mx = 0;
        for(int i = 1; i <= n; i ++){
            dis[i][0] = -1; Dfs(i, i, 0);
            int Mn = 1e9;
            for(int j = 1; j <= n; j ++){
                if(flg[j]) Mn = min(Mn, dis[i][j]);
            }   
            mx = max(mx, Mn);
        }
        res = min(res, mx);
        return;
    }
    if(x > n) return;
    flg[x] = true; dfs(x + 1, cnt + 1);
    flg[x] = false; dfs(x + 1, cnt);
}

void solve(){ cin >> n >> k;
    for(int i = 1; i <= n; i ++) nbr[i].clear(), flg[i] = false;
    for(int i = 1; i < n; i ++){
        int u, v; cin >> u >> v;
        nbr[u].emplace_back(v); nbr[v].emplace_back(u);
    }
    res = 1e9; dfs(1, 0);
    cout << res << '\n';
}

signed main(){
    freopen("hub.in", "r", stdin);
    freopen("hub.out", "w", stdout);

    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int T = 1; cin >> c >> T;
    while(T --) solve();
}
#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 10;

int n, k, ans = N;
vector<int> G[N];

vector<int> slc;
int f[N], d[N];
void spr(int u) {
    f[u] = 2;
    for(int v : G[u]) if(f[v] == 1) spr(v); 
}
void update() {
    for(int i = 1; i <= n; i++) f[i] = 0, d[i] = -1;
    for(int i : slc) f[i] = 1;
    spr(slc[0]);
    for(int i : slc) if(f[i] != 2) { spr(i); break; }
    for(int i : slc) if(f[i] != 2) return;
    queue<int> q;
    for(int i : slc) q.push(i), d[i] = 0;
    while(q.size()) {
        int u = q.front();
        q.pop();
        for(int v : G[u]) if(!~d[v]) q.push(v), d[v] = d[u] + 1;
    }
    ans = min(ans, *max_element(d + 1, d + 1 + n));
}
void dfs(int t, int lst) {
    if(t == k + 1) {
        update();
        return;
    }
    for(int i = lst + 1; i <= n - (k - t); i++) {
        slc.push_back(i);
        dfs(t + 1, i);
        slc.pop_back();
    }
} 

void solve() {
    ans = N;
    cin >> n >> k;
    for(int i = 1; i <= n; i++) G[i].clear();
    for(int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    dfs(1, 0);
    cout << ans << "\n";
}

int main() {
    freopen("hub.in", "r", stdin);
    freopen("hub.out", "w", stdout);
    
    ios::sync_with_stdio(false);
    int C, T;
    cin >> C >> T;
    while(T--) solve();
    return 0;
}
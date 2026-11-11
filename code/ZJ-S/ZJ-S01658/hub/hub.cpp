/*
17:40 开始暴力
开始写 15pts 暴力
18:08 太糖了，怎么写了这么久，目前总得分 271pts
开始检查
*/

#include<bits/stdc++.h>
using namespace std;
constexpr int N = 1000005;
int c, t;
int n, k;
vector<int> vec[N];
bool f[N];
bool vis[N];
void dfs(int u) {
    vis[u] = 1;
    for(int v : vec[u]) {
        if(f[v] && !vis[v]) {
            dfs(v);
        }
    }
    return ;
}
bool check() {
    int bit_count = 0;
    for(int i = 1; i <= n; i ++) {
        bit_count += f[i];
    }
    if(bit_count != k) return 0;
    for(int i = 1; i <= n; i ++) {
        vis[i] = 0;
    }
    int b_count = 0;
    for(int i = 1; i <= n; i ++) {
        if(f[i] && !vis[i]) {
            dfs(i);
            b_count ++;
        }
    }
    if(b_count > 2) return 0;
    return 1;
}
int dfs2(int u, int F) {
    if(f[u]) return 0;
    int res = 1e9;
    for(int v : vec[u]) {
        if(v == F) continue;
        res = min(res, dfs2(v, u));
    }
    return res + 1;
}
int calc() {
    int res = 0;
    for(int i = 1; i <= n; i ++) {
        if(!f[i]) {
            res = max(res, dfs2(i, 0));
        }
    }
    return res;
}
void init(int n, int k) {
    for(int i = 1; i <= n; i ++) {
        vec[i].clear();
    }
    return ;
}
signed Main() {
    cin >> n >> k;
    init(n, k);
    for(int i = 1; i < n; i ++) {
        int u, v;
        cin >> u >> v;
        vec[u].push_back(v);
        vec[v].push_back(u);
    }
    int ans = 1e9;
    for(int i = 0; i < (1 << n); i ++) {
        for(int j = 1; j <= n; j ++) {
            f[j] = (i >> (j - 1)) & 1;
        }
        if(check()) {
            ans = min(ans, calc());
        }
    }
    cout << ans << "\n";
    return 0;
}
signed main() {
    freopen("hub.in", "r", stdin);
    freopen("hub.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> c >> t;
    while(t --) {
        Main();
    }
    cerr << clock() * 1.0 / CLOCKS_PER_SEC << "\n";
    return 0;
}
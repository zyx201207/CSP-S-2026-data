#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;
int c, TC, n, k, dis[N], S, T, fp[N], path[N], m = 0, ok[N];
vector<int> G[N]; 
void dfs(int u, int fa) {
    dis[u] = dis[fa] + 1, fp[u] = fa;
    for (int v : G[u]) if (v != fa) dfs(v, u);
}
int lim;
int depS[N], depT[N], valS[N], valT[N], dst[N], f1[20][N], f2[20][N], lg[N];
void dfs1(int u, int fa, int *val, int *dep) {
    dep[u] = 0, val[u] = 1;
    for (int v : G[u]) if (v != fa) {
        dfs1(v, u, val, dep);
        val[u] += val[v] * (dep[v] + 1 > lim);
        dep[u] = max(dep[u], dep[v] + 1);
    }
}
void dfs2(int u, int fa) {
    dst[u] = 0;
    for (int v : G[u]) if (v != fa && !ok[v]) {
        dfs2(v, u);
        dst[u] = max(dst[u], dst[v] + 1);
    }
}
int ask1(int l, int r) {
    if (l > r) return -1e9;
    int s = lg[r - l + 1];
    return max(f1[s][l], f1[s][r - (1 << s) + 1]);
}
int ask2(int l, int r) {
    if (l > r) return -1e9;
    int s = lg[r - l + 1];
    return max(f2[s][l], f2[s][r - (1 << s) + 1]);
} 
int to1[N], to2[N];
bool check(int vvv) {
    lim = vvv;
    dfs1(S, 0, valS, depS), dfs1(T, 0, valT, depT);
    int mnx = n;
    for (int i = 1, j = 0; i <= m; i++) {
        while (j + 1 <= m && ask1(i + 1, j + 1) - i <= lim) {
            j++;
            to1[j] = valS[path[i]];
        }
    }
    for (int i = m, j = m + 1; i >= 1; i--) {
        while (j - 1 >= 1 && ask2(j - 1, i - 1) + i <= lim) {
            j--;
            to2[j] = valT[path[i]];
        }
    }    
    for (int i = 1; i < m; i++) mnx = min(mnx, to1[i] + to2[i + 1]);
    return mnx <= k;
} 
void solve() {
    cin >> n >> k, m = 0;
    for (int i = 1; i <= n; i++) G[i].clear(), ok[i] = 0;
    for (int i = 1, u, v; i < n; i++) {
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    if (k == n) {
        cout << 0 << endl;
        return;
    }
    dfs(1, 0);
    S = max_element(dis + 1, dis + 1 + n) - dis;
    dfs(S, 0);
    T = max_element(dis + 1, dis + 1 + n) - dis;
    for (int i = T; i; i = fp[i]) path[++m] = i, ok[i] = 1;
    for (int i = 1; i <= m; i++) dfs2(path[i], 0);
    lg[0] = -1;
    for (int i = 1; i <= m; i++) lg[i] = lg[i >> 1] + 1;
    
    for (int i = 1; i <= m; i++) {
        f1[0][i] = i + dst[path[i]];
        f2[0][i] = -i + dst[path[i]];
    }
    for (int j = 1; j <= lg[m]; j++) {
        for (int i = 1; i + (1 << j) - 1 <= m; i++) {
            f1[j][i] = max(f1[j - 1][i], f1[j - 1][i + (1 << (j - 1))]);
            f2[j][i] = max(f2[j - 1][i], f2[j - 1][i + (1 << (j - 1))]);
        }
    }
    int L = 1, R = n, ans = n;
    while (L <= R) {
        int mid = (L + R) >> 1;
        if (check(mid)) ans = mid, R = mid - 1;
        else L = mid + 1;
    }
    cout << ans << endl;
}
int main() {
    freopen("hub.in","r", stdin);
    freopen("hub.out","w", stdout);

    cin.tie(0)->sync_with_stdio(false);
    cin >> c >> TC;
    while (TC--) solve();
    return 0;
}
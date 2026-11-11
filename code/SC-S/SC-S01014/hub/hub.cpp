#include <bits/stdc++.h>
using namespace std;

template <typename T> void read(T &x) {
    x = 0; int f = 1; char ch = getchar();
    while (!isdigit(ch)) f = (ch == '-') ? -1 : f, ch = getchar();
    while (isdigit(ch)) x = x * 10 + (ch & 15), ch = getchar(); x *= f;
}


namespace sub0 {
    const int N = 25;
    vector<int> e[N];
    int n, m, k, dis[N];
    
    void solve() {
        read(n), read(k);
        for (int i = 1; i <= n; i++) e[i].clear();
        for (int i = 1, u, v; i < n; i++) {
            read(u), read(v);
            e[u].push_back(v);
            e[v].push_back(u);
        }
        if (n == k) {
            puts("0"); return ;
        }
        
        int ans = n;
        for (int S = 0; S < (1 << n); S++) {
            if (__builtin_popcount(S) != k) continue;
            int mxd = 0;
            for (int i = 0; i < n; i++)
                dis[i + 1] = (S >> i & 1) ? 0 : n + 1;
            int cnt = k;
            for (int u = 1; u <= n; u++) if (S >> (u - 1) & 1)
                for (auto v : e[u]) if (S >> (v - 1) & 1) cnt--;
            if (cnt > 2) continue;
            queue<int> Q;
            for (int i = 1; i <= n; i++)
                if (!dis[i]) Q.push(i);
            while (!Q.empty()) {
                int u = Q.front(); Q.pop();
                mxd = max(mxd, dis[u]);
                for (auto v : e[u]) if (dis[v] > dis[u] + 1)
                    dis[v] = dis[u] + 1, Q.push(v);
            }
            ans = min(ans, mxd);
        }
        printf("%d\n", ans);
    }
}

namespace sub1 {
    const int N = 1005;
    vector<int> e[N];
    int n, m, k, sz[N];
    int f1[N * 2][3], f2[3], g2[3];
    int f[N][N * 2][2][3], g1[N * 2][3];
    void chkmin(int &x, int y) { x = min(x, y); }
    
    void dfs(int u, int fa) {
        for (int i = N - m; i <= N + m; i++)
            for (int y = 0; y <= 2; y++)
                f[u][i][0][y] = f[u][i][1][y] = k + 1;
        
        sz[u] = 1;
        for (auto v : e[u]) if (v ^ fa)
            dfs(v, u), sz[u] += sz[v];
        if (sz[u] == 1) {
            f[u][N][0][0] = 0;
            f[u][N + m][1][1] = 1;
            return ;
        }
        
        { // not using u
            for (int i = N - m; i <= N + m; i++)
                for (int y = 0; y <= 2; y++) f1[i][y] = k + 1;
            f1[N][0] = 0;
            for (auto v : e[u]) if (v ^ fa) {
                for (int i = N - m; i <= N + m; i++)
                    for (int y = 0; y <= 2; y++) g1[i][y] = k + 1;
                
                for (int i = N - m; i <= N + m; i++)
                    for (int j = N - m + 1; j <= N + m; j++)
                        for (int yi = 0; yi <= 2; yi++) for (int yj = 0; yi + yj <= 2; yj++) {
                            int x = j - 1 - N, y = i - N;
                            int t = (abs(y) > abs(x) ? i : j - 1);
                            chkmin(g1[t][yi + yj], f1[i][yi] + min(f[v][j][0][yj], f[v][j][1][yj]));
                        }
                for (int i = N - m; i <= N + m; i++)
                    for (int y = 0; y <= 2; y++) f1[i][y] = g1[i][y];
            }
        }
        { // using u
            f2[0] = f2[2] = k + 1, f2[1] = 1;
            for (auto v : e[u]) if (v ^ fa) {
                for (int y = 0; y <= 2; y++) g2[y] = k + 1;
                
                for (int j = N - m + 1; j <= N + m; j++)
                    for (int yi = 1; yi <= 2; yi++) for (int yj = 0; yj <= 2; yj++) {
                        if (yi + yj <= 2) chkmin(g2[yi + yj], f2[yi] + f[v][j][0][yj]);
                        if (yi + yj <= 3) chkmin(g2[yi + yj - 1], f2[yi] + f[v][j][1][yj]);
                    }
                for (int y = 0; y <= 2; y++) f2[y] = g2[y];
            }
        }
        
        for (int i = N - m; i <= N + m; i++)
            for (int x = 0; x <= 2; x++) f[u][i][0][x] = f1[i][x];
        for (int x = 0; x <= 2; x++) f[u][N + m][1][x] = f2[x];
        
//        printf("u = %d\n", u);
//        for (int i = N - m; i <= N + m; i++)
//            for (int x = 0; x <= 1; x++) for (int y = 0; y <= 2; y++) if (f[u][i][x][y] <= k) {
//                printf("f[%d][%d][%d][%d] = %d\n", u, i - N, x, y, f[u][i][x][y]);
//            }
//        puts("");
    }
    
    bool chk(int M) {
        m = M, dfs(1, 0);
        for (int i = 0; i <= m; i++)
            for (int x = 0; x < 2; x++)
                for (int y = 0; y < 3; y++)
                    if (f[1][N + i][x][y] <= k) return true;
        return false;
    }
    
    void solve() {
        read(n), read(k);
        for (int i = 1; i <= n; i++) e[i].clear();
        for (int i = 1, u, v; i < n; i++) {
            read(u), read(v);
            e[u].push_back(v);
            e[v].push_back(u);
        }
        if (n == k) {
            puts("0"); return ;
        }
        
        int l = 1, r = (n + 1) / 2;
        if (k >= 2) r = (n + 2) / 3;
        int ans = r;
        while (l <= r) {
            int mid = (l + r) >> 1;
            if (!chk(mid)) l = mid + 1;
            else ans = mid, r = mid - 1;
        }
        printf("%d\n", ans);
    }
}

namespace subA {
    const int N = 100005;
    vector<int> e[N];
    int n, m, k, dis[N];
    
    void solve() {
        read(n), read(k);
        for (int i = 1; i <= n; i++) e[i].clear();
        for (int i = 1, u, v; i < n; i++) {
            read(u), read(v);
            e[u].push_back(v);
            e[v].push_back(u);
        }
        if (n == k) {
            puts("0"); return ;
        }
        if (k >= n / 2) {
            puts("1"); return ;
        }
        int ans = n;
        for (int l = 0; l <= n; l++) {
            int cur = (l + 1) / 2 + 1;
            int d = n / 2 - l - k;
            if (d > 0) cur = max(cur, (d + 1) / 2 + 1);
            ans = min(ans, cur);
        }
        printf("%d\n", ans);
    }
}

signed main() {
    freopen("hub.in", "r", stdin);
    freopen("hub.out", "w", stdout);
//    freopen("hub5.in", "r", stdin);
//    freopen("my-hub.out", "w", stdout);
    
    int c, T;
    read(c), read(T);
    if (c <= 3) {
        while (T--) sub0::solve();
        return 0;
    }
    if (c >= 13 && c <= 14) {
        while (T--) subA::solve();
        return 0;
    }
//    if (c <= 8) {
        while (T--) sub1::solve();
        return 0;
//    }
    return 0;
}
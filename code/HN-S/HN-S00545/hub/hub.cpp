#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e5 + 5;
int n, k, cnt;
bool vis[N];
vector<int> g[N];
bitset<N> f[N], p;
using PII = pair<int, int>;
inline void dfs(int x, int fa, int s) {
    vis[x] = 1;
    cnt++;
    for(int y : g[x]) {
        if(y == fa || !(s >> y - 1 & 1)) continue;
        dfs(y, x, s);
    }
}
inline bool check(int mid) {
    for(int i = 1; i <= n; i++) f[i].reset();
    for(int i = 1; i <= n; i++) {
        fill(vis, vis + 1 + n, 0);
        queue<PII> q;
        q.push({i, 0}), vis[i] = 1;
        while(q.size()) {
            auto [x, s] = q.front(); q.pop();
            f[i][x] = 1;
            if(s >= mid) continue;
            for(int y : g[x]) {
                if(!vis[y]) vis[y] = 1, q.push({y, s + 1});
            }
        }
    }
    if(k <= 2) {
        for(int i = 1; i <= n; i++) {
            for(int j = i + 1; j <= n; j++) {
                p = (f[i] | f[j]);
                bool fl = 0;
                for(int l = 1; l <= n; l++) if(!p[i]) {
                    fl = 1;
                    break;
                }
                if(!fl) return 1;
            }
        }
        return 0;
    }
    // for(int i = 1; i <= n; i++) {
    //     for(int j = 1; j <= n; j++) cerr << f[i][j] << ' ';
    //     cerr << endl;
    // }
    for(int s = 1; s < 1 << n; s++) {
        if(__builtin_popcount(s) > k) continue;
        p.reset();
        for(int i = 1; i <= n; i++) {
            if(s >> i - 1 & 1) p |= f[i];
        }
        bool fl = 0;
        for(int i = 1; i <= n; i++) if(!p[i]) {
            fl = 1;
            break;
        }
        if(!fl) {
            fill(vis, vis + 1 + n, 0);
            int cnt = 0;
            for(int i = 1; i <= n; i++) if(s >> i - 1 & 1 && !vis[i]) dfs(i, 0, s), cnt++;
            // cerr << cnt << endl;
            if(cnt <= 2) {
                // for(int i = 1; i <= n; i++) if(s >> i - 1 & 1) cerr << i << ' ';
                // cerr << endl;
                // // cerr << n << '\n';
                // for(int i = 1; i <= n; i++) cerr << p[i] << ' ';
                // cerr << endl;
                return 1;
            }
        }
    }
    return 0;
}
inline void solve() {
    cin >> n >> k;
    for(int i = 1; i <= n; i++) g[i].clear();
    for(int i = 1, x, y; i < n; i++) {
        cin >> x >> y;
        g[x].push_back(y), g[y].push_back(x);
    }
    int lt = 0, rt = n + 1;
    while(lt + 1 < rt) {
        int mid = lt + rt >> 1;
        if(check(mid)) rt = mid;
        else lt = mid;
    }
    cout << rt << '\n';
    // cout << check(1) << '\n';
}
namespace sub {
    inline void solve() {
        cin >> n >> k;
        for(int i = 1; i <= n; i++) g[i].clear();
        for(int i = 1, x, y; i < n; i++) {
            cin >> x >> y;
            g[x].push_back(y), g[y].push_back(x);
        }
        int m = n / 2;
        int p = (m + 1 - k) / 4;
        cout << p + 1 << '\n';
    }
}
signed main() {
    freopen("hub.in", "r", stdin);
    freopen("hub.out", "w", stdout);
    // freopen("err.out", "w", stderr);
    cin.tie(0) -> sync_with_stdio(0);
    int c, t;
    cin >> c >> t;
    // t=1;
    if(c == 13 || c == 14) {
        while(t--) sub::solve();
        return 0;
    }
    while(t--) solve();
    return 0;
}
/*
乐扣保佑！！！！！！
*/
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = a; i <= b; ++i)
#define ll long long
#define make_pair m_p
using namespace std;
int read() {
    int w = 0, f = 1;
    char c = getchar();
    while(c < '0' || c > '9') {
        if(c == '-') {
            f = -f;
        }
        c = getchar();
    }
    while('0' <= c && c <= '9') {
        w = w * 10 + c - '0';
        c = getchar();
    }
    return w * f;
}
void write(int x) {
    if(x < 0) {
        putchar('-');
        x = -x;
    }
    if(x > 9) {
        write(x / 10);
    }
    putchar(x % 10 + '0');
}
const int N = 1e6 + 5;
int c, tot, t, n, k, u, v, ans;
int fa[N], cnt[N], mark[N], dep[N];
vector<int> e[N];
int find(int x) {
    return fa[x] == x ? fa[x] : fa[x] = find(fa[x]);
}
inline void merge(int x, int y) {
    int fx = find(x), fy = find(y);
    if(fx != fy) {
        fa[fx] = fy;
    }
}
void dfs(int s, int fa) {
    dep[s] = dep[fa] + 1;
    for(const int to : e[s]) {
        if(to == fa) {
            continue;
        }
        dfs(to, s);
    }
}
void solve() {

    n = read(), k = read();
    rep(i, 1, n) {
        e[i].clear();
    }
    rep(i, 1, n - 1) {
        u = read(), v = read();
        e[u].push_back(v);
        e[v].push_back(u);
    }
    ans = n + 1;
    rep(s, 0, (1 << n) - 1) {
        if(__builtin_popcount(s) == k) {
            tot = 0;
            fill(mark, mark + n + 1, 0);
            rep(i, 1, n) {
                fa[i] = i;
                cnt[i] = 0;
            }
            rep(i, 1, n) {
                if(s & (1 << i - 1)) {
                    mark[i] = 1;
                }
            }
            rep(i, 1, n) {
                if(!mark[i]) {
                    continue;
                }
                for(const int to : e[i]) {
                    if(mark[to]) {
                        merge(to, i);
                    }
                }
            }
            rep(i, 1, n) {
                if(mark[i]) {
                    if(cnt[find(i)] == 0) {
                        ++tot;
                    }
                    cnt[find(i)]++;
                }
            }
            if(tot <= 2) {
                int res = 0;
                rep(i, 1, n) {
                    if(!mark[i]) {
                        int d = n + 1;
                        dfs(i, 0);
                        rep(j, 1, n) {
                            if(mark[j]) {
                                d = min(d, dep[j] - 1);
                            }
                        }
                        res = max(res, d);
                    }
                }
                ans = min(ans, res);
            }
        }
    }
    write(ans);
    putchar('\n');
}

int main() {
        freopen("hub.in", "r", stdin);
    freopen("hub.out", "w", stdout);
    c = read(), t = read();
    while(t--) {
        solve();
    }
    return 0;
}
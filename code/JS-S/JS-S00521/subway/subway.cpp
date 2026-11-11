#include <bits/stdc++.h>
#define re register
#define fir first
#define sec second
#define int long long
#define gc getchar
#define pc putchar
#define pck putchar(' ');
#define pcn putchar('\n');
#define mp make_pair
#define pb push_back
#define MAXN 500005
#define INF 50000000000000
#define min(a, b) a < b ? a : b
using namespace std;
int c, n, m, dd, qq;
int w[MAXN];
priority_queue<pair<int, int> > q;
int d[505][505];
bool vis[505];
int g[505][505];
vector<pair<int, int> > a[MAXN];
inline void free() {
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
}
inline int rd() {
    int x = 0, sig = 1;
    char ch = gc();
    for (; ch > '9' || ch < '0'; ch = gc())
        if (ch == '-') sig = -1;
    for (; ch >= '0' && ch <= '9'; ch = gc())
        x = (x << 3) + (x << 1) + (ch ^ 48);
    return x * sig;
}
inline void write(int x) {
    if (x < 10) {
        pc(x ^ 48);
        return;
    }
    write(x / 10);
    pc(x % 10 ^ 48);
}
inline void wt(int x) {
    if (x < 0) {
        pc('-');
        x = -x;
    }
    write(x);
    pcn;
}
signed main() {
    free();
    c = rd();
    n = rd();
    m = rd();
    dd = rd();
    qq = rd();
    for (re int i = 1; i <= m; i++)
        w[i] = rd();
    for (re int i = 1; i <= n; i++) {
        int k = rd();
        for (re int j = 1; j <= k; j++) {
            int _1 = rd(), _2 = rd();
            a[_1].pb(mp(i, _2));
        }
    }
    for (re int i = 0; i <= n + 1; i++)
        for (re int j = 0; j <= n + 1; j++)
            g[i][j] = INF;
    for (re int i = 1; i <= m; i++)
        for (re int j = 0; j < a[i].size() - 1; j++)
            for (re int k = j + 1; k < a[i].size(); k++)
                g[a[i][j].fir][a[i][k].fir] = g[a[i][k].fir][a[i][j].fir] = min(g[a[i][j].fir][a[i][k].fir], a[i][j].sec + a[i][k].sec);
    for (re int x = 1; x <= n; x++) {
        while (!q.empty())
            q.pop();
        for (re int i = 0; i <= n + 1; i++) {
            vis[i] = 0;
            d[x][i] = INF;
        }
        d[x][x] = 0;
        q.push(mp(0, x));
        while (!q.empty()) {
            int u = q.top().sec;
            q.pop();
            if (vis[u]) continue;
            vis[u] = 1;
            for (re int i = 1; i <= n; i++) {
                int v = i, w = g[u][i];
                if (!vis[v] && d[x][u] + w < d[x][v]) {
                    d[x][v] = d[x][u] + w;
                    q.push(mp(-d[x][v], v));
                }
            }
        }
    }
    while (qq--) {
        int x, y;
        int ans = INF;
        x = rd();
        y = rd();
        for (re int i = 0; i < a[x].size(); i++)
            for (re int j = 0; j < a[y].size(); j++)
                ans = min(ans, d[a[x][i].fir][a[y][j].fir] + a[x][i].sec + a[y][j].sec);
        ans += w[x] + w[y];
        wt(ans);
    }
    return 0;
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2
*/

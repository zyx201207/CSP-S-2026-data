#include <bits/stdc++.h>
#define int long long
using namespace std;
inline int read() {
    int x = 0, flg = 0;
    char c = getchar();
    while (!isdigit(c)) {
        flg |= c == '-';
        c = getchar();
    }
    while (isdigit(c)) {
        x = x * 10 + (c ^ 48);
        c = getchar();
    }
    return flg ? -x : x;
}
inline void write(int x, char div = '\n') {
    if (!x) {
        putchar('0'), putchar(div);
        return;
    }
    string s = "";
    if (x < 0) {
        putchar('-'), x = -x;
    }
    while (x) {
        s = char(x % 10 + '0') + s;
        x /= 10;
    }
    for (char c : s) {
        putchar(c);
    }
    putchar(div);
}
const int N = 500 + 5;
const int M = 5e5 + 5;
const int inf = 1e18;
int n, m, q, d, subtasks;
int w[M];
struct Node {
    int u, t;
    Node() {}
    Node(int _u, int _t) {
        u = _u, t = _t;
    }
};
int k[N];
vector <Node> a[N];
struct Station {
    int line, t;
    Station() {}
    Station(int _l, int _t) {
        line = _l, t = _t;
    }
};
vector <Station> st[M];
int line[N][N];
inline void addEdge(int u, int v, int w) {
    line[u][v] = line[v][u] = min(line[u][v], w);
}
signed main() {
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    subtasks = read(), n = read(), m = read(), d = read(), q = read();
    for (int i = 1; i <= m; i++) {
        w[i] = read();
    }
    for (int i = 1; i <= n; i++) {
        k[i] = read();
        for (int j = 1, u, t; j <= k[i]; j++) {
            u = read(), t = read();
            a[i].push_back(Node(u, t));
            st[u].push_back(Station(i, t));
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            line[i][j] = inf;
        }
        line[i][i] = 0;
    }
    for (int i = 1, sz; i <= m; i++) {
        sz = st[i].size();
        for (int u = 0; u < sz; u++) {
            for (int v = u + 1; v < sz; v++) {
                addEdge(st[i][u].line, st[i][v].line, st[i][u].t + st[i][v].t);
            }
        }
    }
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                addEdge(i, j, line[i][k] + line[k][j]);
            }
        }
    }
    for (int i = 1, u, v, res; i <= q; i++) {
        u = read(), v = read(), res = inf;
        for (Station x : st[u]) {
            for (Station y : st[v]) {
                res = min(res, line[x.line][y.line] + x.t + y.t);
            }
        }
        write(w[u] + w[v] + res);
    }
    return 0;
}

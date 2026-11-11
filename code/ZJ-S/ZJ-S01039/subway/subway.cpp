#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pr pair<int, int>
#define pb push_back
#define mid (l + r) / 2
#define ls num << 1
#define rs num << 1 | 1

inline int read() {
    int x = 0, m = 1;
    char ch = getchar();
    while (!isdigit(ch)) {
        if (ch == '-') m = -1;
        ch = getchar();
    }
    while (isdigit(ch)) {
        x = x * 10 + ch - 48;
        ch = getchar();
    }
    return x * m;
}

inline void write(int x) {
    if (x < 0) {
        putchar('-');
        write(-x);
        return;
    }
    if (x >= 10) write(x / 10);
    putchar(x % 10 + '0');
}

const int N = 5e5 + 5, M = 505, D = 21, inf = 1e13;

int a[N];
int f[M][M];
vector<pr> w[N];

signed main() {
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    int synAKIOI = read(), n = read(), m = read(), d = read(), q = read();
    for (int i = 1; i <= m; i++) a[i] = read();
    for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++) f[i][j] = (i == j) ? 0 : inf;
    for (int i = 1; i <= n; i++) {
        int k = read();
        for (int j = 1; j <= k; j++) {
            int x = read(), y = read();
            for (auto [X, Y] : w[x]) {
                f[X][i] = min(f[X][i], Y + y);
                f[i][X] = min(f[i][X], Y + y);
            }
            w[x].pb({i, y});
        }
    }
    for (int k = 1; k <= n; k++) for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++) f[i][j] = min(f[i][j], f[i][k] + f[k][j]);
    while (q--) {
        int x = read(), y = read();
        int ans = inf;
        for (auto [x1, y1] : w[x]) for (auto [x2, y2] : w[y]) ans = min(ans, a[x] + a[y] + y1 + y2 + f[x1][x2]);
        write(ans);
        putchar('\n');
    }
}
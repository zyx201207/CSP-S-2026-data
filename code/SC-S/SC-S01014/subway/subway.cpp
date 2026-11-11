#include <bits/stdc++.h>
#define ll long long
using namespace std;

template <typename T> void read(T &x) {
    x = 0; int f = 1; char ch = getchar();
    while (!isdigit(ch)) f = (ch == '-') ? -1 : f, ch = getchar();
    while (isdigit(ch)) x = x * 10 + (ch & 15), ch = getchar(); x *= f;
}
template <typename T> void write(T x) {
    if (x < 0) putchar('-'), x = -x;
    static short Stack[30], top(0);
    do Stack[++top] = x % 10; while (x /= 10);
    while (top) putchar(Stack[top--] | 48);
    putchar('\n');
}

const int N = 505, M = 500005;
int sta[M][21], T[M][21], cnt[M];
int c, n, m, d, q, w[M]; ll f[N][N];

signed main() {
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
//    freopen("subway7.in", "r", stdin);
//    freopen("my-subway.out", "w", stdout);
    
    read(c), read(n), read(m), read(d), read(q);
    for (int i = 1; i <= m; i++) read(w[i]);
    for (int i = 1; i <= n; i++) {
        int k; read(k);
        for (int x = 1; x <= k; x++) {
            int a, t; read(a), read(t);
            ++cnt[a], sta[a][cnt[a]] = i, T[a][cnt[a]] = t;
        }
    }
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++) f[i][j] = (ll)1e18;
    for (int i = 1; i <= n; i++) f[i][i] = 0;
    
    for (int i = 1; i <= m; i++) {
        int *st = sta[i];
        for (int x = 1; x <= cnt[i]; x++)
            for (int y = x + 1; y <= cnt[i]; y++) {
                ll d = min(f[st[x]][st[y]], (ll)T[i][x] + T[i][y]);
                f[st[x]][st[y]] = f[st[y]][st[x]] = d;
            }
    }
    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                f[i][j] = min(f[i][j], f[i][k] + f[k][j]);
    
    while (q--) {
        int x, y; ll ans = (ll)1e18;
        read(x), read(y);
        for (int i = 1; i <= cnt[x]; i++)
            for (int j = 1; j <= cnt[y]; j++) {
                ans = min(ans, f[sta[x][i]][sta[y][j]] + T[x][i] + T[y][j]);
            }
        write(ans + w[x] + w[y]);
    }
    return 0;
}
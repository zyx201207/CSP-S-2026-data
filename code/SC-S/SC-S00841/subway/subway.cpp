#include <bits/stdc++.h>
using namespace std;
typedef long long LLD;
const int N = 510, M = 5e5 + 10;
int TASK_ID, n, m, DEG, q, w[M];
LLD d[N][N];
vector <pair <int, int> > su[M];

namespace Read {
    char ib[1 << 16], *is = ib, *it = ib;
    inline char getch() { return (is == it && ((it = ib + fread(is = ib, 1, 1 << 16, stdin)), is == it)) ? EOF : *is++; }
    inline int read() {
        int x = 0;
        char ch = getch();
        while (ch < '0' || ch > '9') ch = getch();
        while (ch >= '0' && ch <= '9') {
            x = x * 10 + (ch ^ 48);
            ch = getch();
        }
        return x;
    }
} using namespace Read;

int main() {
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    TASK_ID = read(), n = read(), m = read(), DEG = read(), q = read();
    for (int i = 1; i <= m; ++i) w[i] = read();
    for (int i = 1; i <= n; ++i) {
        int siz;
        siz = read();
        for (int j = 0; j < siz; ++j) {
            int pl, wei;
            pl = read(), wei = read();
            su[pl].push_back({ i, wei });
        }
    }
    memset(d, 0x3f, sizeof d);
    for (int i = 1; i <= n; ++i) d[i][i] = 0;
    for (int i = 1; i <= m; ++i)
        for (int j = 0; j < (int)su[i].size(); ++j)
            for (int k = j + 1; k < (int)su[i].size(); ++k) {
                int u = su[i][j].first, v = su[i][k].first;
                LLD wei = su[i][j].second + su[i][k].second;
                d[u][v] = min(d[u][v], wei);
                d[v][u] = min(d[v][u], wei);
            }
    for (int k = 1; k <= n; ++k)
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= n; ++j)
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
    while (q--)  {
        int u, v;
        u = read(); v = read();
        LLD ans = 0x3f3f3f3f3f3f3f3f;
        for (int j = 0; j < (int)su[u].size(); ++j)
            for (int k = 0; k < (int)su[v].size(); ++k) {
                int p = su[u][j].first, q = su[v][k].first;
                LLD val = su[u][j].second + su[v][k].second + d[p][q];
                ans = min(ans, val);
            }
        printf("%lld\n", ans + w[u] + w[v]);
    }
    fflush(stdout); fclose(stdin), fclose(stdout);
    return 0;
}
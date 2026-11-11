#include <bits/stdc++.h>

using namespace std;

#define int long long // sikaoyifan...
#define endl '\n'
#define gc getchar
#define PII pair<int, int> 

int read() {
    int x = 0, f = 1;
    char c = gc();
    while (!isdigit(c)) {
        if (c == '-') f = -1;
        c = gc();
    }
    while (isdigit(c)) {
        x = x * 10 + (c - '0');
        c = gc();
    }
    return x * f;
}

const int N = 5010;

int ID, n, m, d, q;
int w[N], t[N][N], k[N], a[N][N];
int dist[N][N];
int id[N], idx, ids[N], cnt[N][N];
int nt;

void floyd() {
    for (int u = 1; u <= nt; u ++ )
        for (int i = 1; i <= nt; i ++ )
            for (int j = 1; j <= nt; j ++ )
                dist[i][j]  = min(dist[i][u] + dist[u][j], dist[i][j]);
}

signed main() {
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);

    ID = read(), n = read(), m = read(), d = read(), q = read();
    memset(dist, 0x3f, sizeof dist);
    for (int i = 1; i <= m; i ++ ) w[i] = read();

    for (int i = 1; i <= m; i ++ ) {
        id[i] = ++ idx;
        ids[i] = ++ idx;
        dist[id[i]][ids[i]] = w[i];
        dist[ids[i]][id[i]] = w[i];
    }

    for (int i = 1; i <= n; i ++ ) {
        k[i] = read();
        for (int j = 1; j <= k[i]; j ++ ) {
            a[i][j] = read(), t[i][j] = read();
            int x = ++ idx;
            cnt[i][j] = x;
            dist[x][ids[a[i][j]]] = t[i][j];
            dist[ids[a[i][j]]][x] = t[i][j];
            if (j > 1) dist[x][cnt[i][j - 1]] = 0, dist[cnt[i][j - 1]][x] = 0;
        }
    }

    for (int i = 1; i <= idx; i ++ ) dist[i][i] = 0;
    nt = idx;
    floyd();
    for (int i = 1; i <= q; i ++ ) {
        int x = read(), y = read();
        printf("%lld\n", dist[id[x]][id[y]]);
    }
    //cerr << "time use: " << 1. * clock() / CLOCKS_PER_SEC << endl;
    return 0; 
}
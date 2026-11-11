#include<bits/stdc++.h>
using namespace std;
const int MAXN = 505;
const int MAXM = 1005;
int c, n, m, d, q;
int G[MAXM][MAXM];
long long f[MAXM][MAXM];
int w[MAXM], k[MAXN];
int a[MAXN][MAXM], t[MAXN][MAXM];
void read(int &x)
{
    int res = 0, f = 1, ch = getchar();
    while (!isdigit(ch)) {
        if (ch == '-') f = -1;
        ch = getchar();
    }
    while (isdigit(ch)) {
        res = (res << 1) + (res << 3) + ch - '0';
        ch = getchar();
    }
    x = res * f;
}
int main()
{
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    read(c), read(n), read(m), read(d), read(q);//cin >> c >> n >> m >> d >> q;
    for (int i = 1; i <= m; i++) {
        read(w[i]);//cin >> w[i];
    }
    for (int i = 1; i <= n; i++) {
        read(k[i]);//cin >> k[i];
        for (int j = 1; j <= k[i]; j++) {
            read(a[i][j]), read(t[i][j]);//cin >> a[i][j] >> t[i][j];
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j1 = 1; j1 <= k[i]; j1++) {
            for (int j2 = 1; j2 <= k[i]; j2++) {
                G[a[i][j1]][a[i][j2]] = t[i][j1] + t[i][j2]; 
            }
        }
    }
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= m; j++) {
            if (G[i][j] == 0) {
                f[i][j] = INT_MAX;
                continue;
            }
            f[i][j] = G[i][j];
        }
    }
    for (int i = 1; i <= m; i++) {
        f[i][i] = 0;
    }
    for (int k = 1; k <= m; k++) {
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= m; j++) {
                f[i][j] = min(f[i][j], f[i][k] + f[k][j]);
            }
        }
    }
    while (q--) {
        int x, y;
        cin >> x >> y;
        cout << f[x][y] + w[x] + w[y] << '\n';
    }
    /*for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= m; j++) {
            cout << f[i][j] << ' ';
        }
        cout << '\n';
    }*/
    return 0;
}
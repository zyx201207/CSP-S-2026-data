//quan yuan zui duan lu?
// I only remember Kruscal
//O(n^3+q*(d^2))? 50pts
// dan fan n<=400 dou guo le
// scan your QR code CCF and CSP

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int c, n, m, d, q;
ll G[505][505];
int w[500005], a[500005][22], cnt[500005];
int t[501][500005];
int k, p, tp;
int x, y;

int main() {

    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);

    scanf("%d %d %d %d %d", &c, &n, &m, &d, &q);
    for(int i=1; i<=m; i++) scanf("%d", &w[i]);
    for(int i=1; i<=n; i++) {
        scanf("%d", &k);
        for(int j=0; j<k; j++) {
            scanf("%d %d", &p, &tp);
            a[p][++cnt[p]] = i;
            t[i][p] = tp;
        }
    }
    memset(G, 0x3f, sizeof(G));
    for(int i=1; i<=m; i++) {
        if(cnt[i] >= 2) {
            for(int j=1; j<cnt[i]; j++) {
                for(int l=j+1; l<=cnt[i]; l++) {
                    int jj = a[i][j], ll = a[i][l];
                    G[jj][ll] = G[ll][jj] = min((long long)(t[jj][i] + t[ll][i]), G[jj][ll]);
                }
            }
        }
    }
    for(int i=1; i<=n; i++) {
        G[i][i] = 0;
        for(int j=1; j<=n; j++) {
            for(int l=n; l>=1; l--) {
                G[i][j] = min(G[i][j], G[i][l] + G[l][j]);
            }
        }
    }
    while(q--) {
        scanf("%d %d", &x, &y);
        ll ans = 0x7fffffffffffffff;
        for(int i=1; i<=cnt[x]; i++) {
            for(int j=1; j<=cnt[y]; j++) {
                int ii = a[x][i], jj = a[y][j];
                ans = min(ans, G[ii][jj] + t[ii][x] + t[jj][y]);
            }
        }
        printf("%lld\n", ans + w[x] + w[y]);
    }
    return 0;
}

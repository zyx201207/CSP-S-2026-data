#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int maxm = 5e5 + 5;
const int maxq = 1e5 + 5;
const int maxn = 505;
const int maxd = 25;
int w[maxm];
int a[maxn][maxm];
int t[maxn][maxm];

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    int c, n, m, d, q;
    cin >> c >> n >> m >> d >> q;
    for (int i = 1; i <= m; i++) {
        cin >> w[i];
    }
    for (int i = 1; i <= n; i++) {
        int k;
        cin >> k;
        for (int j = 1; j <= k; j++) {
            cin >> a[i][j] >> t[i][j];
        }
    }
    for (int r = 1; r <= q; r++) {
        int x, y;
        cin >> x >> y;
    }

    return 0;
}

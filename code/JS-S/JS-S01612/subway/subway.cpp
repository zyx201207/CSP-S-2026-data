#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 500 + 7;


ll a[N];
ll g[N][N];
ll wer[N];
ll sdf[N];


int main() {
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);
    int c, n, m, d, q;
    cin >> c >> n >> m >> d >> q;
    for (int i = 1; i <= m; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= m; j++) if (i != j) g[i][j] = 0x3f3f3f3f;

    for (int i = 1; i <= n; i++) {
        int k;
        cin >> k;
        for (int j = 1; j <= k; j++) {

            cin >> wer[j] >> sdf[j]; // wer zhantai  sdf val
        }
        for (int j = 1; j <= k; j++) {
            for (int z = 1; z <= k; z++) {
                if (z != j) g[wer[j]][wer[z]] = min(g[wer[j]][wer[z]], sdf[j] + sdf[z]);
            }
        }
    }
    for (int k = 1; k <= m; k++) {
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= m; j++) {
                if (i != j && i != k && j != k)
                g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
            }
        }
    }

    while (q--) {
        int x, y;
        cin >> x >> y;
        cout << g[x][y] + a[x] + a[y] << "\n";
    }

    return 0;
}

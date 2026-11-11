#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 105;
const int INF = 1e9 + 7;

int c, n, m, d, q;
int w[MAX_N];
int k[MAX_N], a[MAX_N][MAX_N], t[MAX_N][MAX_N];
vector <pair <int, int> > cnt[MAX_N];
int x, y;
vector <pair <int, int> > G[MAX_N];

int main () {
    freopen ("subway.in", "r", stdin);
    freopen ("subway.out", "w", stdout);

    ios::sync_with_stdio (false);
    cin.tie (0); cout.tie (0);

    cin >> c >> n >> m >> d >> q;
    for (int i = 1; i <= m; i++) cin >> w[i];
    for (int i = 1; i <= n; i++) {
        cin >> k[i];
        for (int j = 1; j <= k[i]; j++) {
            cin >> a[i][j] >> t[i][j];
            cnt[a[i][j]].push_back ({i, t[i][j]});
        }
    }
    while (q--) {
        cin >> x >> y;
        if (y < x) swap (x, y);
        if (n <= 3) {
            int sum = INF;
            for (int i = 1; i <= n; i++) {
                for (int j = 1; j <= k[i]; j++) {
                    if (a[i][j] == x) {
                        if (a[i][j + 1] == y) sum = min (sum, t[i][j + 1] + t[i][j]);
                        else if (a[i][j + 2] == y) sum = min (sum, t[i][j + 1] + t[i][j]);

                    } else if (a[i][j] == y) {
                        if (a[i][j + 1] == x) sum = min (sum, t[i][j + 1] + t[i][j]);
                        else if (a[i][j + 2] == x) sum = min (sum, t[i][j + 1] + t[i][j]);
                    }
                }
            }
            cout << w[x] + w[y] + sum << endl;
        }
    }
    return 0;
}

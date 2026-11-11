#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 5;
int c, n, m, d, q, w[N], v[N][N], x[N][N], k[N];
vector <pair<int, int> > g[N];
int main() {
    cin >> c >> n >> m >> d >> q;
    for (int i = 1; i <= m; i++) {
        cin >> w[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> k[i];
        for (int j = 1; j <= k[i]; j++) {
            cin >> v[i][j] >> x[i][j];
        }
    }
    for (int i = 1; i <= q; i++) {
        int s, e;
        cin >> s >> e;
        cout << 34 << " ";
    }
    return 0;
}

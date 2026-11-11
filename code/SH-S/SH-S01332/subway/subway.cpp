#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

using LL = long long;

const LL INF = 1e18 + 10;
const LL N = 510;
const LL M = 5e5 + 10;
LL w[M], sp[N][N];
vector<pair<LL, LL>> lines[M];

int main() {
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    LL c, n, m, d, q;
    cin >> c >> n >> m >> d >> q;
    for (LL i = 1; i <= m; i++) {
        cin >> w[i];
    }
    memset(sp, 0x3f, sizeof(sp));
    for (LL i = 1; i <= n; i++) {
        LL len;
        cin >> len;
        sp[i][i] = 0;
        for (LL j = 0; j < len; j++) {
            LL station, time;
            cin >> station >> time;
            lines[station].push_back({i, time});
        }
    }
    for (LL i = 1; i <= m; i++) {
        for (auto p1 : lines[i]) {
            for (auto p2 : lines[i]) {
                LL u = p1.first;
                LL v = p2.first;
                if (u == v) {
                    continue;
                }
                sp[u][v] = min(sp[u][v], p1.second + p2.second);
                sp[v][u] = sp[u][v];
            }
        }
    }
    for (LL k = 1; k <= n; k++) {
        for (LL u = 1; u <= n; u++) {
            for (LL v = 1; v <= n; v++) {
                sp[u][v] = min(sp[u][v], sp[u][k] + sp[k][v]);
                sp[v][u] = sp[u][v];
            }
        }
    }
    for (LL i = 0; i < q; i++) {
        LL x, y;
        cin >> x >> y;
        LL min_cost = INF;
        for (auto p1 : lines[x]) {
            for (auto p2 : lines[y]) {
                LL u = p1.first;
                LL v = p2.first;
                min_cost = min(min_cost, p1.second + p2.second + sp[u][v]);
            }
        }
        min_cost += (w[x] + w[y]);
        cout << min_cost << endl;
    }

    fclose(stdin);
    fclose(stdout);
    return 0;
}

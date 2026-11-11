#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;

vector<pair<int, int>> station[500001];
unsigned long long dis[501][501];
const long long INF = 1e18;
int n, m, d, q;
int v_s[500001];

int main() {
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int _n;
    cin >> _n >> n >> m >> d >> q;
    for (int i = 1; i <= m; i++) {
        cin >> v_s[i];
    }
    for (int i = 1; i <= n; i++) {
        int t;
        cin >> t;
        for (int j = 1; j <= t; j++) {
            int st, ti;
            cin >> st >> ti;
            station[st].push_back({i, ti});
        }
    }
    memset(dis, 0xff, sizeof(dis));
    for (int i = 1; i <= m; i++) {
        for (int j = 0; j < station[i].size(); j++) {
            for (int k = j + 1; k < station[i].size(); k++) {
                pair<int, int>& pj = station[i][j], pk = station[i][k];
                dis[pk.first][pj.first] = dis[pj.first][pk.first] = min(dis[pj.first][pk.first], 1ull * pj.second + pk.second);
            }
        }
    }
    for (int i = 1; i <= n; i++) dis[i][i] = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            for (int k = 1; k <= n; k++) {
                if (dis[i][k] >= INF || dis[k][j] >= INF) continue;
                dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
            }
        }
    }
    while (q--) {
        int a, b;
        cin >> a >> b;
        unsigned long long minn = 1e18;
        for (int i = 0; i < station[a].size(); i++) {
            for (int j = 0; j < station[b].size(); j++) {
                pair<int, int>& ap = station[a][i], bp = station[b][j];
                minn = min(minn, dis[ap.first][bp.first] + ap.second + bp.second);
            }
        }
        cout << minn + v_s[a] + v_s[b] << endl;
    }
}

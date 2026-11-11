#include <bits/stdc++.h>

using namespace std;

int main(){
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int c, n, m, d, q;
    cin >> c >> n >> m >> d >> q;

    vector<int> a(m + 1);
    for (int i = 1; i <= m; ++i){
        cin >> a[i];
    }

    vector<vector<int>> dis(m + 1, vector<int>(m + 1, 1e8));
    //vector<vector<Edge>> g(m + 1);
    for (int i = 0; i < n; ++i){
        int k;
        cin >> k;
        vector<pair<int, int>> b(k + 1);
        for (int j = 1; j <= k; ++j){
            cin >> b[j].first >> b[j].second;
        }
        for (int j = 1; j <= k; ++j){
            for (int l = j + 1; l <= k; ++l){
                int u = b[j].first, v = b[l].first;
                dis[u][v] = min(dis[u][v], b[j].second + b[l].second);
                dis[v][u] = dis[u][v];
                //g[u].push_back({u, v, i + 1, b[j].second + b[l].second});
                //g[v].push_back({v, u, i + 1, b[j].second + b[l].second});
            }
        }
    }

    for (int i = 1; i <= m; ++i){
        for (int j = i + 1; j <= m; ++j){
            for (int k = 1; k <= m; ++k){
                if (i == k || k == j) continue;
                dis[i][j] = min(dis[i][j], dis[i][k] + dis[j][k]);
                dis[j][i] = dis[i][j];
            }
        }
    }

    while (q--){
        int x, y;
        cin >> x >> y;
        cout << dis[x][y] + a[x] + a[y] << endl;
    }
    return 0;
}
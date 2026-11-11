#include <bits/stdc++.h>
using namespace std;

#define FIO "subway"

using ll = long long;
using pii = pair <int, int>;

const int MOD = 998244353;

int c, n, m, d, q;
int w[500005];
ll dist[505][505];
vector <pii> lines[500005];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    freopen(FIO".in", "r", stdin);
    freopen(FIO".out", "w", stdout);

    cin >> c >> n >> m >> d >> q;
    for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) dist[i][j] = i == j? (ll)0: (ll)1e18;
    for (int i = 1; i <= m; i++) cin >> w[i];

    for (int i = 0; i < n; i++){
        int k; cin >> k;
        while (k--){
            int a, t; cin >> a >> t;
            lines[a].push_back({i, t});
        }
    }
    for (int i = 1; i <= m; i++){
        for (int j = 0; j < lines[i].size(); j++){
            int a1 = lines[i][j].first, t1 = lines[i][j].second;
            for (int k = 0; k < j; k++){
                int a2 = lines[i][k].first, t2 = lines[i][k].second;
                dist[a1][a2] = min(dist[a1][a2], (ll)t1 + t2);
                dist[a2][a1] = min(dist[a2][a1], (ll)t1 + t2);
            }
        }
    }

    for (int k = 0; k < n; k++){
        for (int i = 0; i < n; i++){
            for (int j = 0; j < n; j++){
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }

    while (q--){
        int x, y; cin >> x >> y;
        ll ans = 1e18;
        for (int i = 0; i < lines[x].size(); i++){
            int a1 = lines[x][i].first, t1 = lines[x][i].second;
            for (int j = 0; j < lines[y].size(); j++){
                int a2 = lines[y][j].first, t2 = lines[y][j].second;
                ans = min(ans, t1 + t2 + dist[a1][a2]);
            }
        }
        cout << ans + w[x] + w[y] << "\n";
    }

    return 0;
}
// chennie bless me
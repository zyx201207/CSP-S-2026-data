#include<bits/stdc++.h>
using namespace std;
using ll = unsigned long long;
const ll inf = 1e18 + 7;
ll dist[501][501];
const int maxm = 5e5 + 7;
vector<pair<int, ll> > sub[maxm];
int c, m, n, d, q;
int w[maxm];
int main(){
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> c >> n >> m >> d >> q;
    for(int i = 1; i <= m; ++i){
        cin >> w[i];
    }
    for(int i = 1; i <= n; ++i){
        int k;
        cin >> k;
        for(int j = 1; j <= k; ++j){
            int a; ll t;
            cin >> a >> t;
            sub[a].emplace_back(i, t);
        }
    }
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= n; ++j){
            if(i != j){
                dist[i][j] = inf;
            }
        }
    }
    for(int i = 1; i <= m; ++i){
        int op = sub[i].size();
        for(int j = 0; j < op; ++j){
            for(int k = 0; k < op; ++k){
                auto x = sub[i][j];
                auto y = sub[i][k];
                dist[x.first][y.first] = min(dist[x.first][y.first], x.second + y.second);
                dist[y.first][x.first] = min(dist[y.first][x.first], x.second + y.second);
            }
        }
    }
    for(int k = 1; k <= n; ++k){
        for(int i = 1; i <= n; ++i){
            for(int j = 1; j <= n; ++j){
                if(dist[i][k] + dist[k][j] < dist[i][j]){
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }
    for(int i = 1; i <= q; ++i){
        int x, y;
        cin >> x >> y;
        ll ans = inf;
        int op1 = sub[x].size();
        int op2 = sub[y].size();
        for(int j = 0; j < op1; ++j){
            for(int k = 0; k < op2; ++k){
                auto ux = sub[x][j];
                auto uy = sub[y][k];
                ans = min(ans, ux.second + uy.second + dist[ux.first][uy.first]);
            }
        }
        cout << ans + w[x] + w[y] << '\n';
    }
    return 0;
}

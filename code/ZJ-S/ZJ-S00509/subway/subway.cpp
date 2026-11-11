#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 505, M = 5e5 + 5;
const ll INF = 1000000000000000000ll;

int __c;
int n, m, d, q;
int cnt[N];
ll w[M], g[N][N];
vector <int> sub[M];
vector <ll> t[M];

int main(){
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> __c;

    cin >> n >> m >> d >> q;
    for (int i = 1; i <= m; i ++ ) cin >> w[i];
    
    for (int i = 1; i <= n; i ++ ){
        cin >> cnt[i];
        for (int j = 0; j < cnt[i]; j ++ ){
            int pt; ll tim; cin >> pt >> tim;
            sub[pt].push_back(i), t[pt].push_back(tim);
        }
    }

    for (int i = 1; i <= n; i ++ ) for (int j = 1; j <= n; j ++ ) g[i][j] = (i == j ? 0 : INF);
    for (int i = 1; i <= m; i ++ ){
        int sz = sub[i].size();
        for (int _a = 0; _a < sz; _a ++ ){
            for (int _b = _a + 1; _b < sz; _b ++ ){
                int a = sub[i][_a], b = sub[i][_b];
                g[b][a] = g[a][b] = min(g[a][b], t[i][_a] + t[i][_b]);
            }
        }
    }
    // for (int i = 1; i <= n; i ++ ){
    //     for (int j = 1; j <= n; j ++ ){
    //         cout << g[i][j] << " ";
    //     }
    //     cout << "\n";
    // }
    for (int k = 1; k <= n; k ++ )
        for (int i = 1; i <= n; i ++ )
            for (int j = 1; j <= n; j ++ )
                    g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
    
    // return 0;
    while (q -- ){
        int x, y; cin >> x >> y;
        ll res = INF;
        for (int _a = 0; _a < sub[x].size(); _a ++ ){
            for (int _b = 0; _b < sub[y].size(); _b ++ ){
                int a = sub[x][_a], b = sub[y][_b];
                // cout << a << " " << b << " " << w[x] << " " << w[y] << " " << t[x][_a] << " " << t[y][_b] <<   " " << g[a][b] << "\n";
                res = min(res, g[a][b] + t[x][_a] + t[y][_b]);
            }
        }
        res += w[x] + w[y];
        cout << res << "\n";
    }
}
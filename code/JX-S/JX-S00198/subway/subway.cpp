#include <bits/stdc++.h>
using namespace std;
using PII = pair<int, int>;
const int N = 505, M = 5e5 + 5;
int c, n, m, d, q;
long long w[M];
vector<int> route[M];
vector<long long> t[N];
long long g[N][N];
unordered_map<int, int> pos[M];
void floyd(){
    for (int k = 1; k <= n; k ++ )
        for (int i = 1; i <= n; i ++ )
            for (int j = 1; j <= n; j ++ )
                g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
}
int main(){
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    ios :: sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> c >> n >> m >> d >> q;
    for (int i = 1; i <= m; i ++ ) cin >> w[i];
    for (int i = 1; i <= n; i ++ ) {
        int k, aij, tij;
        cin >> k;
        t[i].push_back(0);
        for (int j = 1; j <= k; j ++ ) {
            cin >> aij >> tij;
            t[i].push_back(tij);
            route[aij].push_back(i);
            pos[aij][i] = j;
        }
    }
    for (int i = 1; i <= n; i ++ )
        for (int j = 1; j <= n; j ++ )
            if (i == j) g[i][j] = 0;
            else g[i][j] = 2e18;
    for (int i = 1; i <= m; i ++ )
        for (int it1 = 0; it1 < route[i].size(); it1 ++ )
            for (int it2 = it1 + 1; it2 < route[i].size(); it2 ++ ) {
                int p = route[i][it1], q = route[i][it2];
                g[p][q] = g[q][p] = min(g[p][q], t[p][pos[i][p]] + t[q][pos[i][q]]);
            }
    floyd();
    while (q -- ) {
        int xr, yr;
        cin >> xr >> yr;
        long long res = 2e18;
        for (int i = 0; i < route[xr].size(); i ++ )
            for (int j = 0; j < route[yr].size(); j ++ ) {
                int p = route[xr][i], q = route[yr][j];
                res = min(res, g[p][q] + t[p][pos[xr][p]] + t[q][pos[yr][q]]);
            }
        res += w[xr] + w[yr];
        cout << res << '\n';
    }
    return 0;
}


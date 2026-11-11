#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

using LL = long long;

int w[500005];
LL dp[505][505];
vector<short> station[500005];
int t[505][500005];

int main(){
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int c, n, m, d, q;
    cin >> c >> n >> m >> d >> q;
    for (int i = 1; i <= m; i++){
        cin >> w[i];
    }
    memset(dp, 0x3f, sizeof dp);
    for (int i = 1; i <= n; i++){
        dp[i][i] = 0;
        int k;
        cin >> k;
        for (int j = 1; j <= k; j++){
            int x, y;
            cin >> x >> y;
            station[x].push_back(i);
            t[i][x] = y;
        }
    }
    for (int i = 1; i <= m; i++){
        if (station[i].size() == 1) continue;
        for (auto j: station[i]){
            for (auto k: station[i]){
                dp[j][k] = min(dp[j][k], 1ll * t[j][i] + t[k][i]);
            }
        }
    }
    for (int k = 1; k <= n; k++){
        for (int i = 1; i <= n; i++){
            for (int j = 1; j <= n; j++){
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
            }
        }
    }
    while (q--){
        int s, e;
        cin >> s >> e;
        LL ans = 1e18;
        for (auto i: station[s]){
            for (auto j: station[e]){
                ans = min(ans, t[i][s] + dp[i][j] + t[j][e]);
            }
        }
        cout << w[s] + w[e] + ans << '\n';
    }
    return 0;
}

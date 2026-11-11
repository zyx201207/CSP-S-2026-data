#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 510, M = 5e5 + 10;
int c, n, m, d, q, w[M], sum[N];
long long f[N][N];
struct sb { int pos, cost; };
vector<sb> station[M];
signed main() {
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin >> c >> n >> m >> d >> q;
    for(int i = 1; i <= m; i++) cin >> w[i];
    for(int i = 1; i <= n; i++) {
        cin >> sum[i];
        int pos, cost;
        for(int j = 1; j <= sum[i]; j++) {
            cin >> pos >> cost;
            station[pos].push_back({i, cost});
        }
    }
    memset(f, 0x3f, sizeof(f));
    for(int i = 0; i <= n; i++) f[i][i] = 0;
    for(int i = 1; i <= m; i++) {
        int len = station[i].size();
        for(int j = 0; j < len; j++) {
            for(int k = j + 1; k < len; k++) {
                long long pos1 = station[i][j].pos, pos2 = station[i][k].pos, cost1 = station[i][j].cost, cost2 = station[i][k].cost;
                f[pos1][pos2] = min(f[pos1][pos2], cost1 + cost2);
                f[pos2][pos1] = min(f[pos2][pos1], cost1 + cost2);
            }
        }
    }
    for(int k = 1; k <= n; k++) for(int i = 1; i <= n; i++) for(int j = 1; j <= n; j++) f[i][j] = min(f[i][j], f[i][k] + f[k][j]);
    while(q--) {
        int s, t;
        long long ans = 1e18; cin >> s >> t;
        int len1 = station[s].size(), len2 = station[t].size();
        for(int i = 0; i < len1; i++) {
            for(int j = 0; j < len2; j++) {
                long long pos1 = station[s][i].pos, pos2 = station[t][j].pos, cost1 = station[s][i].cost, cost2 = station[t][j].cost;
                ans = min(ans, f[pos1][pos2] + cost1 + cost2);
            }
        }
        cout << ans + w[s] + w[t] << "\n";
    }
    return 0;
}
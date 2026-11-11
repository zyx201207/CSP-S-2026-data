#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

//fo zu bao you, bu yao zha a
//xie le 2:30 le zen me zhi chu le yi ti
//wo yao zha le
//17:32
const int N = 5005;
ll a[N], g[N][N], ans;


int main() {
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    int c, t, n, d;
    cin >> c >> t;
    while (t--) {
        memset(a, 0, sizeof(a));
        memset(g, 0x3f, sizeof(g));
        ans = 0;
        cin >> n >> d;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (abs(a[j] - a[i]) <= d) {
                    g[i][j] = 1;
                }
            }
        }
        for (int i = 1; i <= n; i++) {
            for (int k = 1; k <= n; k++) {
                for (int j = 1; j <= n; j++) {
                    if (g[i][j] + g[j][k] < g[i][k]) {
                        g[i][k] = g[i][j] + g[j][k];
                    }
                }
            }
        }
        map<pair<int,int>,int> mp;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                for (int k = 1; k <= n; k++) {
                    if (g[i][j] + g[j][k] == g[i][k]) {
                        mp[make_pair(i, k)]++;
                    }
                }
            }
        }
        for (auto i : mp) {
            if (i.second == 2) ans++;
        }
        cout << ans << ' ';
    }
    return 0;
}

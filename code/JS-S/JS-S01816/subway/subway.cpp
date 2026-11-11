#include <bits/stdc++.h>
using namespace std;

#define int long long

const int N = 5e5;

int c, n, m, d, q;
int w[N + 10];
vector<tuple<int, int, int, int>> e[N + 10];
signed main() {
 //   freopen("subway.in", "r", stdin);
 //   freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> c >> n >> m >> d >> q;

    for (int i = 1; i <= m; i ++) cin >> w[i];
    for (int i = 1; i <= n; i ++) {
        int k;
        cin >> k;
        int a, t;
        cin >> a >> t;
        for (int j = 2; j <= k; j ++) {
            int aa, tt;
            cin >> aa >> tt;
            e[a].push_back({aa, 0, t, i});
            a = aa, t = tt;
        }
    }
    for (int i = 1; i <= m; i ++) {
        for (auto st : e[i]) {

        }
    }
    return 0;
}

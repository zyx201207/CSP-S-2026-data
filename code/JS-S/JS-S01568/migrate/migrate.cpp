#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int, int>
const int N = 2e6 + 5;

int n, d, x[N];
signed main() {
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int C, T;
    cin >> C >> T;
    while (T--) {
        cin >> n >> d;
        for (int i = 1; i <= n; i++)
            cin >> x[i];
        vector<pii> ans;
        for (int i = 1; i <= n; i++)
            for (int j = i + 2; j <= n; j++) {
                if (x[j] - x[i] <= d)
                    continue;
                if (x[j] - x[i] >= 2 * d)
                    break;
                int cnt = 0;
                for (int k = i + 1; k < j; k++)
                    if (x[k] - x[i] <= d && x[j] - x[k] <= d)
                        cnt++;
                if (cnt == 2)
                    ans.push_back({i, j});
            }
        cout << ans.size() << '\n';
    }
    return 0;
}
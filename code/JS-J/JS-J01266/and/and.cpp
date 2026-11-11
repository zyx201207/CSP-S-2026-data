#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5 + 5;
int n, m, vis[N];
ll a[N][40], ans;
int main() {
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        ll x; cin >> x;
        for (int j = 35; j >= 0; --j) {
            if ((1ll << j) <= x) {
                a[i][j] = 1;
                x -= (1ll << j);
            }
        }
    }
    for (int j = 35; j >= 0; --j) {
        int cnt = 0;
        for (int i = 1; i <= n; ++i) {
            if (!vis[i] && a[i][j]) cnt++;
        }
        if (cnt >= m) {
            ans += (1ll << j);
            for (int i = 1; i <= n; ++i) {
                if (!a[i][j]) vis[i] = 1;
            }
        }
    }
    cout << ans << endl;
    return 0;
}
// 100

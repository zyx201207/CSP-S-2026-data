#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;
using ll = long long;

ll n, m;
ll a[N];
ll ans = 0;

int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    if (n <= 20) {
        while (next_permutation(a+1, a+n+1)) {
            ll temp = a[1];
            for (int i = 2; i <= m; i++) {
                temp &= a[i];
            }
            ans = max(ans, temp);
        }
        cout << ans;
    } else if (n <= 2000) {
        if (m == 1) {
            for (int i = 1; i <= n; i++) {
                ans = max(ans, a[i]);
            }
            cout << ans;
            return 0;
        } else if (m == n) {
            ans = a[1];
            for (int i = 2; i <= n; i++) {
                ans &= a[i];
            }
            cout << ans;
            return 0;
        }
    }
    return 0;
}

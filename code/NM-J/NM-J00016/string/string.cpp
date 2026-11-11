#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
typedef long long ll;
ll n, sum[N], t[N];
int main() {
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    cin >> n;
    char maxc = 0;
    for (int i = 1; i <= n; i++) {
        ll a;
        char c;
        cin >> a >> c;
        t[c] += a;
        maxc = max(maxc, c);
    }
    ll ans = 1e18;
    for (int i = 'a'; i <= maxc; i++) {
        ll res = 0;
        for (int j = 'a'; j <= maxc; j++) {
            if (i == j) {
                continue;
            }
            if (t[i] == t[j]) {
                continue;
            }
            res += t[j];
        }
        ans = min(ans, res);
    }
    cout << ans << endl;
    return 0;
}

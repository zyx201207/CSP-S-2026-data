#include <bits/stdc++.h>
using namespace std;

// #define LOCAL
const int MAX = 5e5 + 10;
typedef long long ll;
ll n, a[MAX], m;
ll diff[MAX];
ll sum[MAX];

int main() {
    // freopen("crystal3.in", "r", stdin);
    #ifndef LOCAL
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    #endif
    cin.tie(nullptr)->sync_with_stdio(false);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    sort(a + 1, a + n + 1);
    for (int i = n - 1; i >= 1; i--) {
        diff[i] = diff[i + 1] + (a[i + 1] - a[i]);
    }
    for (int i = 1; i <= n; i++) {
        sum[i] = sum[i - 1] + diff[i];
    }
    ll ans = 1;
    int l = 1, r = 1;
    while (r <= n) {
        if (sum[r - 1] - sum[l - 1] - (r - l) * diff[r] <= m) {
            ans = max(ans, (ll)r - l + 1);
            r++;
        }
        else {
            l++;
        }
    }
    cout << ans << '\n';
    // fclose(stdin);
    #ifndef LOCAL
    fclose(stdin);
    fclose(stdout);
    #endif
    return 0;
}
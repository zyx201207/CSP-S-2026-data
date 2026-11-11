#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 5e5 + 10;
int n;
ll m;
ll a[N], s[N];
bool cmp(ll a, ll b) {
    return a > b;
}
int main() {
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i];
    sort(a + 1, a + n + 1, cmp);
    for (int i = 1; i <= n; i++) s[i] = s[i - 1] + a[i];
    int ans = 1;
    for (int i = 1; i <= n; i++) {
        int l = i, r = n, mid;
        while (l <= r) {
            mid = (l + r) >> 1;
            if (a[i] * (mid - i + 1) - s[mid] + s[i - 1] <= m) {
                l = mid + 1;
                ans = max(ans, (mid - i + 1));
            } else r = mid - 1;
        }
    }
    cout << ans << '\n';
    return 0;
}

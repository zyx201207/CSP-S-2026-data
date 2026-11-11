#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int const N = 5e5 + 5;
int n, ans;
ll a[N], m, s[N];
bool chk(int x, int y) {
    return (y - x + 1) * a[y] - s[y] + s[x - 1] <= m;
}
int main () {
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    sort(a + 1, a + n + 1);
    for (int i = 1; i <= n; i++) {
        s[i] = s[i - 1] + a[i];
    }
    for (int i = 1; i <= n; i++) {
        int l = 1, r = i;
        while (l <= r) {
            int mid = l + r >> 1;
            if (chk(mid, i)) r = mid - 1;
            else l = mid + 1;
        }
        ans = max(ans, i - r);
    }
    cout << ans << endl;
    return 0;
}
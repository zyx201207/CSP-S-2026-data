#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 5E5 + 5;
ll arr[N], sum[N];
int n;
ll m;

ll get(int to, int fr) {
    ll sum1 = 1ll * (to - fr + 1) * arr[to];
    ll sum2 = sum[to] - sum[fr - 1];
    return sum1 - sum2;
}

signed main() {
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> arr[i];
    sort(arr + 1, arr + n + 1);
    for (int i = 1; i <= n; i++) sum[i] = sum[i - 1] + arr[i];
    int ans = 1;
    for (int i = 1; i <= n; i++) {
        int l = 1, r = i;
        int lst = 0;
        while (l <= r) {
            int mid = l + r >> 1;
            if (get(i, mid) <= m) {
                lst = mid;
                r = mid - 1;
            } else l = mid + 1;
        }
        ans = max(ans, i - lst + 1);
    }
    cout << ans << '\n';
}
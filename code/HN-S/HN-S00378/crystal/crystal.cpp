#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);

	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	
    int n;
    ll m;
    cin >> n >> m;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    auto check = [&](int k) {
        ll sum = accumulate(a.begin(), a.begin() + k, 0ll);
        if (a[k - 1] * k - sum <= m) {
            return true;
        }
        for (int i = k; i < n; i++) {
            sum += a[i] - a[i - k];
            if (a[i] * k - sum <= m) {
                return true;
            }
        }
        return false;
    };
    int l = 1, r = n, ans = 0;
    while (l <= r) {
        int mid = l + r >> 1;
        if (check(mid)) {
            ans = mid;
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    cout << ans << '\n';
	return 0;
}
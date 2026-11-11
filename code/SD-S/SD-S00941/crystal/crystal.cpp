#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 5e5 + 5;
int n, m, a[N], s[N];
bool check(int i, int x) {
	if (s[i - 1] - s[x - 1] >= a[i] * (i - x) - m) return true;
	else return false;
}
signed main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(false); cin.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; i++) {
		s[i] = s[i - 1] + a[i];
	}
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		int l = 1, r = i - 1, sum = 0;
		while (l <= r) {
			int mid = (l + r) >> 1;
			if (check(i, mid)) {
				r = mid - 1;
				sum = mid;
			} else {
				l = mid + 1;
			}
		}
		ans = max(ans, i - sum + 1);
	}
	cout << ans;
	return 0;
}
// CSP-S rp++

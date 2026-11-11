#include <bits/stdc++.h>
using namespace std;

const int N = 5e5 + 5;

int n;
long long m, a[N], s[N];

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin.tie(0)->sync_with_stdio(0);
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
		int l = 1, r = i;
		while (l <= r) {
			int mid = l + r >> 1;
//			cout<<l<<' '<<r<<' '<<mid<<' '<< s[i] - s[mid - 1] << ' ' << i - mid + 1 << ' ' << a[i] << '\n';
			if ((i - mid + 1ll) * a[i] - (s[i] - s[mid - 1]) <= m) {
				r = mid - 1;
			} else {
				l = mid + 1;
			}
		}
//		cout << i << ' ' << l << '\n';
		ans = max(ans, i - l + 1);
	}
	cout << ans;
	return 0;
}
// Oct31==Dec25?

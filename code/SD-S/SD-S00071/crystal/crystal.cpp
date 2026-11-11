#include<bits/stdc++.h>
using namespace std;
#define int long long
int n, m, a[600001], s[600001];
bool check (int x) {
	for (int i = 1; i <= n - x + 1; i++) {
		int ans = (a[x + i - 1] * x - (s[x + i - 1] - s[i - 1]));
		if (ans <= m) return true;
	}
	return false;
}
signed main () {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	scanf("%lld%lld", &n, &m);
	for (int i = 1; i <= n; i++) scanf("%lld", &a[i]);
	int l = 0, r = n + 1;
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; i++) {
		s[i] = s[i - 1] + a[i];
	}
	while (l + 1 < r) {
		int mid = (l + r) >> 1;
		if (check(mid)) {
			l = mid;
		}else r = mid;
	}
	cout << l << "\n";
}


#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 5;
#define int long long
int n, m, a[N], b[N], cnt[N], lst[N], ans[N];

signed main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		cnt[a[i]]++;
	}
	for (int i = n; i >= 1; i--) {
		if (lst[a[i]] == 0) {
			lst[a[i]] = i;
		}
	}
	if (m >= 100000) {
		for (int i = 1; i < n; i++) {
			cout << cnt[a[i]] << " ";
		}
		cout << n;
		return 0;
	}
	for (int i = 1; i <= n; i++) {
		int j = i;
		while (j <= n) {
			ans[a[j]]++;
			j = lst[a[j]] + 1;
		}
	}
	for (int i = 1; i <= m; i++) {
		cout << ans[i] << " ";
	}
	return 0;
}

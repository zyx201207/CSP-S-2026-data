#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 5e5 + 5;
int n, m;
int a[N];
signed main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	if (n == 1) {
		cout << 1;
		return 0;
	}
	sort(a + 1, a + 1 + n);
	int pre = 0; 
	int ans = 0;
	int l = 0;
	for (int i = 1; i <= n; i++) {
		while (l < i && (i - l) * a[i] - pre > m) {
			pre -= a[l++];
		}
		if ((i - l) * a[i] - pre <= m) {
			ans = max(ans, i - l + 1);
		}
		pre += a[i];
	}
	cout << ans;
	return 0;
}


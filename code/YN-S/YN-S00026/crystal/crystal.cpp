#include <bits/stdc++.h>
#define int long long
using namespace std;
int n, m, ans;
const int maxn = 500005;
int a[maxn];

signed main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	int mid = n / 2 + 1, cnt = 0;
	for (int i = 1; i <= n; i++) {
		if (a[mid] - a[i] > m || a[mid] < a[i])
			continue;
		a[i] += a[mid] - a[i];
		cnt += a[mid] - a[i];
		ans++;
		if (cnt >= m || a[i] > a[mid])
			break;
	}
	if (cnt > m)
		ans--;
	cout << ans;
	return 0;
}
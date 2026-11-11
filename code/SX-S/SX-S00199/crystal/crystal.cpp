#include <bits/stdc++.h>
using namespace std;
long long a[500005];
long long qzh[500005];

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	long long m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; i++)
		qzh[i] = qzh[i - 1] + a[i];
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		int l = 1, r = i;
		while (l < r) {
			int mid = (l + r) / 2;
			if (a[i] * (i - mid + 1) - (qzh[i] - qzh[mid - 1]) <= m)
				r = mid;
			else
				l = mid + 1;
		}
		ans = max(ans, i - r + 1);
	}
	cout << ans;
	return 0;
}

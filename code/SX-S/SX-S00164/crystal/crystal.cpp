#include <bits/stdc++.h>
#define int long long
using namespace std;
int n, m, a[500005], ans;
int c[500005], cc[500005];

bool check(int x) {
	int w = LONG_MAX;
	for (int i = 1; i <= n; i++) {
		int j = i + x - 2;
		if (j >= n)
			break;
		int q = c[j] - c[i - 1] - (i - 1) * (cc[j] - cc[i - 1]);
		w = min(w, q);
	}
	if (w <= m)
		return true;
	else
		return false;
}

signed main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	sort(a + 1, a + n + 1);
	for (int i = 1; i < n; i++)
		c[i] = c[i - 1] + (a[i + 1] - a[i]) * (i);
	for (int i = 1; i < n; i++)
		cc[i] = cc[i - 1] + a[i + 1] - a[i];
	int l = 1, r = n;
	while (l <= r) {
		int mid = (l + r) / 2;
		if (check(mid)) {
			l = mid + 1;
		} else {
			r = mid - 1;
		}
	}
	cout << r;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 5e5 + 5;
int n, m, ans, a[N];
bool vis = 1;

bool check(int x) {
	int sum = 0;
	for (int i = 1; i <= x; i++)
		sum += a[x] - a[i];
	return sum <= m;
}

bool check1(int x) {
	int sum = 1e18;
	for (int i = 1; i <= n - x + 1; i++) {
		int v = 0;
		for (int j = i; j <= i + x - 1; j++)
			v += a[i + x - 1] - a[j];
		sum = min(sum, v);
	}
	return sum <= m;
}

signed main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	sort(a + 1, a + n + 1);
	for (int i = 3; i <= n; i++) {
		if (a[i - 1] - a[i - 2] != a[i] - a[i - 1])
			vis = 0;
	}
	if (vis) {
		int l = 1, r = n;
		while (l <= r) {
			int mid = l + (r - l) / 2;
			if (check(mid))
				ans = mid, l = mid + 1;
			else
				r = mid - 1;
		}
	} else {
		int l = 1, r = n;
		while (l <= r) {
			int mid = l + (r - l) / 2;
			if (check1(mid))
				ans = mid, l = mid + 1;
			else
				r = mid - 1;
		}
	}
	cout << ans << '\n';
	return 0;
}
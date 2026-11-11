#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 5;
int a[N], b[N], c[N];
int n, m;
int ans;

bool check(int x) {
	bool flg = 0;
	for (int i = 1; i < n - x + 1; i++) {
		int sum = 0;
		for (int j = 0; j < x; j++)
			sum += b[i + x - 1] - b[i - 1 + j];
		if (sum <= m) {
			flg = 1;
			break;
		}
	}
	return flg;
}

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	a[0] = 0;
	b[0] = 0;
	for (int i = 1; i <= n; i++) {
		c[i - 1] = a[i] - a[i - 1];
	}
	for (int i = 1; i < n; i++) {
		b[i] = b[i - 1] + c[i];
	}
	int l = 0, r = n, mid;
	while (l <= r) {
		mid = (l + r) / 2;
		if (check(mid)) {
			l = mid + 1;
			ans = mid;
		} else {
			r = mid - 1;
		}
	}
	cout << ans + 1;

	return 0;
}
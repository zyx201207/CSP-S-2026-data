#include <bits/stdc++.h>
using namespace std;
long long n, m, a[500005], cnt = 0, ans = 0, anss = 0;

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;

	for (int i = 1; i <= n; i++) {

		cin >> a[i];
	}

	sort(a + 1, a + n + 1);

	for (int i = 1; i <= n; i++) {

		if (cnt + (a[i] - a[i - 1])*ans <= m) {
			cnt += (a[i] - a[i - 1]) * ans;
			ans++;
		} else if ((a[i] - a[i - 1]) * (ans - 1) - a[i - ans] <= 0) {
			cnt -= a[i - ans] - (a[i] - a[i - 1]) * (ans - 1);
		} else {
			anss = max(anss, ans);
			ans = 0;
			cnt = 0;

		}
	}

	anss = max(anss, ans);
	cout << anss;
	return 0;
}

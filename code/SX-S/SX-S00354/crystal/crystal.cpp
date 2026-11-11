#include <bits/stdc++.h>
using namespace std;
long long _a[500005], _s[500005], ans = 0, n, m;

void check(int x) {
	for (int i = 1; i <= n; i++) {
		if (_a[i] > x)
			_s[i] = 5e18;
		else
			_s[i] = x - _a[i];

	}
	sort(_s + 1, _s + n + 1);
//	for (int i = 1; i <= n; i++)
//		cout << _s[i] << ' ';
//	cout << endl;
	long long k = m, sum = 0;
	for (int i = 1; i <= n; i++) {
		if (k >= _s[i])
			sum++, k -= _s[i];
		else
			break;
	}
	ans = max(sum, ans);
}

int main() {

	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);

	long long l = 1e16, r = -1e16;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> _a[i];
		r = max(r, _a[i]);
		l = min(l, _a[i]);
	}
	sort(_a + 1, _a + n + 1);
	for (int i = l; i <= r; i++)
		check(i);
	cout << ans;
	return 0;
}

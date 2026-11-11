#include <bits/stdc++.h>
using namespace std;
#define int long long
int const N = 5e5 + 5;
int n, m, ans = 1, d, flag = 1;
int a[N], t[505];


signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	sort(a + 1, a + 1 + n);
	d = a[2] - a[1];
	for (int i = 2; i <= n; i++)
		if (a[i] - a[i - 1] != d)
			flag = 0;

	if (n <= 5000) {
		for (int i = 2; i <= n; i++) {
			int sum = 0, l = i;
			while (sum <= m && l)
				sum += a[i] - a[--l];
			ans = max(ans, i - l);
		}
		cout << ans << '\n';
	} else if (flag) {
		for (int i = 1; i < n; i++) {
			int val = (1 + i) * i / 2;
			if (m >= d * val)
				ans = i + 1;
			else
				break;
		}
		cout << ans << '\n';
	} else {

		for (int i = 1; i <= n; i++)
			a[i] += 200, t[a[i]]++;
		for (int i = 1; i <= 500; i++) {
			if (t[i] == 0)
				continue;
			int l = i, sum = 0, cnt = t[i];
			while (l > 0 && sum <= m) {
				l--;
				if (!t[l])
					continue;
				if (t[l] * (i - l) + sum > m) {
					int val = m - sum;
					cnt += val / (i - l);
					break;
				} else
					sum += t[l] * (i - l), cnt += t[l];
			}
			ans = max(ans, cnt);
		}
		cout << ans << '\n';
	}

	return 0;
}

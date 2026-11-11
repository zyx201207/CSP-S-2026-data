#include <bits/stdc++.h>
using namespace std;

long long n, m, flag, flag2, a[1000010], ans, cntt[1000010], cnt, cnt1 = 1, cnt2 = 1, need[1000010];

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
	}
	for (int i = 1; i <= n; ++i) {
		if (a[i] == i)
			flag++;
	}
	if (flag == n && n >= 2) {
		for (int i = 2; i <= n; ++i) {
			if (i * (i - 1) / 2 > m) {
				cnt = i - 1;
				cout << cnt;
				return 0;
			}
		}
	}
	if (n >= 3) {
		for (int i = 2; i <= n - 1; ++i) {
			if (a[i + 1] - a[i] == a[i] - a[i - 1])
				flag2++;
		}
		if (flag2 == n - 2) {
			long long t = a[2] - a[1];
			for (int i = 2; i <= n; ++i) {
				if (t * i * (i - 1) / 2 > m) {
					cnt = i - 1;
					cout << cnt;
					return 0;
				}
			}
		}
	}
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; ++i) {
		ans = 0;
		cntt[i] = 1;
		for (int j = i - 1; j >= 1; --j) {
			ans += (a[i] - a[j]);
			if (ans > m)
				break;
			cntt[i]++;
		}
	}
	for (int i = 1; i <= n; ++i) {
		cnt = max(cntt[i], cnt);
	}
	cout << cnt;
	return 0;
}
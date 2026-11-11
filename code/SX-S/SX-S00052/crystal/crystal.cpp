
#include <bits/stdc++.h>
using namespace std;
long long n, m, a[100010], t = 0, k, y, ans = 0, s, cha, ttt;

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out ", "w", stdout);
	cin >> n >> s;
	m = s;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	sort(a + 1, a + n + 1);
	cha = a[2] - a[1];
	for (int i = 2; i <= n; i++) {
		if (cha != a[i] - a[i - 1])
			ttt++;
	}
	if (ttt != 0) {
		for (int i = 2; i <= n; i++) {
			y = i - 1;
			while (a[i] - a[y] <= m && y >= 1 && m >= 0) {
				ans++;
				m = m - a[i] + a[y];
				y -= 1;

			}
			t = max(ans, t);
			ans = 0;
			m = s;
		}
		t++;
		cout << t ;
	} else {
		for (int i = 1; i <= n; i++) {
			if (m >= cha * i) {
				ans++;
				m -= cha * i;
			}
		}
		cout << ans + 1;

	}

	return 0;
}
























#include <bits/stdc++.h>
using namespace std;
long long a[500005], b[500005];

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	long long n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	if (n <= 16) {
		int ans = 0;
		for (int i = a[1]; i <= a[n]; i++) {
			for (int j = 1; j <= n; j++) {
				if (i >= a[j])
					b[j] = i - a[j];
				else
					b[j] = a[j] - i;
			}
			sort(b + 1, b + n + 1);
			int ee = m;
			int t = 0;
			for (int j = 1; j <= n; j++) {
				if (b[j] <= ee) {
					t++;
					ee -= b[j];
				} else
					break;
			}
			ans = max(ans, t);
		}
		cout << ans;
		return 0;
	}

	int w = n / 2;
	if (n % 2 != 0)
		w++;
	long long x = a[w];
	for (int i = 1; i <= n; i++) {
		if (x > a[i])
			b[i] = x - a[i];
		else
			b[i] = a[i] - x;
	}
	sort(b + 1, b + n + 1);
	int t = 0;
	for (int i = 1; i <= n; i++) {
		if (b[i] <= m) {
			t++;
			m -= b[i];
		} else
			break;
	}
	cout << t;
	return 0;
}

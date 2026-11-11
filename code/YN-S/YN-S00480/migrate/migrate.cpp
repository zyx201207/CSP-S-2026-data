#include <bits/stdc++.h>
using namespace std;
int const maxn = 1e9 + 5;
int n[100000005], d[100000005];
int x[maxn];

int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	int c, t;
	cin >> c >> t;
	for (int i = 1; i <= t; i++) {
		cin >> n[i] >> d[i];
		for (int j = 1; i <= n[i]; j++) {
			cin >> x[i];
		}
	}
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; i++) {
		if (abs(x - a[i]) < abs(x - z)) {
			z = a[i];
			b = i;
		}
	}
	for (int i = b; i >= 1; i--) {
		for (int j = m; j >= 0; j--) {
			if (a[i] == z) {
				cnt += 1;
				break;
			}
			a[i]++;
			m -= 1;
		}

		if (m == 0) {
			break;
		}
	}
	while (a[b] = z) {
		cnt += 1;
		b++;
	}
	cout << cnt;
	return 0;
}
#include <bits/stdc++.h>
using namespace std;
int const maxn = 1e9 + 5;
int a[100000005];

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	int n, x, y = 0, b, cnt = 0;
	long long m, z = 999999999;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		y += a[i];
	}
	x = y / n;
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
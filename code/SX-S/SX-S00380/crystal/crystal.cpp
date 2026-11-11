#include <bits/stdc++.h>
using namespace std;
long long n, m, b[500010], h, s, j, k;
long long a[500010];

bool cmp(int x, int y) {
	return x > y;
}

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	h = m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + 1 + n, cmp);

	for (int i = 1 ; i < n; i++) {
		k = 1;
		m = h;
		while (m > 0 ) {
			if (a[i] - a[i + k] <= m && i + k <= n) {
				m -= abs(a[i] - a[i + k]);
				b[i]++;
				k++;
			} else {
				s++;

				break;
			}
		}
	}
	sort(b + 1, b + 1 + n, cmp);
	cout << b[1] + 1;
	return 0;
}
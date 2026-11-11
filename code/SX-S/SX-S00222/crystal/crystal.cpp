#include <bits/stdc++.h>
using namespace std;
long long int n, m, cnt, i;
long long a[500010], b[100010];

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for (int j = 1; j <= n; j++) {
		cin >> a[j];
		b[a[j]]++;
	}
	sort(a + 1, a + 1 + n);
	while (m >= i) {
		if (b[n / 2 + i] >= 1) {
			if (m >= b[n / 2 + i])
				m -= b[n / 2 + i];
			cnt += b[n / 2 + i];
		} else if (b[n / 2 - i] >= 1) {
			if (m >= b[n / 2 - i])
				m -= b[n / 2 - i];
			cnt += b[n / 2 - i];
		}
		i++;
	}
	cout << cnt;
	return 0;
}
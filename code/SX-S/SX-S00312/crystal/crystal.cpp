#include <bits/stdc++.h>
using namespace std;
long long sum, n, m, a[500005], b[500005] ;
long long ma = LONG_LONG_MIN, mi = LONG_LONG_MAX, maxx = -1;

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		ma = max(a[i], ma);
		mi = min(mi, a[i]);
	}
	if (abs(mi - ma) >= 200000) {
		cout << 1;
		return 0;
	}
	sort(a + 1, a + 1 + n);
	for (int i = mi; i <= ma; i++) {
		memset(b, -1, sizeof(b));
		long long k = 1, zh = 0;
		sum = 0;
		for (int j = 1; j <= n; j++, k++) {
			if (a[j] > i)
				break;
			b[j] = i - a[j];
			sum++;
			zh += b[j];
		}
		while (sum > 0 && zh > 0) {
			if (zh <= m) {
				if (sum == n) {
					cout << sum;
					return 0;
				} else
					maxx = max(sum, maxx);
			}
			sum--;
			zh -= b[k - 1];
			k--;
		}
	}
	cout << maxx;
	return 0;
}

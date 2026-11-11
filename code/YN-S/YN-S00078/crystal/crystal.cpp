#include <bits/stdc++.h>
using namespace std;
const int N = 500005;
long long a[N], n, c, m ;
double b[N], v, k = INT_MAX;

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		v += a[i];
	}
	v /= n;
	for (int i = 1; i <= n; i++) {
		b[i] = abs(a[i] - v);
		k = min(k, b[i]);
	}
	sort(b, b + n + 1);

	for (int i = 1; i <= n; i++) {
		if ((b[i] - k) > m) {
			break;
		} else if (b[i] == 0) {
			continue;
		}
		m -= (b[i] - k);
		b[i] = k;
	}
	for (int i = 1; i <= n; i++) {
		if (b[i] == k) {
			c += 1;
		}
	}
	cout << c;
	return 0;
}

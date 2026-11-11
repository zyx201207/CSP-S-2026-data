#include <bits/stdc++.h>
using namespace std;
long long cnt, n, a[100000005], b, sum;
int x[10000005];
char c[10000005];

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> x[i] >> c[i];
		sum += x[i];
	}
	if (sum > 500000000) {
		for (int i = 1; i <= n; i++) {
			x[i] /= 100;
		}
	}
	for (int i = 1; i <= n; i++) {
		while (x[i]--) {
			b++;
			a[b] = int(c[i]);
		}
	}
	int r = 1, l = b;
	while (r < l) {
		if (a[r] != a[l])
			cnt++;
		r++, l--;
	}
	if (sum > 500000000) {
		cout << cnt * 100;
		return 0;
	}
	cout << cnt;

	return 0;
}
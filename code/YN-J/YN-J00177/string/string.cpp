#include <bits/stdc++.h>
using namespace std;
int n, x;
long long a[200005];
long long ans;
char c[200005];

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> x >> c[i];
		a[i] = a[i - 1] + x;
	}
	int i = 1, m = n;
	long long j = 1, f = a[n];
	while (j <= a[n] / 2 && i <= n) {
		if (j > a[i]) {
			i++;
		}
		if (f <= a[m - 1]) {
			m--;
		}
		int w = min(a[i] - j + 1, f - a[m - 1]);
		j += w;
		f -= w;
		if (c[i] != c[m]) {
			ans += w;
		}
	}
	cout << ans;
	return 0;
}
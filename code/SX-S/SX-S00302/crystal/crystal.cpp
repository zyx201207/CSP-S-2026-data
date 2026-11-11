#include <bits/stdc++.h>
using namespace std;
long long m, n, a[50086], b[50086], c[50086], s, q, w;

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	sort(a + 1, a + n + 1);
	if (a[1] < 0) {
		for (int i = n; i >= 0; i--)
			a[i] = a[i] - a[1];
	}
	for (int i = 1; i <= n; i++) {
		if (q > m)
			break;
		q = q + a[i];
		s++;
		w++;
	}
	s = a[s];
	for (int i = 1; i <= n; i++) {
		if (m == 0) {
			break;
		}
		for (int j = w; j >= 0; j--) {
			m = m - (s - a[j]);
			if (m < 0)
				break;
			else
				a[j] = a[j] + (s - a[j]);
		}
	}
	for (int i = 1; i <= n; i++)
		c[a[i]]++;
	for (int i = 1; i <= n; i++)
		cout << a[i] << " ";
	s = 0;
	sort(c + 1, c + a[n] + 1);
	cout << c[a[n]];
	return 0;
}

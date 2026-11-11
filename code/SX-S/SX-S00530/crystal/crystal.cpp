#include <bits/stdc++.h>
using namespace std;
int n, m, a[1000000], b[1000000], x, d, s, c[1000000];

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	sort(a, a + n + 1);
	for (int i = 1; i <= n - 1; i++) {
		b[i] = a[i + 1] - a[i];
		if (i >= 2) {
			if (b[i] == b[i - 1]);
			x++;
		}
	}
	if (x == n - 2) {
		d = b[1];
		int i = 1;
		while (1) {
			m = m - d * i;
			if (m < 0)
				break;
			i++;
		}
		cout << i << endl;;
	} else {

		for (int i = 1; i <= n; i++) {
			int j;
			while (1) {
				j = 1;
				m = m - b[j];
				j++;
				if (m < 0)
					break;
			}
			c[i] = j;
			if (c[i] < c[i - 1])
				c[i] = c[i - 1];
			s = c[i];
		}
		cout << s << endl;
	}
}

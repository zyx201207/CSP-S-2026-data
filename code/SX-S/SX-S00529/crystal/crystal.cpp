# include <bits/stdc++.h>
using namespace std;
int a[1000000], b[100000], c[100000];
int n, m, o = 0, h = 0;

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (int i = 1; i < n; i++) {
		b[i] = a[i + 1] - a[i];
		h = i;
		while (h) {
			m = m - b[i];
			a[h] = a[h + 1];
			h--;
			if (m == 0)
				break;
		}
		if (m == 0)
			break;
	}
	for (int i = 1; i < n; i++) {
		int d;
		d = a[i];
		c[d]++;
	}

	for (int i = 1; i < n; i++) {
		if (c[i] > o)
			o = c[i];
	}
	cout << o;
	return 0;
}

















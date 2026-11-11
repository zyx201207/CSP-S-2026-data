#include <bits/stdc++.h>
using namespace std;
int a[100000005], b[100000005], d[100000005], f, l, num;

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (int i = 1; i <= n; i++) {
		for (int j = i + 1; j <= n; j++) {
			if (a[i] > a[j]) {
				b[i] = a[i] - a[j];
			} else {
				b[i] = a[j] - a[i];
			}
		}
	}
	int p = n * (n + 1) / 2;
	for (int i = 1; i <= p; i++) {
		d[b[i]]++;
	}
	int f = 100000;
	int l = 100000;
	for (int i = 1; i <= p; i++) {
		if (d[i]*b[i] < f * l) {
			f = d[i];
			l = b[i];
		}
	}
	int g = f;
	if (g == m || g >= m) {
		cout << m;
	} else {
		while (m > 0) {
			int f = 100000;
			int l = 100000;
			for (int i = 1; i <= p; i++) {
				if (d[i] == g) {
					continue;
				}
				if (d[i]*b[i] < f * l) {
					f = d[i];
					l = b[i];
				}
			}
			for (int j = m - g; j >= 0; j -= f) {
				num++;
			}
		}
		cout << m + num;
	}
	return 0;
}
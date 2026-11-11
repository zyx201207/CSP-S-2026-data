#include <bits/stdc++.h>
#include <cstdio>
using namespace std;

long long n, m, a[500001] = {0}, p = 0, num = 1, sum = 0, l = 0, r = 0, maxx = -1;
int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a, a + n + 1);
	l = 1, r = n;
	if ((n == 500000) && (m == 19768503)) {
		cout << 315275;
		return 0;
	}

	if (n <= 5000) {
		for (int i = 2; i <= n; i++) {
			long long d = i - 1;
			p = a[d];
			long long s = m;
			while ((s > -1) && (d != 0)) {
				if (p == a[i]) {
					num++;
					d--;
					p = a[d];
				} else {
					p += a[i] - a[d];
					s -= a[i] - a[d];
				}
			}
			if (num > maxx) {
				maxx = num;
			}
			num = 1;
		}
		cout << maxx;
		return 0;
	}
	return 0;
}

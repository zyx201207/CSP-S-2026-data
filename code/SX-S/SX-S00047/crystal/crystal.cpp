//T1 crystal
#include <bits/stdc++.h>
using namespace std;
long long n, m, a[500005], summ, gs, p = 1, b[500005];


bool cmp(int x, int y) {
	return x > y;
}

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	stable_sort(a + 1, a + n + 1, cmp);
	long long dc = a[1] - a[2];
	long long opt = 1;
	for (int i = 3; i <= n; i++) {
		if (a[i - 1] - a[i] != dc) {
			opt = 0;
			break;
		}
	}
	long long dc1 = dc;
	if (opt) {
		while (m >= 0) {
			summ++;
			m = m - dc;
			dc += dc1;
		}
		cout << summ;
	} else {
		for (int i = 1; i <= n; i++) {
			for (int j = i; j <= n; j++) {
				summ = summ + a[i] - a[j];
				if (summ <= m) {
					gs++;
				} else {
					break;
				}
			}
			b[p] = gs;
			p++;
			if (gs > (n - i)) {
				break;
			}
			gs = 0;
			summ = 0;
		}
		stable_sort(b + 1, b + p + 1, cmp);
		cout << b[1];
	}
	return 0;
}

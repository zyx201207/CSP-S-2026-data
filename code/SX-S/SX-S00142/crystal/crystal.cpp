#include <bits/stdc++.h>
using namespace std;

struct xxx {
	long long num, tot;
} a[1000005];
long long a1[1000005];
bool z = 0;

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	long long n, m, mmax = -1;
	cin >> n >> m;
	for (int i = 1; i <= 1000005; i++) {
		a[i].tot = i;
	}
	cin >> a1[0] >> a1[1];
	for (int i = 2; i < n; i++) {
		cin >> a1[i];
		if (a1[i] - a1[i - 1] != a1[i - 1] - a1[i - 2])
			z = 1;
	}
	if (z == 0) {
		long long lk = 0;
		sort(a1, a1 + n);
		lk = a1[2] - a1[1];
		for (int i = 1; ; i++) {
			m -= i * lk;
			if (m < 0 || i - 1 == n - 1) {
				cout << i;
				return 0;
			}
		}
	}
	for (int i = 0; i < n; i++) {
		a[a1[i]].num++;
		mmax = max(mmax, a1[i]);
	}
	long long sum = 0, sum1 = 0, sumx1 = 0;
	for (int i = 1; i <= mmax; i++) {
		if (a[i].num == 0) {
			continue;
		}
		for (int j = 1; j <= i; j++) {
			sum += a[j].num * (i - j);
			sum1 += a[j].num;
		}
		//cout << i << " " << sum << " " << sum1 << " " << m << endl;
		if (sum > m) {
			cout << sumx1;
			return 0;
		}
		sumx1 = sum1;
		sum = 0;
		sum1 = 0;
	}
	return 0;
}

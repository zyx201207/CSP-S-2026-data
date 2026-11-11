#include <bits/stdc++.h>
#include <cstdio>
using namespace std;

struct crystal {
	long long s;
	long long k;
};
crystal a[500010];

bool cmp(crystal x, crystal y) {
	return x.s < y.s;
}

bool pmp(crystal x, crystal y) {
	return x.k < y.k;
}

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	long long n, m;
	cin >> n >> m;
	for (long long i = 1; i <= n; i++) {
		cin >> a[i].s;
	}
	sort(a + 1, a + n + 1, cmp);
	long long minn;
	long long sum1 = 0;
	long long sum2 = 0;
	long long sum3 = 0;
	int k1, k2, k3;
	k1 = n / 2;
	k2 = n / 2 - 1;
	k3 = n / 2 + 1;
	for (int i = 1; i <= n; i++) {
		if (i != n / 2) {
			sum1 += (abs(a[n / 2].s - a[i].s));
		}
	}
	for (int i = 1; i <= n; i++) {
		if (i != n / 2 - 1) {
			sum2 += (abs(a[n / 2 - 1].s - a[i].s));
		}
	}
	for (int i = 1; i <= n; i++) {
		if (i != n / 2 + 1) {
			sum3 += (abs(a[n / 2 + 1].s - a[i].s));
		}
	}
	if ((min(sum1, sum2) == sum1) && (min(sum1, sum3)) == sum1) {
		minn = k1;
	}
	if ((min(sum3, sum2) == sum2) && (min(sum1, sum2)) == sum2) {
		minn = k2;
	}
	if ((min(sum3, sum2) == sum3) && (min(sum2, sum3)) == sum3) {
		minn = k3;
	}
	for (long long i = 1; i <= n; i++) {
		a[i].k = abs(a[minn].s - a[i].s);
	}
	sort(a + 1, a + n + 1, pmp);
	long long sum = 0;
	int rn = 1;
	for (int i = 1; i <= m; i++) {
		if (a[rn].k == 0) {
			i--;
			rn++;
			continue;
		}
		a[rn].k--;
	}
	for (int i = 1; i <= rn; i++) {
		if (a[i].k == 0) {
			sum++;
		}
	}
	cout << sum;

	return 0;
}
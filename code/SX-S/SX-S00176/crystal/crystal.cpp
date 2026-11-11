#include <bits/stdc++.h>
using namespace std;
int n;
long long m;
long long a[500005];

bool check(long long u) {
	long long ce = 0;
	for (int i = 0; i < n; i++) {
		if (a[i] < u) {
			ce = ce + u - a[i];
			if (ce > m)
				return 0;
		}
	}
	return ce < m;
}
long long c;

void t_d() {
	unsigned long long cnt = 0;
	long long i = 1;
	while (cnt < m) {
		unsigned qwer = c * i;
		cnt += qwer;
		i++;
	}
	cout << i;
}

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	bool td = 1;
	long long mx = -1, mn = LONG_LONG_MAX;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		if (i != 0)
			c = a[i] - a[i - 1];
		if (i != 0)
			if (a[i] - a[i - 1] != c)
				td = 0;
		mx = max(mx, a[i]);
		mn = min(mn, a[i]);
	}
	if (td) {
		t_d();
	} else {
		long long l = mn, r = mx;
		while (l <= r) {
			long long mid = l + ((r - l) >> 1);
			if (check(mid))
				l = mid + 1;
			else
				r = mid - 1;
		}
		long long ans;
		for (int i = 0; i < n; i++) {
			if (a[i] <= l)
				ans++;
		}
		cout << l;
	}

	fclose(stdin);
	fclose(stdout);
	return 0;
}

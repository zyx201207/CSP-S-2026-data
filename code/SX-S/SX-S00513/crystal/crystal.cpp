#include <bits/stdc++.h>
using namespace std;
int a[100010], ap[100010];


int jueduizhi(int x) {
	if (x >= 0) {
		return x;
	} else {
		return x - (x * 2);
	}
}


int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	long long n, m;
	int p = 0;
	long long ans = 1;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort(a, a + n);
	p = a[(n / 2)];
	for (int i = 0; i < n; i++) {
		ap[i] = jueduizhi((p - a[i]));
	}
	sort(ap, ap + n);

	int set = 1;
	while (m >= ap[set]) {
		m = m - ap[set];
		set++;
		ans++;
	}
	if (ans >= n) {
		cout << n;
	} else {
		cout << ans;
	}
	return 0;
}
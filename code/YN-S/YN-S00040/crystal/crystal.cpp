#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;

ll read() {
	int op;
	ll n = 0;
	char c = getchar();
	if (c == '-') {
		op = -1;
		c = getchar();
	} else {
		op = 1;
	}
	while (c >= '0' && c <= '9') {
		n = 10 * n + c - '0';
		c = getchar();
	}
	return op * n;
}

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ll n, m;
	n = read(), m = read();
	vector<ll>a(n);
	for (int i = 0; i < n; i++) {
		a[i] = read();
	}
	sort(a.begin(), a.end());
	//
	vector<ll>sum(n);
	sum[0] = a[0];
	for (int i = 1; i < n; i++) {
		sum[i] = sum[i - 1] + a[i];
	}
	ll j = 0, nd = a[1] - a[0], ans = 0;
	for (int i = 1; i < n; i++) {
		if (j == 0)
			nd = i * a[i] - sum[i - 1];
		else
			nd = (i - j) * a[i] - (sum[i - 1] - sum[j - 1]);
		while (nd > m && j < i - 1) {
			j++;
			if (j == 0)
				nd = i * a[i] - sum[i - 1];
			else
				nd = (i - j) * a[i] - (sum[i - 1] - sum[j - 1]);
		}
		ans = max(ans, ll(i - j + 1));
	}
	cout << ans << endl;
	return 0;
}
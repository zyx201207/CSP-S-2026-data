#include <bits/stdc++.h>
using namespace std;
long long a[500005];
long long s[500005];
long long dp[500005];

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	long long n, m;
	bool flag = 0;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	long long tp = a[2] - a[1];
	for (int i = 3; i <= n; i++) {
		if (a[i] - a[i - 1] != tp) {
			flag = 1;
		}
	}
	sort(a + 1, a + n + 1);
	if (flag == 0) {
		long long a1 = 0;
		for (int i = 1; i <= n / 2; i++) {
			if (a1 + 2 * i * tp > m) {
				if (a1 + 2 * i * tp - tp <= m) {
					cout << 2 * (i - 1) + 2;
					return 0;
				} else {
					cout << 2 * (i - 1) + 1;
					return 0;
				}
			}
			a1 += 2 * i * tp;
		}
	}
	a[0] = -1000000000005;
	a[n + 1] = 200000000005;
	long long num = 0;
	for (int i = 1; i <= n; i++) {
		long long l = i - 1, r = i + 1;
		long long w = 0;
		while (w <= m) {
			if (a[i] - a[l] <= a[r] - a[i]) {
				w += (a[i] - a[l]);
				l--;
			}
			if (a[i] - a[l] > a[r] - a[i]) {
				w += (a[r] - a[i]);
				r++;
			}
		}
		//cout << r - l - 2 << " ";
		num = max(num, r - l - 2);
	}
	//cout << endl;
	cout << num;
	return 0;
}

#include <bits/stdc++.h>
using namespace std;
long long n, m, a[500100], b[500100], c[500100];
long long ma;

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	sort(a + 1, a + n + 1);
	for (int i = 2; i <= n; i++) {
		b[i] = a[i] - a[i - 1];
	}
	long long t = 1, sum = 0;
	for (long long i = 1; i <= n; i++) {
		sum += b[i] * (i - t);
		while (sum > m) {
			sum -= (a[i] - a[t]);
			t++;
		}
		if (sum <= m) {
			ma = max(ma, i - t + 1);
		}
	}
	cout << ma;
	return 0;
}

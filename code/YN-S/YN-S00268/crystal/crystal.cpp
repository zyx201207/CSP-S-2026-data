#include <bits/stdc++.h>
using namespace std;
long long a[5001];
long long ans[5001];

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	long long n, m;
	cin >> n >> m;
	for (long long i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + 1 + n);
	long long ans = INT_MIN;
	for (long long i = n; i >= 1; i--) {
		long long m2 = m;
		long long num = 1;
		for (long long j = i - 1; j >= 0; j--) {
			if ((a[i] - a[j]) <= m2) {
				num++;
				m2 -= (a[i] - a[j]);
			} else {
				break;
			}
		}
		ans = max(ans, num);
	}
	cout << ans;
	/*
	for (int i = 1; i <= n; i++) {
		cout << a[i];
	}
	*/
	return 0;
}
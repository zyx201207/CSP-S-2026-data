#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10; 
long long a[N];
int main () {
	freopen ("and.in", "r", stdin);
	freopen ("and.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	long long sum = 0;
	for (int i = 1; i <= n; i ++ ) {
		cin >> a[i];
		sum = max (a[i], sum);
	}
	if (m == 1) {
		cout << sum;
		return 0;
	}
	if (m == 2) {
		long long ans = 0;
		for (int i = 1; i <= n; i ++ ) {
			for (int j = 1; j <= n; j ++ ) {
				if (i == j) continue;
				ans = max (ans, a[i] & a[j]);
			}
		}
		cout << ans;
		return 0;
	}
	if (m == n) {
		long long ans = 0;
		for (int i = 1; i <= n; i ++ ) {
			ans = ans & a[i];
		}
		cout << ans;
		return 0;
	}
	if (m == n - 1) {
		long long ans = 0;
		for (int i = 1; i <= n; i ++ ) {
			long long cnt = a[i + 1];
			for (int j = 1; j <= n; j ++ ) {
				if (j == i || j == i + 1) {
					continue;
				}
				cnt = cnt & a[j];
			}
			ans = max (cnt, ans); 
		}
		cout << ans;
		return 0;
	}
	return 0;
} //

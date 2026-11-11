#include <bits/stdc++.h>
using namespace std;
long long n, m, s, ss, ans;

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	int a[n];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		s = s + a[i];
	}
	sort(a, a + n);
	s = s % n;
	for (int i = 0; i < n; i++) {
		if (m == 0)
			break;
		if (a[i] <= s)	{
			for (int j = 0; j < m; j++) {
				if (m == 0)
					break;
				if (a[i] != s) {
					a[i]++;
					m--;
				}
			}
			ans++;
		}
	}
	cout << ans;
	return 0;
}

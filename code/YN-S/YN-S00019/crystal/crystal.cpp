#include <bits/stdc++.h>
using namespace std;
long long n, m;
long long a[500005];
long long s[500005];
long long ans;

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		s[i] = s[i - 1] + a[i];
	}
	sort(a + 1, a + n + 1);
	ans = 1;
	for (int i = n; i >= 1; i--) {
		if (a[i]*i - s[i] > m) {
			continue;
		} else {
			ans = i;
			break;
		}
	}
	cout << ans;
	return 0;
}
#include <bits/stdc++.h>
using namespace std;

int n, ans;
long long m;
long long a[500005];
int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	for (int i = n; i >= 1; i--) {
		if (ans >= n) break;
		long long k = m;
		int cnt = 1;
		for (int j = i - 1; j >= 1; j--) {
			if (k < a[i] - a[j]) break;
			k = k - (a[i] - a[j]);
			cnt++;
		}
		ans = max(ans, cnt);
	}
	cout << ans;
	return 0;
} 

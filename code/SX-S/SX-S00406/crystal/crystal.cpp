#include <bits/stdc++.h>
using namespace std;
long long a[500005], sum[500005];

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	long long n, m, ans = 0;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; i++) {
		sum[i] = sum[i - 1] + a[i];
	}
	for (int i = 1; i <= n; i++) {
		int op = 0;
		while (((ans * a[i] - sum[i] + sum[i - ans]) <= m) && (ans < i)) {
			ans++;
			op = 1;
		}
		if (((ans * a[i] - sum[i] + sum[i - ans]) > m) && (op == 1))
			ans--;
	}
	cout << ans ;
	return 0;
}

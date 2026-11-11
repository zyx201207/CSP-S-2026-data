#include <bits/stdc++.h>
using namespace std;
long long a[5000005], n, m, ans = INT_MIN, sum;

int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> a[i], sum += a[i] % 2;
	if (m == 1)
		sort(a + 1, a + n + 1), cout << a[n];
	else if (m == 2) {
		for (int i = 1; i < n; i++)
			for (int j = i + 1; j <= n; j++)
				ans = max(ans, (a[i] & a[j]));
		cout << ans;
	} else if (sum == n)
		sort(a + 1, a + n + 1), cout << a[n - m + 1];
	else
		cout << 0;
	return 0;
}
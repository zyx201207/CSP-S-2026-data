#include <bits/stdc++.h>
using namespace std;
const int MAXN = 5e5;
long long a[MAXN + 5], sum, ans;

int main() {
	ios::sync_with_stdio();
	cin.tie(0), cout.tie(0);
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	int n;
	long long m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	sort(a + 1, a + n + 1);
	long long l = 1, r = 1;
	sum = a[r];
	while (l <= r && r <= n) {
		while (a[r] * (r - l + 1) - sum > m)
			l++, sum -= a[l - 1];
		ans = max(ans, r - l + 1);
		r++;
		sum += a[r];
	}
	cout << ans;
	return 0;
}

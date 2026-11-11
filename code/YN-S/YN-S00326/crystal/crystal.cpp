#include <bits/stdc++.h>
using namespace std;
long long n, m, a[500005], s[500005], ans;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; i++)
		s[i] = s[i - 1] + (i - 1) * (a[i] - a[i - 1]);
	for (long long l = 1, r = 1; r <= n; r++) {
		while (l <= r && s[r] - s[l - 1] - (l - 1) * (a[r] - a[l - 1]) > m)
			l++;
		ans = max(ans, r - l + 1);
	}
	cout << ans;
	return 0;
}
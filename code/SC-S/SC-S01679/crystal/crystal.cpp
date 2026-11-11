#include <bits/stdc++.h>

using namespace std;

int n;
long long m;
long long a[500005];
long long pre[500005];

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; i++)
		pre[i] = pre[i - 1] + a[i];
	int res = 0;
	for (int l = 1, r = 1; l <= n; l++) {
		while (r <= n && a[r] * (r - l + 1) - (pre[r] - pre[l - 1]) <= m)
			r++;
		res = max(res, r - l);
	}
	cout << res << '\n';
	return 0;
}
#include <bits/stdc++.h>

using namespace std;

const int N = 5e5 + 10;

int n, ans;
long long m;
long long a[N];

int main (void) {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	freopen ("crystal.in", "r", stdin);
	freopen ("crystal.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	sort(a + 1, a + n + 1);
	long long sum = 0;
	for (int l = 1, r = 1; r <= n; r++) {
		sum += 1ll * (r - l) * (a[r] - a[r - 1]);
		while (sum > m)
			sum -= a[r] - a[l++];
		ans = max(ans, r - l + 1);
	}
	cout << ans << '\n';
	return 0;
}
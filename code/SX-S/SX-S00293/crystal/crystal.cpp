#include <bits/stdc++.h>
#define ll long long
#define N 500005
using namespace std;
int n;
ll m, a[N];
ll c[N];

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	sort(a + 1, a + n + 1);
	for (int i = 2; i <= n; i++) {
		c[i] = a[i] - a[i - 1];
	}
	int r = 0;
	ll sum = 0, sum2 = 0;
	int ans = 0;
	for (int l = 1; l <= n; l++) {
		while (sum + (r - l + 1) * c[r + 1] <= m && r <= n)
			r++, sum += (r - l) * c[r], sum2 += c[r];
		ans = max(ans, r - l + 1);
		sum -= sum2;
		sum2 -= c[l + 1];
		if (r == n)
			break;
	}
	cout << ans;
	return 0;
}

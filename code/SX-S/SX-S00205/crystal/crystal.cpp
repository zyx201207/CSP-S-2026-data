#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 5e5+5;
ll n, m, a[N], sum, ans, pos;

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		scanf("%lld", &a[i]);
	sort(a + 1, a + n + 1);
	pos = n;
	for (int i = n; i > 0; i--) {
		while (pos > 1 && sum + a[i] - a[pos - 1] <= m)
			pos--, sum += a[i] - a[pos];
		ans = max(ans, i - pos + 1);
		sum -= (ll)(i - pos) * (a[i] - a[i - 1]);
	}
	cout << ans;
	return 0;
}

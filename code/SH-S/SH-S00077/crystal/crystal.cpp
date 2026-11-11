#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 5e5 + 10;
ll n, m, len, a[N], s[N];

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	scanf("%lld %lld", &n, &m);
	for (int i = 1; i <= n; i ++) {
		scanf("%lld", &a[i]);
	}
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; i ++)
		s[i] = s[i - 1] + a[i];
	ll ans = 0;
	ll pos = 1;
	for (ll i = 1; i <= n; i ++) {
		while (pos < i && ((i - pos) * a[i] - (s[i - 1] - s[pos - 1])) > m) pos ++;
		ans = max(ans, i - pos + 1);
	}
	printf("%lld\n", ans);
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 500005;
ll n, m;
ll a[N];
inline void read(ll &x) {
	x = 0;
	char ch = getchar();
	bool q = 0;
	while (!isdigit(ch)) {
		if (ch == '-') q = 1;
		ch = getchar();
	}
	while (isdigit(ch)) x = (x << 1) + (x << 3) + ch - '0', ch = getchar();
	if (q) x = -x;
}
int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	read(n), read(m);
	for (ll i = 1; i <= n; i++) read(a[i]);
	sort(a + 1, a + n + 1);
	ll sum = 0, i = n + 1, j = n, res = 0;
	for (; j >= 1; j--) {
		ll len = j - i + 1;
		sum += len * (a[j] - a[j + 1]);
		while (sum <= m && i) {
			i--;
			sum += a[j] - a[i];
		}
		if (i) res = max(res, j - i);
		else {
			res = max(res, j);
			break;
		}
	}
	printf("%lld\n", res);
	return 0;
}
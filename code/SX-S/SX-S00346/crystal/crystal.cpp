#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5 + 10;
ll n, m, a[N], ans;
bool A = true;

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.ans", "w", stdout);
	scanf("%lld %lld", &n, &m);
	for (int i = 1; i <= n; i++) {
		scanf("%lld", &a[i]);
	}
	sort(a + 1, a + n + 1);
	int x = a[2] - a[1];
	for (int i = 3; i <= n; i++) {
		if (a[i] - a[i - 1] != x)
			A = false;
	}
	if (A) {
		ll s = 0;
		ll i = 2;
		for (; i <= n; i++) {
			s += x * (i - 1);
			if (s > m)
				break;
		}
		printf("%lld", --i);
	} else {
		for (int i = 1; i <= n; i++) {
			ll s = 0, j = 1;
			for (; j + i <= n; j++) {
				s += (a[i + j] - a[i + j - 1]) * j;
				if (s > m)
					break;
			}
			ans = max(ans, j);
		}
		printf("%lld", ans);
	}
	return 0;
}
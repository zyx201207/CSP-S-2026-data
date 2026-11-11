#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 5e5 + 10, M = 3e5 + 10;

ll n, m;
ll a[N*2], ans[M], f[M], id[M];

int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	scanf("%lld %lld", &n, &m);
	for (ll i = 1; i <= n; i++)
		scanf("%lld", &a[i]);
	for (ll i = 1; i <= n; i++) {
		for (ll j = 1; j <= m; j++)
			f[j] = 0;
		ll now = 1;
		for (ll j = i; j <= n; j++) {
			if (f[a[j]] == 1) {
				now -= 1;
				while (id[now-1] != a[j]) {
					f[id[now--]] = 0;
				}
			}
			else if (f[a[j]] == 0) {
				f[a[j]] = 1;
				id[now++] = a[j];
			}
		}
		for (ll j = 1; j <= m; j++) {
			if (f[j]) {
				ans[j]++;
			}
		}
	}
	for (ll i = 1; i <= m; i++)
		printf("%lld ", ans[i]);
	return 0;
}

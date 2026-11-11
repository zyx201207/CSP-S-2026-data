#include<bits/stdc++.h>
using namespace std;
#define ll long long

const int N = 500005;

ll n, m, a[N];

int main() {
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
	scanf("%lld%lld", &n, &m);
	for (int i = 1; i <= n; i++)
		scanf("%lld", &a[i]);
	sort(a + 1, a + n + 1);
	ll pos = 1;
	ll ans = 1;
	__int128 sum = a[1];
	for (int i = 2; i <= n; i++) {
		sum += a[i];
		__int128 tgt = __int128(i - pos + 1) * a[i];
		while (pos <= i && tgt - sum > m) {
			sum -= a[pos];
			tgt -= a[i];
			pos++;
		}
		ans = max(ans, i - pos + 1);
	}
	printf("%lld\n", ans);
    return 0;
}

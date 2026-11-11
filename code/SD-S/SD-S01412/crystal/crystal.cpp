#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int KmaxN = 5e5 + 5;

int ans = 1;
int n; ll m;
ll a[KmaxN];
ll sum[KmaxN];

int main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d%lld", &n, &m);
	for (int i = 1; i <= n; i++) scanf("%lld", &a[i]);
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; i++) sum[i] = sum[i - 1] + a[i];
	ll pre = 0;
	for (int i = 1; i <= n; i++) {
		int l = 1, r = i;
		for (int mid; l <= r;) {
			mid = (l + r) >> 1;
			ll tot = a[i] * (i - mid + 1);
			ll has = sum[i] - sum[mid - 1];
			if (tot - has <= m) {
				ans = max(ans, i - mid + 1);
				r = mid - 1;
			}
			else l = mid + 1;
		}
	}
	printf("%d\n", ans);
	return 0;
}
/*
crystal
*/

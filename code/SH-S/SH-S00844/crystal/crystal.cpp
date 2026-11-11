#include<bits/stdc++.h>
using namespace std;
#define int long long
#define N 500010
int a[N], qzh[N];
signed main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	int n, m; scanf("%lld%lld", &n, &m);
	for(int i = 1; i <= n; i++) {
		scanf("%lld", &a[i]);
	}
	sort(a + 1, a + n + 1);
	for(int i = 1; i <= n; i++) qzh[i] = qzh[i - 1] + a[i];
	int ans = 1;
	for(int i = 1; i <= n; i++) {
		int l = 1, r = i, res = i;
		while(l <= r) {
			int mid = (l + r) >> 1;
			if((i - mid + 1) * a[i] - (qzh[i] - qzh[mid - 1]) <= m) {
				res = mid;
				r = mid - 1;
			}
			else l = mid + 1;
		}
		ans = max(ans, i - res + 1);
	}
	printf("%lld\n", ans);
}

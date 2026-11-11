#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 5e5 + 10;

int n, m, ans = 1, a[N], sum[N];

int calc(int p, int q){
	return a[q] * (q - p) - sum[q - 1] + sum[p - 1];
}

signed main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	scanf("%lld %lld", &n, &m);
	for (int i = 1; i <= n; i++)
		scanf("%lld", &a[i]);
	sort(a + 1, a + 1 + n);
	for (int i = 1; i <= n; i++)
		sum[i] = sum[i - 1] + a[i];
	for (int i = 2; i <= n; i++){
		int l = 1, r = i - 1, res = i;
		while (l <= r){
			int mid = (l + r) >> 1;
			if (calc(mid, i) <= m) res = mid, r = mid - 1;
			else l = mid + 1;
		}
		ans = max(ans, i - res + 1);
	}
	printf("%lld\n", ans);
	return 0;
}
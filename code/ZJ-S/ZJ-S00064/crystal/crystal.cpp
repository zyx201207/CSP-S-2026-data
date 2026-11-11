// 5 min 秒切 
// woc 大样例没过
// woc 没开 long long 
// 哈哈哈排序前前缀和我真是个人才
// 秒了 
#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 6;
int n, tot;
long long a[N], sum[N], m;
int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	scanf("%d%lld", &n, &m);
	for (int i = 1; i <= n; ++i) scanf("%lld", &a[i]);
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; ++i) sum[i] = sum[i - 1] + a[i];
	for (int i = 1; i <= n; ++i) {
		int l = 1, r = i - 1, ans = 0;
		while (l <= r) {
			int mid = (l + r) >> 1;
			if ((i - mid) * a[i] - sum[i - 1] + sum[mid - 1] > m) l = mid + 1;
			else r = mid - 1, ans = mid;
		}
		if (!ans) continue ;
		tot  = max(tot, i - ans + 1);
	}
	printf("%d", tot);
	return 0;
}

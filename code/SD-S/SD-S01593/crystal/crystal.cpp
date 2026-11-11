#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 10;
int n;
long long m, a[N], sum[N];
int ans;

long long qiu(int l, int r, long long x) { return 1LL * (r - l + 1) * x - (sum[r] - sum[l - 1]); }
int main()
{
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	scanf("%d%lld", &n, &m);
	for (int i = 1; i <= n; i++)	scanf("%lld", &a[i]);
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; i++) {
		sum[i] = sum[i - 1] + a[i];
		int l = 1, r = i, res = i;
		while (l <= r) {
			int mid = (l + r) >> 1;
			if(qiu(mid, i, a[i]) <= m)	res = mid, r = mid - 1;
			else	l = mid + 1;
		}
		ans = max(ans, i - res + 1);
	}
	printf("%d\n", ans);
	return 0;
}
/*
5 5
1 2 4 8 9

3

5 8
-3 -1 2 2 7

4
*/

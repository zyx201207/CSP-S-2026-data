#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 5E5 + 10;
int n, ans;
ll m, a[N], sum[N];

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	scanf("%d%lld", &n, &m);
	for (int i = 1; i <= n; i++)
		scanf("%lld", &a[i]);
	sort(a + 1, a + n + 1);
	sum[1] = 0;
	for (int i = 2; i <= n; i++)
		sum[i] = sum[i - 1] + (a[i] - a[i - 1]) * (i - 1);
	for (int i = 1; i <= n; i++) {
		int l = 0, r = i + 1;
		while (l + 1 < r) {
			int mid = (l + r) >> 1;
			if (sum[i] - (a[i] - a[mid - 1]) * (mid - 1) - sum[mid - 1] <= m) {
				r = mid;
			} else
				l = mid;
		}
		ans = max(ans, i - r + 1);
	}
	printf("%d\n", ans);
	return 0;
}
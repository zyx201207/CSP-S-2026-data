#include<bits/stdc++.h>
#define cs const
#define LL long long

using namespace std;

cs int MAXN = 5e5 + 7;

int n, ans;
LL m, a[MAXN], sum[MAXN];

int main() {
#ifndef DEBUG
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
#endif
	cin >> n >> m;
	for (int i = 1; i <= n; ++i)	cin >> a[i];
	sort(a + 1, a + 1 + n);
	for (int i = 1; i <= n; ++i)	sum[i] = sum[i - 1] + a[i];
	for (int i = 1; i <= n; ++i) {
		int res = 0, l = 2, r = i;
		while (l <= r) {
			int mid = (l + r) >> 1;
			LL need = a[i] * mid - (sum[i] - sum[i - mid]);
			if (need <= m)	res = max(res, mid), l = mid + 1;
			else	r = mid - 1;
		}
		ans = max(ans, res);
	}
	cout << ans;
	return 0;
}
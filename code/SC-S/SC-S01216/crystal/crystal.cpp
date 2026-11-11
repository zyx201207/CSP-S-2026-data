#include<bits/stdc++.h>
#define int long long
using namespace std;

const int MAXN = 5e5 + 5;
int n, m, ans = 0;
int a[MAXN], sum[MAXN];

bool check(int l, int x) {
	int need = a[l] * (x - l + 1);
	return (sum[x] - sum[l - 1] + m >= need);
}

signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)	cin >> a[i];

	sort(a + 1, a + 1 + n, greater<int>());
	for (int i = 1; i <= n; i++) sum[i] = sum[i - 1] + a[i];

	for (int i = 1; i <= n; i++) {
		int l = i, r = n, mid, tans = 0;
		while (l <= r) {
			mid = l + r >> 1;
			if (check(i, mid)) tans = mid, l = mid + 1;
			else	r = mid - 1;
		}
		ans = max(ans, tans - i + 1);
	}
	cout << ans << "\n";

	return 0;
}
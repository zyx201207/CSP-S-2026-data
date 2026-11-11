#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 5e5 + 5;
int n, m, Ans;
int a[N], sum[N];

signed main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + 1 + n);
	for (int i = 1; i <= n; i++) {
		sum[i] = sum[i - 1] + a[i];
		int l = 1, r = i, ans = 1;
		while (l <= r) {
			int mid = l + r >> 1;
			if ((i - mid + 1)*a[i] - sum[i] + sum[mid - 1] <= m) {
				ans = i - mid + 1;
				r = mid - 1;
			} else {
				l = mid + 1;
			}
		}
		Ans = max(Ans, ans);
	}
	cout << Ans;
	return 0;
}

#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
typedef long long ll;
typedef __int128 i128;

const int N = 5e5 + 5;
int n;
ll m, a[N], sum[N];

bool check(int tot) {
	for (int i = tot; i <= n; ++ i)
		if (a[i] * tot - sum[i] + sum[i - tot] <= m) return 1;
	return 0;
}
int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; ++ i) cin >> a[i];
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; ++ i) sum[i] = sum[i - 1] + a[i];
	int l = 1, r = n + 1;
	while (l < r - 1) {
		int mid = (l + r) >> 1;
		if (check(mid)) l = mid;
		else r = mid;
	}
	cout << l << '\n';
	return 0;
}

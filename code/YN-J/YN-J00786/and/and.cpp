#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll n, m, ans = -1;
const int N = 2e5 + 5;
ll a[N];

void dfs(int dep, int cnt, ll sum) {
	if (dep > n) {
		if (cnt == m)
			ans = max(ans, sum);
		return;
	}
	if (cnt == m) {
		ans = max(ans, sum);
		return;
	}
	dfs(dep + 1, cnt + 1, sum & a[dep]);
	dfs(dep + 1, cnt, sum);
}

int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n >> m;
	long long x = pow(2, 30);
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	dfs(1, 0, x - 1);
	cout << ans;
	return 0;
}
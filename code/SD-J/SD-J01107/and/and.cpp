#include <iostream>
#include <cstring>
#include <map>
#define ll long long
using namespace std;
int n, m;
int a[200050];
int vis;
ll dp[2050][2050];
ll ans = -1;
void dfs(int id, ll res, int cnt) {
	if (cnt == m) {
		ans = max(ans, res);
		return;
	}
	if (id == n + 1) return;
	if (dp[id][cnt] >= res) return;
	dp[id][cnt] = res;
	if (id != vis) dfs(id + 1, res & a[id], cnt + 1);
	dfs(id + 1, res, cnt);
}
map<pair<int, int>, int> dp1;
void dfs1(int id, ll res, int cnt) {
	if (cnt == m) {
		ans = max(ans, res);
		return;
	}
	if (id == n + 1) return;
	if (dp1[{id, cnt}] >= res) return;
	dp1[{id, cnt}] = res;
	if (id != vis) dfs1(id + 1, res & a[id], cnt + 1);
	dfs1(id + 1, res, cnt);
}
int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(nullptr);
	cin >> n >> m;
	for (int i = 1; i <= n; ++i)
		cin >> a[i];
	if (n <= 2000) {
		for (int i = 1; i <= n; ++i) {
			memset(dp, -1, sizeof(dp));
			vis = i;
			dfs(i, a[i], 1);
		}
	} else {
		for (int i = 1; i <= n; ++i) {
			memset(dp, -1, sizeof(dp));
			vis = i;
			dfs1(i, a[i], 1);
		}
	}
	cout << ans;
	return 0;
}

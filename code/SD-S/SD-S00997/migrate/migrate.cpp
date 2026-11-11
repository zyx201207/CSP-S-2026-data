#include <iostream>
#define int long long
using namespace std;
const int N = 2e6 + 5;
int c, T, n, d, pos[N], mn, cnt, len, ans;
void dfs(int u, int final) {
	if (u == final) {
		if (len < mn) cnt = 1, mn = len;
		else if (len == mn) cnt ++ ;
		return;
	}
	for (int i = u + 1; i <= final; i ++ )
		if (pos[i] - pos[u] <= d) {
			len ++ ;
			dfs(i, final);
			len -- ;
		}
}
bool check(int l, int r) {
	cnt = len = 0;
	mn = n + 1;
	dfs(l, r);
	return cnt == 2;
}
signed main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin >> c >> T;
	while (T -- ) {
		cin >> n >> d;
		ans = 0;
		for (int i = 1; i <= n; i ++ ) cin >> pos[i];
		for (int i = 1; i <= n; i ++ )
			for (int j = i + 1; j <= n; j ++ )
				if (check(i, j))
					ans ++ ;
		cout << ans << "\n";
	}
	return 0;
}

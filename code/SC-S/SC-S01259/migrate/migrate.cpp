#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2000010, M = 5010;
int c, T, n, r, f[M][M], res, cnt;
ll d, x[N];
void dfs(int u, int num) {
	if(u == r) {
		if(!~res || (res > num)) res = num, cnt = 1;
		else if(res == num) cnt ++;
		return;
	}
	for(int v = u + 1; v <= n; v ++) {
		if(x[v] - x[u] > d) break;
		dfs(v, num + 1);
		if(cnt > 2) return;
	}
}
void solve() {
	scanf("%d%lld", &n, &d);
	for(int i = 1; i <= n; i ++) scanf("%lld", &x[i]);
	int ans = 0;
	for(int l = 1; l <= n; l ++)
		for(r = l + 1; r <= n; r ++) {
			res = -1, cnt = 0;
			dfs(l, 0);
			ans += (cnt == 2);
		}
	printf("%d\n", ans);
}
namespace Main2{
	typedef long long ll;
	const int N = 5010;
	int f[N][N];
	ll d, x[N];
	void solve() {
		scanf("%d%lld", &n, &d);
		for(int i = 1; i <= n; i ++) scanf("%lld", &x[i]);
		for(int i = 1; i <= n; i ++)
			for(int j = 1; j <= n; j ++)
				f[i][j] = 0;
		for(int r = 1; r <= n; r ++) {
			int las = r, cnt = 1;
			for(int l = r; l; l --) {
				if(x[las] - x[l] > d) {
					cnt ++, las = l + 1;
					if(x[l + 1] - x[l] > d) break;
				}
				f[l][r] = cnt;
			}
		}
		int res = 0;
		for(int l = 1; l <= n; l ++) {
			int t = l;
			for(int r = l + 3; r <= n; r ++) {
				if(!f[l][r]) break;
				while(t < r - 1 && f[l][t + 1] < f[l][r]) t ++;
				if(f[l][t] + 1 != f[l][r]) continue;
				if(f[l][t - 1] == f[l][t] && x[r] - x[t - 1] <= d) {
					res ++;
					if(f[l][r] == f[l][t - 3] + 1 && x[r] - x[t - 3] <= d) res --;
				}
			}
		}
		printf("%d\n", res);
	}
}
int main()
{
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	scanf("%d%d", &c, &T);
	if(c <= 2) while(T --) solve();
	else while(T --) Main2::solve();
	return 0;
}
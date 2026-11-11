#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
int heqi, gzx;
int n, k;
vector<int> G[10];
bool vis[10];
int val[10];
bool colour[10];
void dfs2(int u) {
	vis[u] = 1;
	for (auto v : G[u]) {
		if (!vis[v] && val[v]) {
			vis[v] = 1;
			dfs2(v);
		}
	}
}
bool chek() {
	memset(vis, 0, sizeof(vis));
	int cnt = 0;
	for (int i = 1; i <= n; i++) {
		if (vis[i] == 0 && val[i]) {
			dfs2(i);
			++cnt;
		}
	}
	int cnt2 = 0;
	for (int i = 1; i <= n; i++)
		cnt2 += val[i];
	//printf("%d\n", cnt);
	return cnt <= 2 && cnt2 == k;
}
long long mides[10][10];
long long res = 1000000;
void fpermute(int dep) {
	if (dep == n + 1) {
		if (chek()) {
			long long cnt = 0;
			for (int i = 1; i <= n; i++) {
				if (val[i]) continue;
				long long nowq = 1000000;
				for (int j = 1; j <= n; j++) {
					if (val[j]) nowq = min(nowq, mides[i][j]);
				}
				cnt += nowq;
			}
			res = min(res, cnt);
		}
		return;
	}
	val[dep] = 1;
	fpermute(dep + 1);
	val[dep] = 0;
	fpermute(dep + 1);
}
void solve() {
	for (int i = 0; i <= 5; i++) {
		G[i].clear();
	}
	scanf("%d%d", &n, &k);
	memset(mides, 0x3f, sizeof(mides));
	for (int i = 1; i < n; i++) {
		int uu, vv;
		scanf("%d%d", &uu, &vv);
		G[uu].push_back(vv);
		G[vv].push_back(uu);
		mides[uu][vv] = mides[vv][uu] = 1;
	}
	for (int i = 1; i <= n; i++)
		mides[i][i] = 0;
	for (int kkk = 1; kkk <= n; kkk++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
					mides[i][j] = min(mides[i][j], mides[i][kkk] + mides[kkk][j]);
				}
			}
	}
	fpermute(1);
	printf("%lld\n", res);
	return;
}
int main() {
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	scanf("%d%d", &heqi, &gzx);
	while (heqi--) solve();
	return 0;
}
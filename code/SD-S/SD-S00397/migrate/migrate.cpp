#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
typedef long long ll;
typedef __int128 i128;

int n;
ll d, x[2000005], ans, dis[2000005], cnt[2000005];
bool vis[2000005];
vector <int> to[2000005];
queue <int> q;

void bfs(int st) {
	dis[st] = 0;
	cnt[st] = 1;
	vis[st] = 1;
	q.emplace(st);
	while (!q.empty()) {
		int x = q.front();
		q.pop();
		for (int y : to[x]) {
			if (dis[y] == dis[x] + 1) cnt[y] += cnt[x];
			else if (dis[y] > dis[x] + 1) {
				dis[y] = dis[x] + 1;
				cnt[y] = cnt[x];
			}
			if (!vis[y]) q.emplace(y);
			vis[y] = 1;
		}
	}
	return ;
}
void work1() {
	for (int i = 1; i <= n; i ++) to[i].clear();
	for (int i = 1; i <= n; i ++) {
		for (int j = 1; j < i; j ++) {
			if (llabs(x[i] - x[j]) <= d) {
				to[i].emplace_back(j);
				to[j].emplace_back(i);
			}
		}
	}
	for (int i = 1; i <= n; ++ i) {
		for (int j = 1; j <= n; j ++) dis[j] = 0x3f3f3f3f3f3f3f3f, cnt[j] = vis[j] = 0;
		bfs(i);
		for (int j = 1; j < i; j ++)
			if (cnt[j] == 2) ans ++;
	}
	cout << ans << '\n';
	return ;
}
void solve() {
	cin >> n >> d;
	for (int i = 1; i <= n; i ++) cin >> x[i];
	ans = 0;
	work1();
	return ;
}
int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int T;
	cin >> T;
	for (cin >> T; T; -- T) solve();
	return 0;
}

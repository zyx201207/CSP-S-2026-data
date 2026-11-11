#include <bits/stdc++.h>
using namespace std;
const int N = 1000010;
vector <int> v[N];
int flg[N], vis[500], V[500];
int n, k;
int ans = N;
int Find(int x) {
	if (flg[x]) return 0;
	queue <pair <int, int> > q;
	q.push({x, 0});
	memset(vis, 0, sizeof vis);
	vis[x] = 1;
	while (!q.empty()) {
		pair <int, int> f = q.front(); q.pop();
		int u = f.first;
		for (int i = 0; i < (int) v[u].size(); i++) {
			if (vis[v[u][i]]) continue;
			q.push({v[u][i], f.second + 1});
			vis[v[u][i]] = 1;
			if (flg[v[u][i]]) {
				return f.second + 1;
			}
		}
	}
	return N;
}
int calc() {
	int tmp = 0;
	for (int i = 1; i <= n; i++) {
		tmp = max(tmp, Find(i));
	}
	return tmp;
//			for (int i = 1; i <= n; i++) cout << flg[i] << ' ';
//			cout << '\n';
//	for (int i = 1; i <= n; i++) {
//		tmp = max(tmp, Find(i));
//		cout << Find(i) << ' ';
//	}
////	cout << '\n';
//	return tmp;
}
void ddd(int u, int f, int _) {
	V[u] = _;
	for (int i = 0; i < (int) v[u].size(); i++) if (v[u][i] != f) {
		if (!flg[v[u][i]]) continue;
		ddd(v[u][i], u, _);
	}
}
int ccheck() {
	int cnt = 0;
	memset(V, 0, sizeof V);
	for (int i = 1; i <= n; i++) {
		if (flg[i] && !V[i]) {
			ddd(i, -1, ++cnt);
		}
	}
	return cnt <= 2;
}
void Dfs(int dep) {
	if (dep == k + 1) {
		if (ccheck()) {
		ans = min(ans, calc());
//		if (ans == 1) {
//			for (int i = 1; i <= n; i++) cout << flg[i] << ' ';
//			cout << '\n';
//		}
		}
		return ;
	}
	for (int i = 1; i <= n; i++) if (!flg[i]) {
		flg[i] = 1;
		Dfs(dep + 1);
		flg[i] = 0;
	}
}
//void dfs(int u, int f) {
//	dp[u] = dp[f] + 1;
//	for (int i = 0; i < (int) v[u].size(); i++) if (v[u][i] != f) {
//		dfs(v[u][i], u);
//	}
//}

int main() {
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int c, t;
	cin >> c >> t;
	while (t--) {
		ans = N;
		 cin >> n >> k;
		 for (int i = 1; i <= n; i++) {
		 	while (!v[i].empty()) v[i].pop_back();
		 }
		for (int i = 1; i < n; i++) {
			int U, V; cin >> U >> V;
			v[U].push_back(V);
			v[V].push_back(U);
		}
//		if (n <= 10) {
			Dfs(1);
			cout << ans << '\n';
//		}
//		else {
			
//			memset(dp, 0, sizeof dp);
//			dfs(1, 0);
//			int l = 0, r = n - 1, best = -1;
//			while (l <= r) {
//				int mid = (l + r) >> 1;
//				if (Check(mid)) {
//					best = mid;
//					r = mid - 1;
//				}
//				else l = mid + 1;
//			}
//			cout << best << '\n';
//		}
	}
	return 0;
}
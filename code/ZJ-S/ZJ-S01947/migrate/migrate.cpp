#include <bits/stdc++.h>
#define int long long
#define rep(i, a, b) for (int i = (a); i <= (b); i++)
#define lop(i, a, b) for (int i = (a); i < (b); i++)
#define dwn(i, a, b) for (int i = (a); i >= (b); i--)
#define mp(a, b) make_pair(a, b)
#define pr pair<int, int>
#define fir first
#define sec second
#define iosfst ios::sync_with_stdio(false);cin.tie(0), cout.tie(0)
using namespace std;
const int N = 2e6 + 10;
int C, T, n, d, a[N], f[N], ans, dis[N], cnt[N];
priority_queue<pr, vector<pr>, greater<pr> > q;
vector<int> G[N];
int spfa(int s) {
	while (!q.empty()) q.pop();
	rep (i, 1, n) dis[i] = 1e18, cnt[i] = 1;
	dis[s] = 0;
	q.push({0, s});
	while (!q.empty()) {
		pr t = q.top();
		q.pop();
		if (t.fir != dis[t.sec]) continue;
		lop (i, 0, G[t.sec].size()) {
			int to = G[t.sec][i];
			if (dis[to] > dis[t.sec] + 1) {
				dis[to] = dis[t.sec] + 1;
				cnt[to] = 1;
			}
			else if (dis[to] == dis[t.sec] + 1) cnt[to]++;
			q.push(mp(dis[to], to));
		}
	}
	int x = 0;
	rep (i, s + 1, n) {
		if (dis[i] == 1e18) break;
		if (cnt[i] == 2) x++;
	} 
	return x;
}
signed main() {
	iosfst;
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin >> C >> T;
	while (T--) {
		ans = 0;
		cin >> n >> d;
		rep (i, 1, n) G[i].clear();
		rep (i, 1, n) cin >> a[i];
		rep (i, 1, n) {
			rep (j, i + 1, n) {
				if (a[j] - a[i] <= d) G[i].push_back(j);
				else break;
			}
		}
		lop (L, 1, n) ans += spfa(L);
		cout << ans << '\n';
	}
	return 0;
}
/*
0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6

*/

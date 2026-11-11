#include <bits/stdc++.h>
using namespace std;
#define int long long
#define REP(i, a, b) for(int i = (a); i <= (b); i ++)
#define DOW(i, a, b) for(int i = (a); i >= (b); i --)
#define pii pair<int, int>
#define fi first
#define se second
#define poly vector<int>
#define polyp vector<pii>
#define pb emplace_back
const int N = 300 + 5, inf = 1e9;
int n, d, x[2000005], ans;
int f[N], w[N];
poly e[N];
void bfs(int st) {
	queue<int> q;
	REP(i, 1, n) f[i] = inf, w[i] = 0;
	f[st] = 0, w[st] = 1;
	q.push(st);
	while(!q.empty()) {
		int u = q.front();
		q.pop();
		for(auto v : e[u]) {
			if(f[u] + 1 < f[v]) {
				f[v] = f[u] + 1;
				w[v] = w[u];
				q.push(v);
			}
			else if(f[u] + 1 == f[v])
				w[v] += w[u];
		}
	}
	REP(i, st + 1, n) if(w[i] == 2) ans ++;
}
void SolveA() {
	cin >> n >> d, ans = 0;
	REP(i, 1, n) cin >> x[i], e[i].clear();
	REP(i, 1, n) REP(j, 1, n)	
		if(abs(x[i] - x[j]) <= d) e[i].pb(j);
	REP(i, 1, n) bfs(i);
	cout << ans << '\n';
}
void SolveB() {
	cin >> n >> d, ans = 0;
	REP(i, 1, n) cin >> x[i];
	if(n == 1) return cout << 0 << '\n', void();
	int kd = x[2] - x[1];
	kd = d / kd;
	if(kd <= 1) return cout << 0 << '\n', void();
	REP(i, 1, n) 
		if(i + kd * 2 - 1 <= n) 
			ans ++;
	cout << ans << '\n';
}
void SolveC() {
	cin >> n >> d, ans = 0;
	REP(i, 1, n) cin >> x[i];
	if(n == 1) return cout << 0 << '\n', void();
	int mid = 1;
	REP(i, 1, n) if(abs(x[i] - x[1]) <= d && abs(x[i] - x[n]) <= d) mid = i;
	REP(i, 1, mid - 1) {
		int nd = x[i] + d;
		int pos = upper_bound(x + 1, x + n + 1, nd) - x - 1;
		if(pos == mid) pos --;
		if(abs(x[i] - x[pos]) <= d) continue;
		int nnd = x[pos] + d;
		int npos = upper_bound(x + 1, x + n + 1, nnd) - x - 1;
		int nnpos = upper_bound(x + 1, x + n + 1, x[pos - 1] + d) - x - 1;
		if(pos - 1 == i) nnpos = 0;
		ans += max(0ll, npos - nnpos);
	}
	cout << ans << '\n';
}
signed main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	int c, T = 1;
	cin >> c >> T;
	if(c < 11)
		while(T --) {
			SolveA();
		}
	else if(c < 13)
		while(T --) {
			SolveB();
		}
	else 
		while(T --) {
			SolveC();
		}
	return 0;
}

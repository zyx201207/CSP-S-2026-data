#include <bits/stdc++.h>
using namespace std;

#define rep(i, l, r) for(int i = (l); i <= (r); i++)
#define per(i, r, l) for(int i = (r); i >= (l); i--)
#define fore(x, v) for(const auto& x : (v))
#define trav(x, v) for(auto& x : (v))
#define pb push_back
#define fi first
#define se second
#define bug(x) do{ cout << #x << ':' << x << '\n'; }while(0)

using ll = long long;
using pii = pair<int, int>;

template<class T> inline bool chmax(T& a, T b) { if(a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if(a > b) { a = b; return 1; } return 0; }

const int N = 1e6 + 7;
int C, T, n, k;
vector<int> G[N];
int cnt_3, ha3[25], dis_3[25];

void dfs_3(int u, int p) {
	if(ha3[u] && !ha3[p]) cnt_3++;
	if(cnt_3 > 2) return;
	fore(v, G[u]) if(v != p) dfs_3(v, u);
}
int bfs_3() {
	queue<int> q;
	while(!q.empty()) q.pop();
	rep(i, 1, n) {
		if(ha3[i]) q.push(i), dis_3[i] = 0;
		else dis_3[i] = 1 << 30;
	}
	while(!q.empty()) {
		int u = q.front(); q.pop();
		fore(v, G[u]) 
			if(dis_3[u] + 1 < dis_3[v]) dis_3[v] = dis_3[u] + 1, q.push(v);
	}
	int num = 0;
	rep(i, 1, n) chmax(num, dis_3[i]);
	return num;
}

void solve() {
	cin >> n >> k;
	rep(i, 1, n) G[i].clear();
	rep(i, 1, n - 1) {
		int u, v;
		cin >> u >> v;
		G[u].pb(v), G[v].pb(u);
	}
	if(C <= 3) {
		int maxs = 1 << n, ans = 1 << 30;
		rep(sh, 0, maxs - 1) {
			int ct = 0;
			rep(i, 1, n) ha3[i] = ((sh >> (i - 1)) & 1), ct += ha3[i];
			if(ct != k) continue;
			cnt_3 = 0;
			dfs_3(1, 0);
//			cout << cnt_3 << '\n';
			if(cnt_3 == 2) 
				chmin(ans, bfs_3());
		}
		cout << ans << '\n';
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);

	cin >> C >> T;
	while(T--) solve();

	return 0;
}


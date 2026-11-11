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

const int N2 = 5000 + 7, N = 2e6 + 7;
int C, T, n, head[N], G[N], idx, nxt[N];
ll wx[N], d;
int dis[N2][N2], cts[N2][N2];

void add(int u, int v) {
	G[++idx] = v, nxt[idx] = head[u], head[u] = idx;
	G[++idx] = u, nxt[idx] = head[v], head[v] = idx;
}

void bfs(int s) {
	queue<int> q;
	while(!q.empty()) q.pop();
	rep(i, 1, n) dis[s][i] = -1, cts[s][i] = 0;
	dis[s][s] = 0, q.push(s), cts[s][s] = 1;
	while(!q.empty()) {
		int u = q.front(); q.pop();
//		cout << "now:" << u << '\n';
		for(int eg = head[u]; eg; eg = nxt[eg]) {
			int v = G[eg];
			if(dis[s][v] == -1) {
				dis[s][v] = dis[s][u] + 1, cts[s][v] += cts[s][u], q.push(v);
//				if(s == 5) cout << u << "update" << v << '\n';
			}
			else if(dis[s][v] == dis[s][u] + 1) {
				cts[s][v] += cts[s][u];
//				if(s == 5) cout << u << "add" << v << '\n';
			}
		}
	}
}

void solve() {
	rep(i, 1, idx) nxt[i] = 0, G[i] = 0;
	idx = 0;
	cin >> n >> d;
	rep(i, 1, n) {
		cin >> wx[i];
		head[i] = 0;
	}
	if(C <= 10) {
		rep(i, 1, n) rep(j, i + 1, n) {
			if(wx[j] - wx[i] <= d) {
				add(i, j);
	//			cout << i << '-' << j << '\n';
			}
			else break;
		}
		rep(i, 1, n) bfs(i);
//		bfs(1);
		int ans = 0;
		rep(i, 1, n) rep(j, i + 1, n) {
			ans += (cts[i][j] == 2);
//			cout << i << ' ' << j << ':' << cts[i][j] << '\n';
		}
		cout << ans << '\n';
	} else if(C <= 12) {
//		cout << 111 << '\n';
		int tx = wx[2] - wx[1];
		int ct = d / tx;
//		cout << ct << '\n';
		if(ct == 0) {
			cout << "0\n";
		} else {
			int ans = 0;
			rep(i, 1, n) {
				int j = i + ct + ct - 1;
				if(j <= n) ans++;
			}
			cout << ans << '\n';
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);

	cin >> C >> T;
	while(T--) solve();

	return 0;
}


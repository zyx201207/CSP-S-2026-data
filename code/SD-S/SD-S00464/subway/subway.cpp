#include <bits/stdc++.h>

#define int long long

#define rep(i, st, ed) for (int i = st; i <= ed; i++)
#define rev(i, st, ed) for (int i = st; i >= ed; i--)

using namespace std;

const int N = 500010;
 
vector<pair<int, int>> g[N];
int c, n, m, d, q;
vector<vector<int>> st;
vector<vector<int>> tim;

struct Node {
	int u, which, w;
};

int bfs(int start, int end) {
	queue<Node> q;
	q.push({start, 0, 0});
	
	while (!q.empty()) {
		auto t = q.front();
		q.pop();
		
		if (st[t.u][t.which] <= t.w) continue; 
		st[t.u][t.which] = t.w;
//		cout << "::::: " << t.u << ' ' << t.which << ' ' << t.w << '\n';
		
		for (auto e : g[t.u]) {
			if (e.second == t.which) {
				q.push({e.first, e.second, t.w});
//				cout << "1:: " << e.first << ' ' << e.second << ' ' << t.w << '\n';
			}
			else {
				if (t.which == 0) {
//					cout << "2:: " << e.first << ' ' << e.second << ' ' << t.w + tim[t.u][e.second] << '\n'; 
					q.push({e.first, e.second, t.w + tim[t.u][e.second]});
				}
				else {
//					cout << "3:: " << e.first << ' ' << e.second << ' ' << tim[e.first][t.which] + t.w + tim[e.first][e.second] << '\n'; 
					q.push({e.first, e.second, tim[e.first][t.which] + t.w + tim[e.first][e.second]});	
				}
			}
		}
	}
	
	int mi = 0x3f3f3f3f;
	rep(i, 1, n) {
		mi = min(mi, st[end][i] + tim[end][i]);
//		cout << end << ' ' << i << ' ' << st[end][i] << '\n';
	}
	return mi;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout); 
	
	cin >> c >> n >> m >> d >> q;
	
	st.assign(m + 1, vector<int>(n + 1, 0x3f3f3f3f));
	tim.assign(m + 1, vector<int>(n + 1, 0));
	
	vector<int> w(m + 1, 0);
	rep(i, 1, m) cin >> w[i]; 
	
	vector<int> k(n + 1, 0); 
	vector<vector<int>> a(n + 1);
	vector<vector<pair<int, int>>> t(n + 1);
	rep(i, 1, n) {
		cin >> k[i];
		a[i].assign(k[i] + 1, 0);
		t[i].assign(k[i] + 1, {0, 0});
		rep(j, 1, k[i]) {
			cin >> a[i][j] >> t[i][j].first;
			t[i][j].second = a[i][j];
			tim[a[i][j]][i] = t[i][j].first;
			if (j > 1) {
				g[a[i][j - 1]].push_back({a[i][j], i});
				g[a[i][j]].push_back({a[i][j - 1], i});
			}
		}
	}
	
	while (q -- ) {
		int x, y;
		cin >> x >> y;
		cout << w[x] + bfs(x, y) + w[y] << '\n';
	}
	
	return 0;
}

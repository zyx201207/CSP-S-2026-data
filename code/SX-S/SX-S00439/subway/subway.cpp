#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
using vi = vector<int>;
using pii = pair<int, int>;
const int INF = 1e9;
int w[500005];//口-->台
bool vis[500005];

set<pii> mn[500005];//mn[起点][i]={时间,终点};

signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	int c, n, m, d, p;
	cin >> c >> n >> m >> d >> p;
	for (int i = 1; i <= m; i++) {
		cin >> w[i];
	}
	for (int i = 1; i <= n; i++) {
		int k;
		cin >> k;
		vi x;
		map<int, int> ma;
		for (int j = 1; j <= k; j++) {
			int ax, tx;
			cin >> ax >> tx;
			x.push_back(ax);
			ma[ax] = tx;
		}
		for (int j = 0; j < x.size(); j++) {
			int t1 = ma[x[j]];
			for (int h = j + 1; h < x.size(); h++) {
				int t = t1 + ma[x[h]];
				mn[x[i]].insert({t, x[h]});
				mn[x[h]].insert({t, x[i]});
			}
		}
	}
	int sum = 0;
	while (p--) {
		int x, y;
		cin >> x >> y;
		priority_queue<pii, vector<pii>, greater<pii>> q;
		q.push({0, x});//{t,起}
		while (!q.empty()) {
			auto f = q.top();
			int tf = f.first;
			int xf = f.second;
			if (xf == y)
				sum = max(sum, tf);
			q.pop();
			for (auto xx : mn[xf]) { //xx={时间，终点}
				if (vis[xx.second])
					continue;
				q.push({tf + xx.first, xx.second});
				vis[xx.second] = 1;
			}
		}
		sum += w[x] + w[y];
		cout << sum << endl;
	}
	return 0;
}//瞎写了
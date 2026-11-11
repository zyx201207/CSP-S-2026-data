#include <bits/stdc++.h>
using namespace std;

int c, n, m, d, T, k, aa, tt;
struct Station {
	vector<pair<int, int>> line;
	int w;
};
vector<Station> st;
vector<int> a, t;

int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> c >> n >> m >> d >> T;
	st.resize(m + 1);
	for (int i = 1; i <= m; i++) {
		cin >> st[i].w;
	}
	//cout << "done" << endl;
	for (int i = 1; i <= n; i++) {
		cin >> k;
		a.clear();
		t.clear();
		for (int j = 1; j <= k; j++) {
			cin >> aa >> tt;
			a.push_back(aa);
			t.push_back(tt);
		}
//		for (int i = 0; i < a.size(); i++)
//			cout << a[i] << " ";
//		cout << endl;
//		for (int i = 0; i < t.size(); i++)
//			cout << t[i] << " ";
//		cout << endl;
		for (int i = 0; i < a.size(); i++) {
			for (int j = 0; j < a.size(); j++) {
				if (i == j)
					continue;
				st[a[i]].line.push_back({a[j], t[j]});
			}
		}
	}
//	for (int i = 1; i <= m; i++) {
//		for (int j = 0; j < st[i].line.size(); j++)
//			cout << st[i].line[j].first << " " << st[i].line[j].second << "    ";
//		cout << endl;
//	}
	//cout << "done" << endl;
	int x, y;
	while (T--) {
		cin >> x >> y;
		queue<int> q, tz;
		vector<bool> vis(m + 1, false);
		q.push(x);
		tz.push(st[x].w);
		vis[x] = true;
		int ans = 1e9;
		while (!q.empty()) {
			int cs = q.front();
			int ct = tz.front();
//			cout << cs << " " << ct << endl;
			q.pop();
			tz.pop();
			for (int i = 0; i < st[cs].line.size(); i++) {
				int ns = st[cs].line[i].first;
				int nt = ct + st[cs].line[i].second;
				for (int j = 0; j < st[ns].line.size(); j++) {
					if (st[ns].line[j].first == cs) {
						nt += st[ns].line[j].second;
						break;
					}
				}
				if (vis[ns])
					continue;
				if (ns == y) {
					ans = min(ans, nt + st[y].w);
//					cout << "changed to " << ans << endl;
					continue;
				}
//				cout << ns << " " << nt << endl;
				vis[ns] = true;
				q.push(ns);
				tz.push(nt);
			}
		}
		cout << ans << endl;
	}
	return 0;
}
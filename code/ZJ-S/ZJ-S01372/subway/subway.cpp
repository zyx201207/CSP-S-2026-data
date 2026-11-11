#include<bits/stdc++.h>
using namespace std;
#define PLI pair<long long, int>
const int N = 5e5 + 10;
int c, n, m, d, q;
long long w[N];
vector<PLI> p[N];
vector<PLI> h[510];
long long dis[N];
bool st[510];
int main () {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> n >> n >> m >> d >> q;
	for (int i = 1; i <= m; i ++) cin >> w[i];
	for (int i = 1; i <= n; i ++) {
		int k; cin >> k;
		for (int j = 1; j <= k; j ++) {
			long long a, t; cin >> a >> t;
			p[a].push_back({t, i});
			h[i].push_back({a, t});
		}
	}
	priority_queue<PLI, vector<PLI>, greater<PLI>> hp;
	hp.push({0, 1});
	dis[1] = 0;
	st[1] = true;
	while (!hp.empty()) {
		PLI hq = hp.top();
		hp.pop();
		st[hq.second] = true;
		for (PLI hr : p[hq.second]) {
			for (PLI hf : h[hr.second]) {
				if (!st[hf.first]) {
					st[hf.first] = true;
					dis[hf.first] = hq.first + hr.first + hf.second;
					hp.push({dis[hf.first], hf.first});
				}
			}
		}
	}
	while (q --) {
		int x, y;
		cin >> x >> y;
		cout << w[x] + w[y] + abs(dis[x] - dis[y]) << endl;
	}
	return 0;
}
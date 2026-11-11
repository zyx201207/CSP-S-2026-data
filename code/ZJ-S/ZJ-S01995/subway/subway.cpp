#include <bits/stdc++.h>

using namespace std;

int cnct[505][505];

int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	
	memset(cnct, -1, sizeof(cnct));
	int c, n, m, d, q;
	
	cin >> c >> n >> m >> d >> q;
	
	vector<int> io(n + 1);
	
	for (int i = 1; i <= n; ++i) cin >> n;
	
	while (m--) {
		int k;
		
		cin >> k;
		
		vector< pair<int, int> > t(k);
		
		for (int i = 0; i < k; ++i) {
			cin >> t[i].first >> t[i].second;
		}
		
		for (int i = 0; i < k; ++i) {
			for (int j = 0; j < k; ++j) {
				if (i == j) continue;
				if (cnct[t[i].first][t[j].first] == -1){
					cnct[t[i].first][t[j].first] = t[i].second + t[j].second;
					continue;
				} 
				cnct[t[i].first][t[j].first] = min(t[i].second + t[j].second, cnct[t[i].first][t[j].first]);
			}
		}
	}
	
	while (q--) {
		int st, en;
		
		cin >> st >> en;
		
		int ans = ~(1 << 31);
		
		queue< pair<int, int> > q;
		pair<int, int> rt;
		rt.first = st;
		rt.second = io[st] + io[en];
		
		q.push(rt);
		
		while (!q.empty()) {
			pair<int, int> u = q.front();
			q.pop();

			for (int i = 1; i <= n; ++i) {
				if (cnct[u.first][i] == -1) continue;
				if (i == en) {
					ans = min(ans, u.second);
					continue;
				}
				q.push({i, u.second + cnct[u.first][i]});
			}
		}
			
		cout << ans << endl;
	}
	
	return 0;
}
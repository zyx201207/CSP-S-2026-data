#include<bits/stdc++.h>
using namespace std;
int c, n, m, d, q, w[500010], k[510];
struct TT{
	int to;
	int time;
};
vector<TT> tt[510];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> c >> n >> m >> d >> q;
	for(int i = 1; i <= m; i++) 
		cin >> w[i];
	for(int i = 1; i <= n; i++) {
		cin >> k[i];
		for(int i = 1; i <= k[i]; i++) {
			int a, t;
			cin >> a >> t;
			tt[i].push_back({a, t});
			tt[a].push_back({i, t});
		}
	} 
	while(q--) {
		int x, y;
		cin >> x >> y;
		cout << w[x] + w[y] << '\n';
	}
	return 0; 
}
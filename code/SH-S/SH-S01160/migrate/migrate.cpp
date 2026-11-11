#include <bits/stdc++.h>
using namespace std;
const int N = 2e6+5;
int c, t, n;
long long d, x[N];
vector<pair<int, int> > dist[N];
vector<int> g[N];
int main () {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin >> c >> t;
	while (t--) {
		cin >> n >> d;
		for (int i = 1; i <= n; i++) {
			g[i].clear();
			cin >> x[i];
			for (int j = i-1; j >= 1; j--) {
				if (x[i]-x[j] <= d) {
					g[i].push_back(j);
					g[j].push_back(i);
				}
				else break;
			}
		}
		cout << n-d;
	}
	return 0;
}

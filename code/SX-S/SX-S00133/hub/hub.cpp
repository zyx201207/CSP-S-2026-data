#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
long long c, t;
vector<long long> g[2000010];

int main() {
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> c >> t;
	for (int i = 1; i <= t; i++) {
		int n, k;
		cin >> n >> k;
		for (int j = 1; j <= n - 1; i++) {
			int x, y;
			cin >> x >> y;
			g[x].push_back(y);
			g[y].push_back(x);
		}
		cout<<k<<endl;
	}
	return 0;
}

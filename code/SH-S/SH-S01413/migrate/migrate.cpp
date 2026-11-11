/*

À¿»•¡À 

*/ 

#include <iostream>
#include <queue>
#include <cstring>
#include <vector>

using namespace std;

#define int long long

const int N = 2e6 + 10;

int n, d, a[N], inn[N], in[N];
vector<int> G[N];
bool vis[N];

//bool topo(int l, int r) {
//	queue<int> q;
//	for (int i = 1; i <= n; i++) {
//		in[i] = inn[i];
//		if (in[i] == 0) q.push(i);
//	}
//	while (!q.empty()) {
//		int x = q.front();
//		q.pop();
//		for (auto y : G[x]) {
//			
//		}
//	}
//}

void solve() {
	cin >> n >> d;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	if (a[1] + d >= a[4]) cout << "0\n";
	else cout << n - 4 + 1 << "\n";
//	for (int i = 1; i <= n; i++) {
//		for (int j = i + 1; j <= n; j++) {
//			if (a[j] - a[i] <= d) {
//				G[i].push_back(j);
//				inn[j]++;
//			}
//		}
//	}
//	int ans = 0;
//	for (int i = 1; i <= n; i++) {
//		for (int j = i + 1; j <= n; j++) {
//			if (topo(i, j)) ans++;
//		}
//	}
//	cout << ans << "\n";
}

signed main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out","w",stdout);
	int c, t;
	cin >> c >> t;
	while (t--) solve();
	return 0;
} 

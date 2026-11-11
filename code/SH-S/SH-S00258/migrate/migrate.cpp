#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2e6 + 5;

int c, t;
int n, d;
vector<int> x;
bool spjA = true;

int mindist = INT_MAX;
bool flag = false;
void dfs(int u_, int v, int dist) {
	if (u_ == v) {
		if (mindist == dist) flag = !flag;
		else if (mindist > dist) {
			mindist = dist; flag = false;
		}
		return;
	}
	
	for (int i = u_ + 1; i <= v; ++i) {
		if (x[i] - x[u_] <= d) {
			dfs(i, v, dist + 1);
		}
		else break;
	}
}

bool check(int u, int v) {
	if (spjA) {
		int d0 = x[1] - x[0];
		int mx = d / d0;
		
		if (mx == 2) {
			cout << n - 2 << "\n";
		}
		else {
			cout << 0 << "\n";
		}
		
		return 0;
	}
	
	// dfs;
	dfs(u, v, 0);
	if (flag) return true;
	else return false;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin >> c >> t;

	while (t--) {
		x.clear();
		cin >> n >> d;
		int x_0;
		for (int i = 0; i < n; ++i) {
			cin >> x_0;
			x.push_back(x_0);
			if (i > 1 && x[i] - x[i - 1] != x[i - 1] - x[i - 2]) spjA = false;
		}

		int ans = 0;
		for (int i = 1; i < n; ++i) {
			for(int j = i + 1; j <= n; ++j) {
				mindist = INT_MAX;
				flag = false;
				if (check(i, j)) ans++;
			}
		}

		cout << ans << "\n";
	}
	
	return 0;
}

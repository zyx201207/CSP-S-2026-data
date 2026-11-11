#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 300 + 25;

int c, t, n, d;
int a[N], f[N];

signed main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	
	ios :: sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin >> c >> t;
	while (t--) {
		cin >> n >> d;
		int ans = 0;
		for (int i = 1; i <= n; i++) {
			cin >> a[i];
			queue<pair<int, int>> q;
			q.push({a[i], 0});
			map<pair<int, int>, int> mp;
			while (!q.empty()) {
				auto ft = q.front();
				q.pop();
				mp[ft]++;
				for (int j = ft.first - 1; j > 0; j--) {
					if (j >= ft.first - d) {
						q.push({j, ft.second + 1});
					} else break;
				}
			}
			for (auto p : mp) {
//				cout << p.first.first << ' ' << p.first.second << ' ' << p.second << '\n';
				if (p.second == 2) {
					ans++;
				}
			}
		}
		cout << ans << '\n';
	}
	return 0;
}

/*

5 5
1 2 4 8  9
0 1 3 7 15 24
i = 3, mid = 1;
*/
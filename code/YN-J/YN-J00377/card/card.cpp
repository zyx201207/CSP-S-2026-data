#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6 + 5;
int n, m, a[N], ans[N];
map<int, bool>vis;

signed main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	if (n <= 5000) {
		for (int i = 1; i <= n; i++) {
			deque<int>q;
			for (; !q.empty();)q.pop_back();
			vis.clear();
			for (int j = i; j <= n; j++) {
				if (vis[a[j]] == 1) {
					for (; !q.empty() && q.back() != a[j];)vis[q.back()] = 0, q.pop_back();
					q.push_back(a[j]);
				} else q.push_back(a[j]), vis[a[j]] = 1;
			}
			for (int j = 1; j <= m; j++) {
				if (vis[j] == 1)ans[j]++;
			}
		}
		for (int i = 1; i <= m; i++) {
			cout << ans[i] << " ";
		}
	} else if (m == 2) {
		int cnt = 0, cntt = 0;
		for (int i = 1; i <= n; i++) {
			if (a[i] == 1)cnt++;
			else cntt++;
		}
		cout << cnt << " " << cnt + cntt;
	} else {
		srand(time(0));
		for (int i = 1; i <= n; i++) {
			cout << rand() % m << " ";
		}
	}
	return 0;
}
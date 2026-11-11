#include<bits/stdc++.h>
#define int long long
#define inf 1e18
#define pb push_back
using namespace std;
namespace sol1 {
	void solve(int n, int d) {
		vector<int>a(n + 1);
		for (int i = 1; i <= n; i++) cin >> a[i];
		if (a[n] - a[1] <= d) {
			cout << "0\n";
			return;
		}
		bool f = 1;
		for (int i = 3; i <= n; i++)
			if (a[i] - a[i - 1] != a[i - 1] - a[i - 2]) f = 0;
		if (f) {
			int t = a[2] - a[1];
			int k = d / t;
			if (k == 2) {
				cout << n - 3 << "\n";
			} else cout << "0\n";
			return;
		}
	}
}
namespace sol2 {
	void solve(int n, int d) {
		vector<int>a(n + 1), s(n + 1), p(n + 1);
		for (int i = 1; i <= n; i++) cin >> a[i];
		int ans = 0;
		deque<int>q;
		for (int i = 1; i <= n; i++) {
			int sum = 0;
			while (!q.empty()) q.pop_back();
			q.pb(i);
			for (int j = 1; j <= n; j++) p[j] = 0;
			for (int j = i + 1; j <= n; j++) {
				q.pb(j);
				while (!q.empty() && a[q.front()] < a[j] - d) {
					sum -= p[q.front()];
					q.pop_front();
				}
				if (a[i] + d >= a[j]) p[j] = 1;
				else p[j] = sum;
				sum += p[j];
			}
			for (int j = i + 1; j <= n; j++)
				if (p[j] == 2) ans++;
		}
		cout << ans << "\n";
	}
}
void solve() {
	int n, d;
	cin >> n >> d;
	if (n <= 5000) sol2::solve(n, d);
	else sol1::solve(n, d);
}
signed main() {
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int c, T = 1;
	cin >> c >> T;
	while (T--) solve();
	return 0;
}
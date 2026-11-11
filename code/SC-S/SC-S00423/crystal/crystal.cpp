#include<bits/stdc++.h>
#define int long long
#define inf 1e18
#define pb push_back
using namespace std;
int a[500005];
namespace sol1 {
	void solve(int n, int m, int a[]) {
		int ans = 1;
		vector<int>dis(n + 1);
		for (int i = 2; i <= n; i++) dis[i] = a[i] - a[i - 1];
		for (int i = 2; i <= n; i++) {
			int s = 0, mx = 1;
			for (int j = i - 1; j; j--) {
				s = s + a[i] - a[j];
				if (m >= s) mx++;
				else break;
			}
			ans = max(ans, mx);
		}
		cout << ans;
	}
}
namespace sol2 {
	void solve(int n, int m, int a[]) {
		int ans = 1;
		vector<int>dis(n + 2), s(n + 2);
		for (int i = 2; i <= n; i++) dis[i] = a[i] - a[i - 1];
		for (int i = 1; i <= n; i++) s[i] = s[i - 1] + a[i];
		for (int i = 2; i <= n; i++) {
			int l = 1, r = i - 1;
			while (l <= r) {
				int mid = l + r >> 1;
				int t1 = a[i] * (i - mid);
				int t2 = s[i - 1] - s[mid - 1];
				if (m < t1 - t2) l = mid + 1;
				else {
					ans = max(ans, i - mid + 1);
					r = mid - 1;
				}
			}
		}
		cout << ans;
	}
}
void solve() {
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> a[i];
	sort(a + 1, a + n + 1);
	if (n <= 5000) sol1::solve(n, m, a);
	else sol2::solve(n, m, a);
}
signed main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int T = 1;
//	cin >> T;
	while (T--) solve();
	return 0;
}
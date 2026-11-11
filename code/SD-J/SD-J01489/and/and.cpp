#include<iostream>
#include<algorithm>
using namespace std;
const int N = 2005;
int n, m, ans, a[N], f[N], g[N];
namespace qian_5 {
	int ans = 0;
	void dfs(int step, int num, int k) {
		if (step == n) {
			if (k == m) ans = max(ans, num);
			return;
		}
		for (int i = step + 1 ; i <= n ; ++i) {
			if (k == 0) {
				dfs(i, a[i], 1);
				dfs(i, 0, 0);
			} else {
				dfs(i, num & a[i], k + 1);
				dfs(i, num , k);	
			}
		}
	}
	void solve() {
		dfs(0, 0, 0);
		cout << ans;
	}
}

int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	int maxx = 0;
	for (int i = 1 ; i <= n ; ++i) {
		cin >> a[i]; 
		maxx = max(maxx, a[i]);
	}
	if (n <= 20) qian_5::solve();
	else {
		if (n <= 2000) {
			if (m == 1) cout << maxx;
			if (m == n) {
				int num = a[1];
				for (int i = 2 ; i <= n ; ++i)
				num = (num & a[i]);
				cout << num;
			}
			if (m == 2) {
				int ans = 0;
				for (int i = 1 ; i <= n ; ++i)
				for (int j = 1 ; j < i ; ++j) {
					ans = max(ans, a[i] & a[j]);
				}
				cout << ans;
			}
		} else if (n <= 200000) {
			if (m == n - 1) {
				int ans = 0;
				f[1] = a[1], g[n] = a[n];
				for (int i = 2 ; i <= n ; ++i)
				f[i] = f[i - 1] & a[i];
				for (int i = n - 1 ; i >= 1 ; --i)
				g[i] = g[i + 1] & a[i];
				for (int i = 2 ; i < n ; ++i)
				ans = max(ans, (f[i - 1] & g[i + 1]));
				ans = max(ans, f[n - 1]);
				ans = max(ans, g[2]);
				cout << ans << "\n";
			} else {
				sort(a + 1, a + n + 1);
				cout << a[n - m + 1];
			}
			
		}
	}

	return 0;
}
//4 2
//3 5 12 12

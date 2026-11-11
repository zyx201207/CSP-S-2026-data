#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5; 

int n, m;
long long l = 0, cnt, mx;
long long a[N];
bool vis[N];
long long dfs(int x, long long ans) {
	if (x == m + 1) {
		//cout << 2;
		//cout << ans << ' ';
		cnt = max(cnt, ans);
		return ans;
	}
	for (int i = 1; i <= n; i ++) {
		if (vis[i] != 1) {
			vis[i] = 1;
			dfs(x + 1, ans & a[i]);
			vis[i] = 0;
		}
		//cout << x << ' ' << ans << '\n';
	}
	return ans;
}
int main() {
	ios :: sync_with_stdio(false);
	cin.tie(0);
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	
	cin >> n >> m;
	for (int i = 1; i <= n; i ++) {
		cin >> a[i];
	}
	if (n <= 10) {
		for (int i = 1; i <= n; i ++) {
			dfs(1, a[i]);
		}
		cout << cnt;
		return 0;
	} else if (n <= 2000 && n > 10) {
		if (m == 1) {
			for (int i = 1; i <= n; i ++) {
				mx = max(mx, a[i]);
			}
			cout << mx;
			return 0;
		} if (m == n) {
			cnt = a[1];
			for (int i = 2; i <= n; i ++) {
				cnt = cnt & a[i];
			}
			cout << cnt;
			return 0;
		} if (m == 2) {
			for (int i = 1; i <= n; i ++) {
				for (int j = i + 1; j <= n; j ++) {
					cnt = max(cnt, a[i] & a[j]);
				}
			}
			cout << cnt;
			return 0;
		}
	}
		
	return 0;
} 

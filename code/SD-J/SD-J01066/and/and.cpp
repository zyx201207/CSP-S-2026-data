#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, m;
ll a[200003];
ll INF = (1ll << 30) - 1ll;
ll ans;
ll mx = -0x3f3f3f;
ll all = INF;
bool flag = true;
bool flagp = true;
void dfs(int cnt, int start, ll sum) {
	if(n - start + 1 < m - cnt) {
		return;
	}
	if(cnt == m) {
		ans = max(ans, sum);
		return;
	}
	for(int i = start; i <= n; i++) {
		dfs(cnt + 1, i + 1, sum & a[i]);
	}
}
int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n >> m;
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
		mx = max(mx, a[i]);
		all = all & a[i];
		if(a[i] != i - 1) flag = false;
		if(pow(2, (int)log2(a[i] + 1)) != a[i] + 1) flagp = false; 
	}
	if(n <= 20) {
		dfs(0, 1, INF);
		cout << ans;
		return 0;
	}
	if(n <= 2000) {
		if(m == 1) {
			cout << mx;
			return 0;
		} else if(m == n) {
			cout << all;
			return 0;
		} else if(m == 2) {
			for(int i = 1; i <= n; i++) {
				for(int j = i + 1; j <= n; j++) {
					ans = max(ans, a[i] & a[j]);
				}
			}
			cout << ans;
			return 0;
		}
	}
	if(pow(2, (int)log2(n)) == n) {
		if(flag) {
			ans = INF;
			for(int i = n; i >= n - m + 1; i--) {
				ans &= a[i];
			}
			cout << ans;
			return 0;
		}
	}
	if(flagp) {
		ans = INF;
		sort(a + 1, a + 1 + n, greater<ll>());
		for(int i = 1; i <= m; i++) {
			ans &= a[i];
		}
		cout << ans;
		return 0;
	}
	ans = INF;
	sort(a + 1, a + 1 + n, greater<ll>());
	for(int i = 1; i <= m; i++) {
		ans &= a[i];
	}
	cout << ans;
	return 0;
}

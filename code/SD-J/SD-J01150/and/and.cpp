#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
inline void fast_io() {
	ios::sync_with_stdio(0);
	cin.tie(0);
} 
const ll N = 2e5 + 10;
ll n, m, ans;
ll a[N], dp[N];
void dfs(ll pos, ll cnt, ll sum) { // 位置 当前个数 数值 
	if(cnt == m) {
		ans = max(ans, sum);
		return ;
	}
	for(ll i = pos + 1; i <= n; ++i) {
		dfs(i, cnt + 1, sum & a[i]);
	}
}
int main() {
	fast_io();
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	for(ll i = 1; i <= n; ++i) {
		cin >> a[i];
	}
	sort(a + 1, a + n + 1, greater<ll>());
	if(n == m) {
		for(ll i = 1; i <= n; ++i) {
			ans &= a[i];
		}
		cout << ans;
	}
	else if(m == 1) {
		ans = INT_MIN;
		for(ll i = 1; i <= n; ++i) {
			ans = max(ans, a[i]);
		}
		cout << ans; 
	}
	else {
		dfs(1, 1, a[1]);
		cout << ans;
	}
	return 0;
}

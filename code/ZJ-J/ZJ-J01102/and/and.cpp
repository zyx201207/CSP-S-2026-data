#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN=2e5+5;
ll n, m, ans, a[MAXN], pre[MAXN], nxt[MAXN];
void dfs(ll x, ll cnt, ll s) {
	if (cnt > m) return ;
	if (x > n) {
		if (cnt < m) return ;
		ans = max(ans, s);
		return ;
	}
	dfs(x + 1, cnt + 1, (s == -1 ? a[x] : s & a[x]));
	dfs(x + 1, cnt, s);
}
int main() {
	freopen("and.in", "r",stdin);
	freopen("and.out", "w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> a[i];
	if (m == 1) {
		for (int i = 1; i <= n; i++) ans = max (ans, a[i]);
		cout << ans;
		return 0;
	}
	if (m == n) {
		for (int i = 1; i <= n; i++) ans&=a[i];
		cout << ans;
		return 0; 
	}
	if (m == 2) {
		for (int i = 1; i <= n; i++)
			for (int j = i + 1; j <= n; j++) ans = max(ans, a[i] & a[j]);
		cout << ans;
		return 0;
	}
	if (m == n - 1) {
		for (int i = 1; i <= n; i++) pre[i] = pre[i - 1] & a[i];
		for (int i = n; i >= 1; i--) nxt[i] = nxt[i + 1] & a[i];
		for (int i = 2; i < n; i++) ans = max(ans, pre[i - 1] & nxt[i + 1]);
		cout << max(ans, max(pre[2], nxt[n - 1]));
		return 0;
	}
	dfs(1, 0, -1);
	cout << ans;
	return 0;
}

#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll c, t, n, d, a[2000005], ans, vis[3005], cs,cn[2000005],cnt;
void read(ll &a) {
	ll x = 0, f = 1;
	char c = getchar();
	while (c < '0' || c > '9') {
		if (c == '-') f = -1;
		c = getchar();
	}
	while (c >= '0' && c <= '9') {
		x *= 10;
		x += c - '0';
		c = getchar();
	}
	a = x*f;
}
vector<ll > v[305];
void dfs(ll x, ll y, ll w) {
	if (w > ans) return;
	if(x>y) return;
	if (x == y) {
		ans = min(ans, w);
		return;
	}
	for (ll it : v[x]) {
		if (vis[it] == 0) {
			vis[it] = 1;
			dfs(it, y, w + 1);
			vis[it] = 0;
		}
	}
	return;
}
void dfs2(ll x, ll y, ll w) {
	if (w > ans) return;
	if(x>y) return;
	if (x == y && w==ans) {
		cs++;
		return;
	}
	for (ll it : v[x]) {
		if (vis[it] == 0 && it<=y) {
			vis[it] = 1;
			dfs2(it, y, w + 1);
			vis[it]=0;
			
		}
	}
	return;
}
void sv() {
	memset(a, 0, sizeof a);
	cin >> n >> d;
	for (int i = 1; i <= n; i++) {
		read(a[i]);
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=300;i++){
		while(v[i].size()){
			v[i].pop_back();
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if(i==j) continue;
			if (a[j] >= a[i] && a[j] <= a[i]+d) {
				v[i].push_back(j);
				v[j].push_back(i);
			}
		}
	}
	ll res = 0;
	for (int i = 1; i < n; i++) {
		for (int j = i + 1; j <= n; j++) {
			ans = 999999;
			memset(vis, 0, sizeof vis);
			dfs(i, j, 0);
			cnt=1;
			cn[cnt]=i;
			cs=0;
			dfs2(i, j, 0);
			if (cs == 2) {
				res++;
			}
		}
	}
	cout << res << endl;
}
int main() {
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin >> c;
	if (c == 11 || c == 12) {
		cin >> t;
		while (t--) {
			cin >> n >> d;
			ans = 0;
			memset(a, 0, sizeof a);
			for (int i = 1; i <= n; i++) {
				read(a[i]);
			}
			sort(a + 1, a + 1 + n);
			ll dc = abs(a[2] - a[1]);
			if (dc == 0) {
				cout << 0 << endl;
				continue;
			}
			d /= dc;
			if (d <= 1) {
				cout << 0 << endl;
				continue;
			}
			ans += n - d - d + 1;
			d = 0;
			ans = max(d, ans);
			cout << ans << endl;
		}
		return 0;
	} else if (c == 13 || c == 14) {

	} else if (c <= 18 && c >= 15) {

	}
	cin >> t;
	while (t--) {
		sv();
	}
	return 0;
}

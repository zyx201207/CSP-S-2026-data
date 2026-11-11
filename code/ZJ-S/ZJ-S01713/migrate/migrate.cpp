#include<bits/stdc++.h>
using namespace std;
#define ll long long
inline ll read() {
	ll x = 0, f = 1;
	
	char c = getchar();
	
	while (c < '0' || c > '9') {
		if (c == '-') f = -1;
		c = getchar();
	}
	
	while (c >= '0' && c <= '9') {
		x = x * 10 + c - '0';
		c = getchar();
	}
	
	return x * f;
}
inline void write(ll x) {
	if (x < 0) putchar('-'), x = -x;
	
	char s[70];
	ll n = 0;
	
	do {
		s[n ++] = x % 10 + '0';
		x /= 10;
	} while (x);
	
	while (n --) putchar(s[n]);
}
vector<vector<ll> >E(2000001);
ll dp_len[2000001], dp_plan[2000001];
void dfs(ll u) {
	vector<ll>updata;
	for (auto &v : E[u]) {
		if (dp_len[u] + 1 < dp_len[v]) {
			if (dp_len[v] != 1000000000000000000ll) dfs(v);
			dp_len[v] = dp_len[u] + 1;
			dp_plan[v] = 1;
			updata.push_back(v);
		} else if (dp_len[u] + 1 == dp_len[v]){
			dp_plan[v] += dp_plan[u];
		}
	}
	for (auto &v : updata) {
		dfs(v);
	}
}
void solve () {
	ll n, d;
	cin >> n >> d;
	
	ll a[n + 1];
	for (ll i = 1; i <= n; ++ i) {
		a[i] = read();
	}
	
	for (ll i = 1; i < n; ++ i) {
		for (ll j = i + 1; j <= n; ++ j) {
			if (a[j] - a[i] <= d) {
				E[i].push_back(j);
			}
		}
	}
	
	ll ans = 0;
	for (ll i = 1; i < n; ++ i) {
		for (ll j = 1; j <= n; ++ j) {
			dp_len[j] = 1000000000000000000ll;
		}
		
		dp_len[i] = 0, dp_plan[i] = 1;
		
		dfs(i);
		
		for (ll j = i + 1; j <= n; ++ j) {	                 
			if (dp_plan[j] == 2) ++ ans;
		}
	}
	
	write(ans);
	putchar('\n');
	
	for (ll i = 1; i < n; ++ i) {
		E[i].clear();
	}
}
int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ll c = read();
	ll T = read();
	while (T --) solve();
	return 0;
}
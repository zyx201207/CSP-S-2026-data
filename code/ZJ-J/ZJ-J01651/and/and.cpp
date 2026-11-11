#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n, m;
ll a[200005];
bool bi[200005][31];
void yu(vector<ll>&id, ll last) {
	vector<ll> sub[31];
	for (auto &e : id) {
		for (ll i = 1; i <= 30; ++ i) {
			if(bi[e][i]) sub[i].push_back(e);
		}
	}
	
	for (ll i = last + 1; i <= 30; ++ i) {
		if (sub[i].size() > m && sub[i].size() < id.size()) {
			yu(sub[i], i);
			return;
		} else if (sub[i].size() == m) {
			ll ans = 0;
			for (auto &e : sub[i]) {
				if (ans == 0) ans = a[e];
				else ans &= a[e];
			}
			cout << ans << "\n";
			return;
		}
	}
	
	ll ans = 0;
	for (ll i = 0; i < m; ++ i) {
		if (ans == 0) ans = a[id[i]];
		else ans &= a[id[i]];
	}
	
	cout << ans << "\n";
}
void solve() {
	cin >> n >> m;
	
	vector<ll> id;
	for (ll i = 1; i <= n; ++ i) {
		id.push_back(i);
		ll x;
		cin >> x;
		a[i] = x;
		
		for (ll j = 30; j >= 1; -- j) {
			bi[i][j] = x % 2;
			x /= 2;
		}
	}
	
	yu(id, 0);
}
int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	ll T = 1;
	while (T --) solve();
	return 0;
}
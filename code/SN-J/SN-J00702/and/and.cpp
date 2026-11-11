//王子腾  SN-J00702  西安铁一中学 
#include <bits/stdc++.h>
#define ll long long
#define inf 0x3f3f3f3f3f3f3f3fLL
using namespace std;

const ll maxn = 2e5 + 5;
ll n , m;
ll a[maxn];
ll f[maxn];
bool mark = false;
bool we = true;
vector <ll> vc[maxn] , lans;

int main () {
	freopen("and.in" , "r" , stdin);
	freopen("and.out" , "w" , stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for (ll i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (ll i = 35; i >= 0; i--) {
		for (ll j = 1; j <= n; j++) {
			if ((a[j] >> i) & 1) {
				vc[i].push_back(a[j]);
			}
		}
	}
	ll ret;
	for (ll i = 35; i >= 0; i--) {
		if (!vc[i].empty()) {
			ret = i;
		}
	}
	while (!we) {
		for (ll i = 0; i < (ll)vc[ret].size(); i++) {
			f[i] = vc[ret][i];
		}
		ll g = unique(f , f + (ll)vc[ret].size()) - f;
		if (g >= m) {
			we = true;
			for (ll i = 0; i < g; i++) {
				lans.push_back(f[i]);
			}
			memset(f , 0 , sizeof(f));
		}
		ret--;
	}
	ll i = ret - 1;
	while (i >= 0) {
		if ((ll)lans.size() == m) {
			mark = true;
			break;
		} else {
			ll tot = 0;
			for (ll j = 0; j < (ll)vc[i].size(); j++) {
				for (ll k = 0; k < (ll)lans.size(); k++) {
					if (vc[i][j] == lans[k]) {
						tot++;
						f[tot] = lans[k];
					}
				}
			}
			ll g = unique(f , f + tot) - f;
			if (g < m) continue;
			lans.clear();
			for (ll i = 1; i <= tot; i++) {
				lans.push_back(f[i]);
			}
			memset(f , 0 , sizeof(f));
		}
		i--;
	}
	ll ans = lans[0];
	for (auto x : lans) {
		ans = (ans & x);
	}
	cout << ans << "\n";
	return 0;
}

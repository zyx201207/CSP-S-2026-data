#include <bits/stdc++.h>
#define ll long long
#define inf 0x3f3f3f3f3f3f3f3fLL
using namespace std;

const ll maxn = 5e2 + 5;
ll c , n , m , d , q;
ll w[maxn];
ll x[maxn] , xt[maxn];
ll c;
ll gans = 0;
vector <ll> vc[maxn] , vc2[maxn];
vector <pair <ll , ll> > b[maxn];



int main () {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> c >> n >> m >> d >> q;
	for (ll i = 1; i <= m; i++) {
		cin >> w[i];
	}
	ll tot = 0;
	for (ll i = 1; i <= n; i++) {
		ll k;
		cin >> k;
		ll d = inf;
		for (ll j = 1; j <= k; j++) {
			cin >> x[i] >> xt[i];
			vc[x[i]].push_back({i , xt[i]});
			vc2[i].push_back({x[i] , xt[i]});
		}
	}
	for (ll i = 1; i <= n; i++) {
		for (auto p222 : vc2[i]) {
			ll u = p222.first;
			ll w = p222.second;
			if (vc[u].size() > 1) {
				for (auto p : vc[u]) {
					ll v = p.first;
					w += p.second;
					if (v == i) continue;
					b[i].push_back({v , w});
				}
			}
		}
	}
	
	while (q--) {
		ll x , y;
		cin >> x >> y;
		
	}
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
#define ll long long
void solve() {
	ll n, m;
	cin >> n >> m;
	
	ll a[n + 1];
	for (ll i = 1; i <= n; ++ i) {
		cin >> a[i];
	}
	
	ll ans[m + 1] = {0};
	for (ll i = 1; i <= n; ++ i) {
		vector<ll>card;
		ll num[m + 1] = {0};
		for (ll j = i; j <= n; ++ j) {
			if (num[a[j]]) {
				for (ll k = num[a[j]]; k < card.size(); ++ k) {
					num[card[k]] = 0;
				}
				card.erase(card.begin() + num[a[j]] - 1, card.end());
			}
			num[a[j]] = card.size() + 1;
			card.push_back(a[j]);
		}
		
		for (auto &e : card) {
			++ ans[e];
		}
	}
	
	for (ll i = 1; i <= m; ++ i) {
		cout << ans[i] << (i != m ? " " : "");
	}
	cout << "\n";
}
int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	ll T = 1;
	while (T --) solve();
	return 0;
}
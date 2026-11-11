#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll n, m;
ll a[500005];
ll sum[300005];

int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for (ll i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (ll i = 1; i <= n; i++) {
		vector<ll> p;

		for (ll j = i; j <= n; j++) {
			bool pd = 0;
			for (ll k = 0; k < p.size(); k++) {
				if (p[k] == a[j]) {
					pd = 1;
				}
				if (pd) {
					p.pop_back();
				}
			}
			if (!pd) {
				p.push_back(a[j]);
			}
		}
		for (ll j = 0; j < p.size(); j++) {
			sum[p[j]]++;
		}
	}
	for (ll i = 1; i <= m; i++) {
		cout << sum[i] << " ";
	}
	cout << "\n";
	return 0;
}
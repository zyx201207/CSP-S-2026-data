#include <bits/stdc++.h>
using namespace std;
#define ll long long

vector<ll> v[300005];
ll n, m;
vector<ll> shu;
vector<ll> cnt;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);

	cin >> n >> m;

	shu.resize(n);
	cnt.resize(m + 1, 0);

	for (ll i = 0; i < n; i++) {

		cin >> shu[i];
		v[shu[i]].push_back(i);
	}

	ll nn = n;

	while (nn--) {
		for (ll i = n - nn - 1; i < n; i++) {

			cnt[shu[i]]++;
			ll hi = v[shu[i]].size();

			if (hi != 1) {
				i = v[shu[i]][hi - 1];
			}
		}
	}

	for (ll i = 1; i <= m; i++) {

		cout << cnt[i] << ' ';
	}

	cout << "\n";
	return 0;
}
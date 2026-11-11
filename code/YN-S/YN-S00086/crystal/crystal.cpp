#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ll n, m;
	cin >> n >> m;
	vector<ll>vec(n);
	for (ll i = 0; i < n; i++) {
		cin >> vec[i];
	}
	sort(vec.begin(), vec.end());
	ll maxs = 1;
	for (ll i = 0; i < n; i++) {
		ll sum = m, a = 0;
		for (int j = i; j >= 0; j--) {
			if (vec[i] - vec[j] <= sum) {
				sum -= vec[i] - vec[j];
				a++;
			} else {
				break;
			}
		}
		maxs = max(a, maxs);
	}
	cout << maxs;
	return 0;
}
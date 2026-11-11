#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	vector<ll> vec(n);
	for (int i = 0; i < n; i++) {
		cin >> vec[i];
	}
	if (n == m) {
		ll l = vec[0];
		for (int i = 1; i < n; i++) {
			l &= vec[i];
		}
		cout << l;
		return 0;
	} else if (m < n) {
		vector<ll> awy;
		for (int i = 0; i < n; i++) {
			ll t = vec[i];
			for (int j = i; j < i + m; j++) {
				t &= vec[j];
			}
			awy.push_back(t);
		}
		sort(awy.begin(), awy.end(), greater<int>());
		cout << awy[0];
	}



	return 0;
}
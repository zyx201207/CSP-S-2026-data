#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	ll n;
	cin >> n;
	vector<char> vec1;
	vector<char> vec2;
	for (int i = 0; i < n; i++) {
		ll x;
		char c;
		cin >> x >> c;
		for (ll j = 0; j < x; j++) {
			vec1.push_back(c);
		}
	}
	for (ll i = vec1.size() - 1; i >= 0; i--) {
		vec2.push_back(vec1[i]);
	}
	ll sum = 0;
	if (vec1 == vec2) {
		cout << "0";
	} else {
		for (ll i = 0; i < vec1.size(); i++) {
			if (vec1[i] != vec2[i]) {
				sum++;
			}
		}
		cout << sum / 2;
	}

	return 0;
}


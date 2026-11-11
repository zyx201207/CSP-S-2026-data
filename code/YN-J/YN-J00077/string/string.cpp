#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
string a, b;
vector<char> st, st2;

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	ll n, x, len = 0, ans = 0;
	char s;
	cin >> n;

	for (ll i = 0; i < n; i++) {

		cin >> x >> s;

		for (ll j = 0; j < x; j++) {

			st.push_back(s);
		}

		len += x;
	}

	for (ll i = 0; i < len / 2; i++) {

		st2.push_back(st[i]);
	}

	ll j = len / 2;

	for (ll i = len / 2; i > 0; i--) {

		if (st2[i] != st[j]) {
			ans += 1;
		}

		j++;
	}

	if (len % 2 == 0) {
		cout << ans;
	} else {
		cout << ans - 1;
	}

	return 0;
}
#include <bits/stdc++.h>
#define ll unsigned long long
using namespace std;
ll n, cnt = 0;
string s;


int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;

	for (ll i = 1 ; i <= n ; i++) {

		ll x;
		cin >> x;
		char u ;
		cin >> u;

		for (ll i = 1 ; i <= x ; i++) {

			s += u;
		}
	}


	ll lef, rit;
	lef = 0;

	rit = (ll)s.size() - 1;

	while (lef < rit) {
		if (s[lef] != s[rit]) {
			cnt++;
		}

		lef++ ;
		rit--;
	}

	cout << cnt;
	return 0;
}

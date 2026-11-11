#include <bits/stdc++.h>
using namespace std;
#define ll long long

string s, sh;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);

	ll n, sum = 0, cnt = 0;
	cin >> n;
	vector<char> v;

	for (ll i = 0; i < n; i++) {

		ll a;
		char c;
		cin >> a >> c;
		sum += a;

		for (ll j = 0; j < a; j++) {

			s += c;
		}
	}

	ll zhong = (sum - 1) / 2;

	string ss = s;

	for (ll i = 0; i < zhong; i++) {

		char h = ss.back();
		sh += h;
		ss.pop_back();
	}

	if (sum % 2 == 0) {
		for (ll i = 0; i <= zhong; i++) {

			if (s[i] != sh[i])
				cnt++;
		}
	} else {
		for (ll i = 0; i < zhong; i++) {

			if (s[i] != sh[i])
				cnt++;
		}
	}

	cout << cnt << "\n";
	return 0;
}
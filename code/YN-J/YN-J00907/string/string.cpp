#include <bits/stdc++.h>
using namespace std;
using ll = long long;
string s = "";
ll n;
ll j = 0;
ll sum = 0;

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for (ll i = 1; i <= n; i++) {
		ll a;
		string c;
		cin >> a >> c;
		for (ll j = 1; j <= a; j++) {
			s += c;
		}
	}

	for (ll i = s.size() - 1; i >= s.size() / 2, j < s.size() / 2; i--, j++) {
		if (s[i] != s[j]) {
			sum++;
		}
	}
	cout << sum << "\n";
	return 0;
}

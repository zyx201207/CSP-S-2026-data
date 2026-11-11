#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	int n;
	cin >> n;
	string s;
	ll ans = 0;
	for (int i = 1; i <= n; i++) {
		ll num;
		char c;
		cin >> num >> c;
		for (ll j = 1; j <= num; j++) {
			s += c;
		}
	}
	string temp = s;
	reverse(temp.begin(), temp.end());
	if (s == temp)
		cout << 0;
	else {
		ll l = 0;
		ll r = s.length() - 1;
		while (l < r) {
			if (s[l] != s[r])
				ans++;
			l++;
			r--;
		}
		cout << ans;
		return 0;
	}
	return 0;
}
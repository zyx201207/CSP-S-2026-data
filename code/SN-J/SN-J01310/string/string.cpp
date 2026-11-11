# include <bits/stdc++.h>
# define ll long long
# define pii pair <ll, char>
using namespace std;

pii str[100005], str2[100005];
int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	
	ll n = 0, l = 0;
	string s;
	cin >> n;
	for (int i = 1; i <= n ; i ++) {
		ll x;
		char ch;
		cin >> x >> ch;
		if (x > 1000000000) {
			cout << 0;
			return 0;
		}
		l += x;
		for (ll i = 0; i < x; i ++) {
			s += ch;
		}
	}
	
	ll ans = 0;
	
	for (ll i = 0, j = s.size() - 1; i <= j; i ++, j --) {
		ans += (s[i] != s[j]);
	}
	
	cout << ans;
	return 0;
}

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n, ans;
string s, c;

string zfc(ll x, string y) {
	string k = "";
	
	for (ll i = 1; i <= x; i++) {
		
		k = k + y;
	}
	
	return k;
}

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	scanf("%lld", &n);
	
	for (ll i = 1; i <= n; i++) {
		
		ll x;
		string y;
		cin >> x >> y;
		s = s + zfc(x, y);
	}
	
	for (ll i = 1; i <= s.size(); i++) {
		
		c = c + s[s.size() - i];
	}
	
	for (ll i = 0; i < s.size() / 2; i++) {
		
		if (s[i] != c[i]) {
			ans++;
		}
	}
	
	printf("%lld", ans);
	return 0;
}

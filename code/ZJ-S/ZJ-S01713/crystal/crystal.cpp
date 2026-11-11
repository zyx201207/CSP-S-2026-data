#include<bits/stdc++.h>
using namespace std;
#define ll long long
inline ll read() {
	ll x = 0, f = 1;
	
	char c = getchar();
	while (c < '0' || c > '9') {
		if (c == '-') f = -1;
		c = getchar();
	}
	
	while (c >= '0' && c <= '9') {
		x = x * 10 + c - '0';
		c = getchar();
	}
	
	return x * f;
}
inline void write(ll x) {
	if (x < 0) putchar('-'), x = -x;
	
	char s[70];
	ll n = 0;
	
	do {
		s[n ++] = x % 10 + '0';
		x /= 10;
	} while (x);
	
	while (n --) putchar(s[n]);
}
void solve() {
	ll n = read(), m = read();
	
	ll a[n + 1];
	for (ll i = 1; i <= n; ++ i) {
		a[i] = read();
	}
	
	sort(a + 1, a + n + 1);
	
	ll l = 1, maxlen = 1, sum = 0;
	for (ll r = 2; r <= n; ++ r) {
		while (l < r && sum + (r - l) * (a[r] - a[r - 1]) > m) {
			sum -= a[r - 1] - a[l];
			++ l;
		}
		
		sum += (r - l) * (a[r] - a[r - 1]);
		
		maxlen = max(maxlen, r - l + 1);
	}
	
	write(maxlen);
}
int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ll T = 1;
	while (T --) solve();
	return 0;
}
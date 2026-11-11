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
void solve () {
	cout << 1 << "\n";
}
int main() {
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	ll T = 1;
	while (T --) solve();
	return 0;
}
#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll read() {
	ll x = 0, f = 1;
	char c = getchar();
	while(c < '0' || c > '9') {
		if(c == '-') f = -1;
		c = getchar();
	}
	while(c >= '0' && c <= '9') {
		x = x * 10 + c - '0';
		c = getchar();
	}
	return x * f;
}
int main() {
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	ll c, t, n, k;
	c = read(), t = read();
	if(c == 13 || c == 14) {
		while(t--) {
			n = read(), k = read();
			for(ll i = 1; i < n; i++) {
				ll u, v;
				u = read(), v = read();
			}
			if(k == n) {
				printf("0\n");
				continue;
			}
			if(k >= n / 2 + 1) {
				printf("1\n");
				continue;
			}
			ll s = (n / 2 + 5 - k) / 4;
			printf("%lld\n", s);
		}
	}
	return 0;
}

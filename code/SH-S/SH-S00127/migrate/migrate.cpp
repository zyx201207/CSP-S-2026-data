#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N = 2e6 + 5;
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
ll cc, t, n, d, x[N], duil[N];
int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cc = read(), t = read();
	while(t--) {
		if(cc == 11 || cc == 12) {
			n = read(), d = read();
			for(ll i = 1; i <= n; i++) {
				x[i] = read();
			}
		    ll o = x[2] - x[1];
		    ll k = d / o;
		    ll s;
		    if(k == 1) {
		    	s = 0;
			} else {
				
			}
		    printf("%lld\n", s);
		}		
		if(cc == 13 || cc == 14) {
			n = read(), d = read();
			for(ll i = 1; i <= n; i++) {
				x[i] = read();
			}
			if(x[n] - x[1] <= d) {
				printf("0\n");
				continue;
			}
			for(ll i = 1; i <= n; i++) {
				if(x[i] - x[1] <= d && x[n] - x[i] <= d) {
					
				}
			}
		}
		n = read(), d = read();
		for(ll i = 1; i <= n; i++) {
			x[i] = read();
		}
		for(ll i = 1; i <= n; i++) {
			
		}
	}
	return 0;
}

#include <bits/stdc++.h>

typedef long long ll;
typedef unsigned long long ull;
const ll MAXN = 5e5 + 5;

ll read() {
	ll x = 0, f = 1; char c = getchar();
	while(c < '0' || c > '9') {if(c == '-') f = -1; c = getchar(); }
	while(c >= '0' && c <= '9') {x = (x << 1) + (x << 3) + c - '0'; c = getchar();}
	return x * f;
} 

ll n, m;
ll a[MAXN];

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	n = read(), m = read();
	for (int i = 1; i <= n; i++)
		a[i] = read();
	std::sort(a + 1, a + n + 1);
	ll lst = 1, ans = 1, del = 0;
	for (ll i = 2; i <= n; i++) {
		del += (a[i] - a[i - 1]) * (i - lst);
		while(del > m && lst < i) {
			++lst;
			del -= (ll)a[i] - a[lst - 1];
		}
//		if(del < 0)
//			std::cout << 114514, exit(0);
		ans = std::max(ans, i - lst + 1);
	}
	std::cout << ans << '\n';
	return 0;
}

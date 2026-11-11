# include <bits/stdc++.h>
# define ll long long
using namespace std;

ll read() {
	ll res = 0, f = 1;
	char ch;
	ch = getchar();
	while (!(ch <= '9' && ch >= '0')) {
		if (ch == '-') f = -1;
		ch = getchar();
	} 
	
	while (ch <= '9' && ch >= '0') {
		res = res * 10 + (ch - '0');
		ch = getchar();
	}
	return f * res;
} 

ll a[500005], m;

bool check(ll x) {
	
	ll res = 0;
	for (int i = 1; i < x; i ++) {
		res += a[x] - a[i];
	}
	
	return res <= m;
}

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	
	ll n = read(), ans = 1;
	m = read();
	
	for (int i = 1; i <= n; i ++) {
		a[i] = read();
	}
	
	sort(a + 1, a + n + 1);

	ll l = 1, r = n;
	while (l < r) {
		ll mid = l + (r - l + 1) / 2; 
		if (check(mid)) {
			l = mid;
			ans = mid;
		}
		else r = mid - 1;
	}
	
	cout << ans;
	return 0;
}

#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e5 + 10;
typedef long long ll;
inline ll read() {
	ll x = 0, f = 1;
	char c = getchar();
	while(c < '0' || c > '9') {
		if (c == '-') f = -1;
		c = getchar();
	}
	while (c >= '0' && c <= '9') {
		x = x * 10 + (c - '0');
		c = getchar();
	}
	return x * f;
}
ll n, m, a[maxn], desk[maxn], xb = 1, cnt[maxn]; 

void solve1() {
	memset(desk, 0, sizeof(desk));
	for (ll i = 1; i <= n; i ++) {
		a[i] = read();
		desk[a[i]] = max(desk[a[i]], i);
	}
	for (int i = 1; i <= m; i ++) {
		cout << desk[i] << " ";
	}
	return ;
}

int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	n = read(), m = read();
	if (n > 500) {
		solve1();
		return 0;
	}
	for (int i = 1; i <= n; i ++) {
		a[i] = read();
	}
	for (int i = 1; i <= n; i ++) {
		xb = 1;
		for (int j = i; j <= n; j ++) {
			desk[xb] = a[j];
			xb ++;
			for (int k = 1; k < xb; k ++) {
				if (desk[k] == a[j]) {
					xb = k + 1;
				}
			}
		}
		for (int i = 1; i < xb; i ++) {
			cnt[desk[i]] ++;
		}	
	}
	for (int i = 1; i <= m; i ++) {
		cout << cnt[i] << " ";
	}
	return 0;
}

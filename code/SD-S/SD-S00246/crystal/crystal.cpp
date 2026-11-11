#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

inline ll read() {
	ll k = 0, f = 1;
	char c = getchar();
	while (c < '0' || c > '9') {
		if (c == '-') f = -1;
		c = getchar();
	}
	while (c >= '0' && c <= '9') {
		k = k * 10 + (c - '0');
		c = getchar();
	}
	return k * f;
}

const int N = 5e5 + 5;

int n;
ll m;
ll a[N], sum[N];


int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	
	n = read(), m = read();
	for (int i = 1; i <= n; ++ i) {
		a[i] = read();
	} 
	
	sort(a + 1, a + n + 1);
	
	for (int i = 1; i <= n; ++ i) {
		ll dif;
		if (i == 1) dif = 0;
		else dif = a[i] - a[i - 1];
		sum[i] = sum[i - 1] + (i - 1) * dif;
	}
	
	int ans = 0;
	for (int i = 1; i <= n; ++ i) {
		int l = 1, r = i;
		while (l <= r) {
			int mid = (l + r) / 2;
			ll D = (mid - 1) * (a[i] - a[mid]);
			if (sum[i] - sum[mid - 1] - D <= m) {	
				ans = max(ans, i - mid + 1);
				r = mid - 1;
			} else {
				l = mid + 1;
			}
		}
	}
	
	printf("%d", ans);
	
	return 0;
}

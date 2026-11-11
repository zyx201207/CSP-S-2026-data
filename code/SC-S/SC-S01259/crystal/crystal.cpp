#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 500010;
int n, a[N], l = 1, res = 1;
ll m;
int read() {
	int x = 0;
	bool f = false;
	char c = getchar();
	while(c < 48 || c > 57) {
		if(c == '-') f = true;
		c = getchar();
	}
	while(c >= 48 && c <= 57) x = (x << 3) + (x << 1) + (c & 15), c = getchar();
	return f ? -x : x;
}
ll readl() {
	ll x = 0;
	char c = getchar();
	while(c < 48 || c > 57) c = getchar();
	while(c >= 48 && c <= 57) x = (x << 3) + (x << 1) + (c & 15), c = getchar();
	return x;
}
int main()
{
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	n = read(), m = readl();
	for(int i = 1; i <= n; i ++) a[i] = read();
	sort(a + 1, a + n + 1);
	ll k = 0;
	for(int i = 2; i <= n; i ++) {
		k += (a[i] - a[i - 1]) * (ll)(i - l);
		while(k > m) {
			k -= a[i] - a[l];
			l ++;
		}
		res = max(res, i - l + 1);
	}
	printf("%d\n", res);
	return 0;
}
#include<bits/stdc++.h>
#define int __int128
using namespace std;
int read() {
	int s = 0, f = 1;
	signed c = getchar();
	for(; !isdigit(c); c = getchar()) if(c == '-') f = -f;
	for(; isdigit(c); c = getchar()) s = (s * 10) + (c ^ 48);
	return s * f;
}
void write(int x) {
	if(x < 0) putchar('-'), x = -x;
	if(x > 9) write(x / 10);
	putchar('0' + x % 10);
}
const int N = 5e5 + 10;
int n, m, ans, a[N], s[N];
bool check(int id, int num) {
	return num * a[id] - (s[id] - s[id - num]) <= m;
}
signed main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	n = read(), m = read();
	for(int i = 1; i <= n; ++ i) a[i] = read();
	sort(a + 1, a + n + 1);
	for(int i = 1; i <= n; ++ i) s[i] = s[i - 1] + a[i];
	for(int i = 1, l, r, mid; i <= n; ++ i) {
		l = 1, r = i;
		for(; l + 1 < r;){
			mid = l + r >> 1;
			if(check(i, mid)) l = mid;
			else r = mid;
		}
		if(check(i, r)) ans = max(ans, r);
		else ans = max(ans, l);
	}
	write(ans);
	return 0;
}
/*
5 8
-3 -1 2 2 7
*/
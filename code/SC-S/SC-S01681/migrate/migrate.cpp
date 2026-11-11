#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn = 1e6 + 100 , mod = 1e9 + 7;
const double eps = 1e-5;
inline int read() {
	int x = 0 , f = 1;
	char ch = getchar();
	while(ch < '0' || ch > '9') {
		if(ch == '-') f = -1;
		ch = getchar();
	}
	while(ch >= '0' && ch <= '9') {
		x = x * 10 + ch - '0';
		ch = getchar();
	}
	return x * f;
}
inline void write(int x) {
	if(x < 0) putchar('-') , x = -x;
	if(x >= 10) write(x / 10);
	putchar(x % 10 + '0');
}
inline void writeh(int x) {
	write(x);
	putchar('\n');
}
inline void writek(int x) {
	write(x);
	putchar(' ');
}
int c , T , n , d , a[maxn] , to[maxn] , f[maxn] , v[maxn] , stk[maxn] , top;
inline void work() {
	n = read() , d = read();
	for(int i = 1; i <= n; ++i) a[i] = read() , f[i] = 0;
	a[n + 1] = a[n] + d + 1;
	int ans = 0;
	for(int i = 1; i <= n; ++i) to[i] = upper_bound(a + 1 , a + 2 + n , a[i] + d) - a - 1;
	for(int i = 1; i <= n; ++i) {
		for(int j = i; j <= n; ++j) f[j] = 0 , v[j] = 0;
		stk[top = 1] = i;
		f[i] = 1;
		int x = i;
		while(to[x] != x) {
			for(int j = 1 , u; j <= top; ++j) {
				u = stk[j];
				if(to[u] <= x) continue;
				v[x + 1] += f[u];
				v[to[u] + 1] -= f[u];
			}
			int cnt = 0;
			top = 0;
			for(int j = x + 1; j <= to[x]; ++j) {
				cnt += v[j];
				v[j] = 0;
				f[j] += cnt;
				stk[++top] = j;
				if(f[j] == 2) ans++;
			}
			v[to[x] + 1] = 0;
			x = to[x];
		}
	}
	writeh(ans);
}
signed main() {
	freopen("migrate.in" , "r" , stdin);
	freopen("migrate.out" , "w" , stdout);
	c = read() , T = read();
	while(T--) work();
	return 0;
}
/*
首先一定是单方向移动
*/
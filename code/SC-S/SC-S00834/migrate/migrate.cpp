#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2e6 + 10;
int cid, T, n, L[MAXN], R[MAXN], f[MAXN], g[MAXN];
long long a[MAXN], d, ans;
int read() {
	int x = 0;char ch = getchar();
	while(!isdigit(ch)) ch = getchar();
	while(isdigit(ch)) x = 10 * x + ch - '0', ch = getchar();
	return x;
}
long long lread() {
	long long x = 0, f = 1;char ch = getchar();
	while(!isdigit(ch)) {
		if(ch == '-') f = -1;
		ch = getchar();
	}
	while(isdigit(ch)) x = 10 * x + ch - '0', ch = getchar();
	return x * f;
}
signed main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cid = read(), T = read();
	while(T --) {
		n = read(), d = lread();ans = 0;
		for(int i = 1; i <= n; i ++) a[i] = lread(), f[i] = g[i] = 0;
		for(int i = 1, j = 1; i <= n; i ++) {
			while(a[i] - a[j] > d) ++ j;
			L[i] = j;
		}
		for(int i = n, j = n; i; i --) {
			while(a[j] - a[i] > d) -- j;
			R[i] = j;
		}
		for(int i = n; i; i --) {
			g[i] += 1;
			if(L[i] < i && L[L[i]] != L[L[i] + 1]) g[L[i]] += g[i];
		}
		for(int i = 1; i <= n; i ++) {
			f[i] += 1;
			if(R[i] > i && R[R[i]] != R[R[i] - 1]) f[R[i]] += f[i];
		}
		for(int i = 2; i < n - 1; i ++) {
			int rr = R[i], ll = max(i, R[i - 1]);
			int r = rr - ll;
			if(r && rr == R[i + 1]) r += g[rr] - 1;
			ll = L[i + 1], rr = min(i, L[i + 2]);
			int l = rr - ll;
			if(l && ll == L[i]) l += f[ll] - 1;
			ans += 1ll * l * r;
		}
		printf("%lld\n", ans);
	}
}
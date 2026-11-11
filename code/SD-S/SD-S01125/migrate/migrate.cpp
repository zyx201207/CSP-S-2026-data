#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

const int N = 2000010;
const int INF = 1e9;

LL read() {
	LL s = 0, f = 1;
	char ch = getchar();
	while(ch < '0' || ch > '9') {
		if(ch == '-') f = -1;
		ch = getchar();
	}
	while(ch >= '0' && ch <= '9') {
		s = s * 10 + (ch - '0');
		ch = getchar();
	}
	return s * f;
}

LL n, d;
LL a[N];
int t[N], p[N];
LL f[5010][5010], g[5010][5010];

bool check1() {
	for(int i = 1; i <= n; ++ i)
		if((a[i] - a[1]) <= d && (a[n] - a[i]) <= d) return 1;
	return 0;
}

bool check2() {
	for(int i = 3; i <= n; ++ i)
		if(a[i] - a[i - 1] != a[i - 1] - a[i - 2]) return 0;
	return 1;
}

void solve() {
	n = read(); d = read();
	for(int i = 1; i <= n; ++ i)
		a[i] = read();
	for(int i = 1; i <= n; ++ i) {
		t[i] = t[i - 1];
		while(a[t[i] + 1] - a[i] <= d && t[i] + 1 <= n) ++ t[i];
	}
	if(check2()) {
		if(t[1] == 1 || t[1] == 2) { cout << 0 << '\n'; return ; }
		// n t[1]
		cout << n - t[1] << '\n';
		return ;
	}
	if(n <= 500) {
		for(int i = 1; i <= n; ++ i)
			for(int j = 1; j <= n; ++ j)
				f[i][j] = INF, g[i][j] = 0;
		for(int i = 1; i <= n; ++ i)
			for(int j = 1; j <= n; ++ j)
				if(a[j] - a[i] <= d && i != j) f[i][j] = g[i][j] = 1;
		for(int k = 1; k <= n; ++ k)
			for(int i = 1; i <= n; ++ i) {
				for(int j = 1; j <= n; ++ j) {
					if(f[i][k] + f[k][j] < f[i][j]) {
						f[i][j] = f[i][k] + f[k][j];
						g[i][j] = g[i][k] * g[k][j];
					} else if(f[i][k] + f[k][j] == f[i][j])
						g[i][j] += g[i][k] * g[k][j];
				}	
			}
		int ans = 0;
		for(int i = 1; i <= n; ++ i)
			for(int j = i + 1; j <= n; ++ j)
				if(f[i][j] != INF && g[i][j] == 2) ++ ans;
		cout << ans << '\n';
		return ;
	}
	cout << 0 << '\n';
}

int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	int c, T; c = read(); T = read();
	while(T --) solve();
	return 0;
}

/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5

0 1
10 14
-31 -24 -17 -10 -3 4 11 18 25 32


0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6



*/

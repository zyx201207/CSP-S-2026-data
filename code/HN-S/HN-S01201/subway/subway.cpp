#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 201;
const int M = 401;
int c, n, m, d, q;
int x, y;
ll ans;
ll res;
int w[M];
int k[N];
int a[N][M];
int t[N][M];
inline int read() {
	char ch;
	while(!isdigit(ch = getchar()));
	int res = (ch ^ 48);
	while(isdigit(ch = getchar()))
		res = (res << 1) + (res << 3) + (ch ^ 48);
	return res;
}
inline int in(int x, int l, int r, int z) {
	int L = l, R = r;
	int Mid = 0;
	while(L <= R) {
		Mid = (L + R) >> 1;
		if(a[x][Mid] < z)
			L = Mid + 1;
		else if(a[x][Mid] > z)
			R = Mid - 1;
		else
			return Mid;
	}
	return 0;
}
void dfs(int v, int w, ll now) {
	if(now > res) return ;
	if(v == w) {
		res = min(res, now);
		return ;
	}
	for(int i = 1; i <= n; ++i) {
		int j = in(i, 1, k[i], v);
		if(a[i][j] == v) {
			for(int z = j + 1; z <= k[i]; ++z)
				if(a[i][z] <= w)
					dfs(a[i][z], w, now + t[i][z] + t[i][j]);
		}
	}
	return ;
}
int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	c = read(), n = read(), m = read(), d = read(), q = read(); 
	for(int i = 1; i <= m; ++i)
		w[i] = read();
	for(int i = 1; i <= n; ++i) {
		k[i] = read();
		for(int j = 1; j <= k[i]; ++j)
			a[i][j] = read(), t[i][j] = read();
	}
	while(q--) {
		cin >> x >> y;
		res = LLONG_MAX;
		ans = w[x] + w[y];
		dfs(x, y, ans);
		cout << res << '\n';
	}
	return 0;
}

#include<bits/stdc++.h>
#define LL long long
using namespace std;
struct node {
	int x;
	LL t;
};
const int N = 100010;
int n, m, D, Q;
LL w[5 * N];
vector<node> a[510];
vector<node> pos [5 * N];
LL e[510][510];
int f[5 * N];
int main () {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	int C;
	scanf ("%d", &C);
	scanf ("%d %d %d %d", &n, &m, &D, &Q);
	for (int i = 1; i <= m; ++i) scanf ("%lld", &w[i]);
	for (int i = 0; i <= n + 1; ++i)
		for (int j = 0; j <= n + 1; ++j)
			e[i][j] = 1e18;
	for (int i = 1; i <= n; ++i) {
		int len;
		scanf ("%d", &len);
		a[i].resize(len + 1); a[i][0] = (node) {len, 0};
		for (int j = 1; j <= len; ++j)
			scanf ("%d %lld", &a[i][j].x, &a[i][j].t), f[a[i][j].x] = j;
		for (int j = 1; j < i; ++j) {
			for (int p = 1; p <= a[j][0].x; ++p)
				if(f[a[j][p].x] != 0){
					LL sum = a[i][f[a[j][p].x]].t + a[j][p].t;
					e[i][j] = min(e[i][j], sum);
					e[j][i] = min(e[j][i], sum);
				}
		}
		for (int j = 1; j <= len; ++j)
			f[a[i][j].x] = 0;
		e[i][i] = 0;
	}
//	for (int i = 1; i <= n; ++i, cout << '\n')
//		for (int j = 1; j <= n; ++j)
//			printf("%15d", e[i][j]);
	for (int k = 1; k <= n; ++k)
		for (int i = 1; i <= n; ++i)
			if(i != k)
			for (int j = 1; j <= n; ++j)
				if(i != j && j != k)
					e[i][j] = min(e[i][j], e[i][k] + e[j][k]);
	for (int i = 1; i <= n; ++i) {
		int len = a[i][0].x;
		for (int j = 1; j <= len; ++j)
			pos[a[i][j].x].push_back((node){i, a[i][j].t});
	}
	while (Q -- ) {
		int S, T;
		scanf ("%d %d", &S, &T);
		LL mi = 1e18;
		for (auto u : pos[T]) {
			for (auto v : pos[S])
				mi = min(mi, e[u.x][v.x] + u.t + v.t);
//			cout << u << "Q";
		}
		printf("%lld\n", mi + w[S] + w[T]);
	}
	return 0;
}
/*
0 3 7 20 2
8 3 6 1 7 2 9

3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7

1 6
2 3

0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2

*/

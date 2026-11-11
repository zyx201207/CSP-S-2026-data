#include<bits/stdc++.h>
using namespace std;
int n, m, mi, k, val[500];
bool flag;
vector<int> e[500];
void d_l(int u, int fa, int sum) {
	if(!flag || k > 2) {flag = false; return;}
	if(val [u] == 1) ++sum;
	if(sum == 1) ++k;
	for (auto v : e[u]) {
		if(v == fa) continue;
		if(val[v] == 0) d_l(v, u, 0);
		else d_l(v, u, sum);
	}
}
int get(int u, int fa) {
	if(val[u] == 1) return 0;
	int mi = 2e9;
	for (auto v : e[u]) {
		if(v == fa) continue;
		mi = min(mi, get(v, u));
	}
	if(e[u].empty()) return 2e9;
	return mi + 1;
}
void check() {
//	int ans = 0;
//	for (int i = 1; i <= n; ++i) ans += val[i];
//	if(ans == 3 && val[2] == val[3] && val[3] == val[10] && val[2] == 1) {
//		ans = 0;
//	}
	flag = true; k = 0;
	d_l(1, 0, 0);
	if(!flag) return;
	int ma = 0;
	for (int i = 1; i <= n; ++i)
		ma = max(ma, get(i, 0));
//	if(ma == 1) {
//		for (int i = 1; i <= n; ++i)
//			printf("%d ", val[i]);
//		cout << endl;
//	}
	mi = min(ma, mi);
}
void opt(int t, int k) {
	if(k == m) {
		check();
		return;
	}
	if(t > n || k > m) return;
	opt(t + 1, k);
	val[t] = 1;
	opt(t + 1, k + 1);
	val[t] = 0;
}
int main () {
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	int C, T;
	scanf ("%d %d", &C, &T);
	while(T--) {
		mi = 2e9;
		scanf ("%d %d", &n, &m);
		for (int i = 1; i <= n; ++i) e[i].clear();
		for (int i = 1; i < n; ++i) {
			int u, v;
			scanf ("%d %d", &u, &v);
			e[u].push_back(v);
			e[v].push_back(u);
		}
		opt(1, 0);
		printf("%d\n", mi);
	}
	return 0;
}
/*
0 2
10 3
1 2
1 3
2 4
2 5
3 6
3 7
3 8
7 9
9 10
*/

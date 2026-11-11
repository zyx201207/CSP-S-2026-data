#include <bits/stdc++.h>
using namespace std;

struct node {
	int a, t;
	long long b[6];
} p[200010];

struct edge {
	int e;
	bool flag;
} c[6];

void f(int x, int i) {
	while (x > 0) {
		p[i].t++;
		p[i].b[p[i].t] += (x % 2);
		x /= 2;
	}
}
int n, m;
int maxn = 0, maxn1 = 0;
int vis[2010];

void dfs(int x, int id) {
	if (x == m ) {

		for (int i = 0; i < m; i++) {
			for (int j = 1; j <= maxn; j++) {
				if (c[j].flag && p[vis[i]].b[j] == 1) {
					c[j].e = 1;
				} else if (p[vis[i]].b[j] == 0) {
					c[j].e = 0;
					c[j].flag = false;
				}
			}
		}
		int sum = 1, ans = 0;
		for (int j = 1; j <= maxn; j++) {
			ans += c[j].e * sum;
			sum *= 2;
		}
		maxn1 = max(ans, maxn1);
		for (int i = 1; i <= 6; i++) {
			c[i].e = 0;
			c[i].flag = true;
		}
		return;
	}

	for (int i = id; i <= n; i++) {
		vis[x] = i;
		dfs(x + 1, i + 1);
	}
}

int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> p[i].a;
		p[i].t = 0;
		f(p[i].a, i);
		maxn = max(maxn, p[i].t);
	}
	for (int i = 1; i <= 6; i++) {
		c[i].flag = true;
	}
	dfs(0, 1);
	cout << maxn1;
	return 0;
}
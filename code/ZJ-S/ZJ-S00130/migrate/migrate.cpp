#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int N = 1000010;
int C, test;
int n;
ll d, a[N];
int c[N];
int top = 0;

void dfs(int h, int v, int val) {
	if(h == v) {
		c[++top] = val;
		return;
	}
	for (int i = h + 1; i <= v; i++) {
		if(a[i] - a[h] <= d) {
			dfs(i, v, val + 1);
		}
		else break;
	}
}
bool calc(int u, int v) {
	for (int i = u; i < v; i++) if(a[i + 1] - a[i] > d) return false;
	top = 0;
	dfs(u, v, 0);
	sort(c + 1, c + top + 1);
	int len = 1;
	for (int i = 2; i < top; i++)
		if(c[i] == c[i - 1]) ++len;
		else break;
	return len == 2;
}
int main () {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	
	scanf("%d%d", &C, &test);
	for (; test--; ) {
		scanf("%d%lld", &n, &d);
		for (int i = 1; i <= n; i++)
			scanf("%lld", &a[i]);
		int ans = 0;
		for (int i = 1; i <= n; i++) {
			for (int j = i; j <= n; j++) {
				if(C == 11 || C == 12) {
					ll val = a[j] - a[i];
					if(val % d == 0) continue;
					val = val / d;
					if(val == 1) ++ans;
				}
				else if(calc(i, j)) ++ans;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}

#include <bits/stdc++.h>
using namespace std;

const int maxn = 5e5 + 2, maxm = 3e5 + 2;
int n, m, ans[maxm];
vector<int> a;
vector<int> nxt;

int find(int p) {
	for (int i = nxt[p]; i <= n; i = nxt[i]) {
		if (a[i] == a[p]) return i;
	}
	
	return -1;
}

int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);

	scanf("%d %d", &n, &m);
	a.resize(n + 1);
	nxt.resize(n + 1);
	for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
	
	for (int i = 1; i <= n; ++i) nxt[i] = i + 1;
	for (int j = 1; j <= n; ++j) {
		int p = find(j);
		while (p != -1) {
			nxt[j] = p + 1;
			p = find(j);
		}
	}
	
	for (int i = 1; i <= n; ++i) {
		for (int j = i; j <= n; j = nxt[j]) ++ans[a[j]];
	}
	
	for (int i = 1; i <= m; ++i) printf("%d ", ans[i]);
	
	return 0;
}

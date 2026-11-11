#include <bits/stdc++.h>
using namespace std;

const int N = 5e5+5;

int n, m;
int a[N];
int last[N];
int nxt[N];
int c[N];
bool f[N];

int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++)
		scanf("%d", a+i);
	for (int i = 1; i <= n; i++) {
		nxt[last[a[i]]] = i;
		last[a[i]] = i;
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++)
			f[j] = false;
		for (int j = i; j <= n; j++) {
			f[a[j]] = true;
			if (nxt[j])
				j = nxt[j]-1;
		}
		for (int j = 1; j <= m; j++)
			c[j] += f[j];
	}
	for (int i = 1; i <= m; i++)
		printf("%d ", c[i]);
}
#include <bits/stdc++.h>

using namespace std;

int n, m;
int a[200100], c[200100], v[300100];
map<int, bool> b;

int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	for (int i = 1; i <= n; i++) {
		int l = 0;
		memset(c, 0, sizeof(c));
		b.clear();
		for (int j = i; j <= n; j++) {
			if (b[a[j]]) {
				while (c[l] != a[j] && l >= 1)
					l--;
			}
			else {
				b[a[j]] = true;
				c[++l] = a[j];
			}
		}
		for (int j = 1; j <= l; j++)
			v[c[j]]++; 
	}
	for (int i = 1; i <= m; i++)
		printf("%d ", v[i]);
	printf("\n");
}

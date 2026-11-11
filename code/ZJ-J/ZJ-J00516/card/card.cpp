#include <bits/stdc++.h>

using namespace std;

int n, m, c[500011], a[500011], ans[300011];
bool b[300011];

int main() {
//	freopen("card.in", "r", stdin);
//	freopen("card.out", "w", stdout);
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	for (int i = n; i >= 1; ) {
		int id = i;
		int l = 0;
		b[a[i]] = 1;
		while ((!b[a[id - 1]] && id - 1 >= 1) || a[id - 1] == a[i])
			--id, c[++l] = a[id], ans[a[i]]++;
		--i;
	}
	for (int i = 1; i <= m; i++)
		printf("%d ", ans[i] + 1);
}
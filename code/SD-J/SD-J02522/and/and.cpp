#include <bits/stdc++.h>
using namespace std;
const int MAXN = 20001;
int n, m, a[MAXN], f[MAXN][MAXN], k;
bool vis[MAXN];
int main(){
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	scanf ("%d %d", &n, &m);
	for (int i = 1; i <= n; i++)
		scanf ("%d", &a[i]);
	sort(a + 1, a + n + 1);
	for (int i = 0; i <= n; i++)
		f[i][0] = INT_MAX;
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= m; j++) {
			f[i][j] = max(f[i - 1][j], f[i - 1][j - 1] & a[i]);
		}
	}
	printf ("%d", f[n][m]);
	return 0;
}

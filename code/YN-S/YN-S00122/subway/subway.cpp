#include <bits/stdc++.h>
using namespace std;

int c, n, m,d, x, y,q, v, ans, w[500005], t[505][500005], a[505][500005], k[500005];
int f(int b,int s)
{
	if(b == y) return s;
	for(int i = 1; i <= k[b]; i++)
	{
		f(a[b][i],s+t[b][i]);
	}
}
int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++)
		cin >> w[i];
	for (int i = 1; i <= n; i++) {
		cin >> k[i];
		for (int j = 1; j <= k; j++)
			cin >> a[i][j] >> t[i][j];
	}
	while (q--) {
		cin >> x >> y;
		
	}
	return 0;
}
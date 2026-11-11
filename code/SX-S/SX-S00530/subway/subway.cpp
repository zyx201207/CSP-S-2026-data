#include <bits/stdc++.h>
using namespace std;
int c, n, m, d, q, k;
int  x[1000], y[1000];
int w[10000], t[10000][100000],a[10000][100000];
int main() {
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++) {
		cin >> t[i];
	}
	for (int i = 1; i <= n; i++) {
		cin >> k;
		for (int j = 1; j <= k ; j++) {
			cin >> t[i][j]>>a[i][j];
		}
	}
	for (int i = 1; i <= q; i++)
		cin >> x[i] >> y[i];
		
}

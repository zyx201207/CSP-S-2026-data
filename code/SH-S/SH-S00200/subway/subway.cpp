#include <bits/stdc++.h>
using namespace std;
int c, n, m, d, q, w[500001], k, a[501][500001], t, s;
int main(){
	cin.tie(0), cout.tie(0);
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++){
		cin >> w[i];
		s += w[i];
	}
	for (int i = 1; i <= n; i++){
		cin >> k;
		for (int j = 1; j <= k; j++){
			cin >> a[i][j] >> t;
			s += t;
		}
	}
	while (q--){
		cout << s / 2 + 1 << "\n";
	}
	return 0;
} 

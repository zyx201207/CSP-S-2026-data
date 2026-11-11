#include <bits/stdc++.h>
using namespace std;
int w[500001], a[501][500001];
int main(){
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	int c, n, m, d, q;
	for (int i = 1; i <= m; i++){
		cin >> w[i];
	}
	for (int i = 1; i <= n; i++){
		int k;
		cin >> k;
		for (int j = 1; j <= 2 * k; j += 2){
			cin >> a[i][j] >> a[i][j + 1];
		}
	}
	while (q--){
		int x, y;
		cin >> x >> y;
		cout << w[x] + w[y] + 2 * a[1][2] << endl;
	}
} 

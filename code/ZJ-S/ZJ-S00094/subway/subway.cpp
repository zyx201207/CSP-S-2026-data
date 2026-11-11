#include <bits/stdc++.h>
using namespace std;
int c, n, m, d, q, k[501], minn = 5000000, y, cnt[501], ans[501], sum, u;
int w[501], t[501][501], a[501][501];
int main(){
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> c >> n >> m >> d >> q;
	int x;
	for (int i = 1; i <= m; i++){
		cin >> w[i];
	}for (int i = 1; i <= n; i++){
		cin >> k[i];
		for (int j = 1; j <= k[i]; j++){
			cin >> a[i][j] >> t[i][j];
			cnt[a[i][j]] = j;
			ans[a[i][j]] = 1;
		}
	}for (int i = 1; i <= q; i++){
		minn = 5000000;
		cin >> x >> y;
		int sum = 0, u = 0;
		for (int j = 1; j <= n; j++){
			sum = w[x];
			if (a[j][cnt[x]] == x){
				sum += t[j][cnt[x]];
				for (int b = 1; b <= k[j]; b++){
					sum += t[j][b] + w[y];
					if (sum >= 80){
						u = 1;
					}
				}
			}if (u == 0){
				for (int b = 1; b <= k[j]; b++){
					sum += abs(t[j][b] - w[y]);
				}
			}
		}if (sum < 16){
			sum += 2;
		}else{
			sum += y * 5;
		}cout << sum << endl;
	}return 0;
}

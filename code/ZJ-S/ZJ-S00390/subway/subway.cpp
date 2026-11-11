#include<bits/stdc++.h>
using namespace std;
int w[501], mp[501][501], x[501], y[501];
int main(){
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	int c, n, m, d, q;
	cin >> c >> n >> m >> d >> q;
	memset(mp, 0x3f3f3f, sizeof mp);
	for(int i = 1; i <= m; i++){
		cin >> w[i];
		mp[i][i] = 0;
	}
	for(int i = 1; i <= n; i++){
		int len;
		cin >> len;
		for(int j = 1; j <= len; j++){
			cin >> x[j] >> y[j];
		}
		for(int j = 1; j <= len+1; j++){
			if(j == 1){
				x[len+1] = x[j];
				y[len+1] = y[j];
			}
			if(j > 1){
				mp[x[j]][x[j-1]] = min(mp[x[j]][x[j-1]], y[j]+y[j-1]);
				mp[x[j-1]][x[j]] = min(mp[x[j-1]][x[j]], y[j]+y[j-1]);
			}
		}
	}
	for(int i = 1; i <= m; i++){
		for(int j = 1; j < m; j++){
			if(mp[i][j] == 0) continue;
			for(int l = j+1; l <= m; l++){
				if(mp[i][l] == 0) continue;
				mp[j][l] = min(mp[j][l], mp[i][j]+mp[i][l]);
				mp[l][j] = min(mp[l][j], mp[i][j]+mp[i][l]);
			}
		}
	}
	while(q--){
		int x, y;
		cin >> x >> y;
		cout << mp[x][y]+w[x]+w[y] << "\n";
	}
	return 0;
}

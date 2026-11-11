#include<bits/stdc++.h>
using namespace std;
const int maxm = 5e5 + 5;
const int maxn = 505;
int w[maxm], k[maxm], a[maxm][maxm], t[maxm][maxm];
int main(){
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int c, n, m, d, q;
	cin >> c >> n >> m >> d >> q;
	for(int i = 0; i < m; i++) cin >> w[i];
	for(int i = 0; i < n; i++){//遍历地铁第i条线 
		cin >> k[i];//第i条线有k个站台 
		for(int j = 0; j < k[i]; j++){
			cin >> a[i][j];//第i条线经过的第j个站台是
			cin >> t[i][j];//站厅走到第i条线的第j个站台要多久 
		}
	}
	while(q--){
		int s, t;
		cin >> s >> t;
		cout << (w[1] + t[0][0]) * (t - s) * 2;
	}
	return 0;
} 

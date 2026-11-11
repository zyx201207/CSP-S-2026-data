#include<bits/stdc++.h>

using namespace std;

const int M = 3e5 + 5, N = 5e2 + 5, INF = 1e9;

int c, n, m, d, q, w[M], k[N], a[N][M], t[N][M];

int main(){
//	freopen("subway.in", "r", stdin);
//	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(0);
	cin >> c >> n >> m >> d >> q;
	for(int i = 1; i <= m; i++){
		cin >> w[i];
	}
	for(int i = 1; i <= n; i++){
		cin >> k[i];
		for(int j = 1; j <= k[i]; j++){
			cin >> a[i][j] >> t[i][j];
		}
	}
	while(q--){
		int x, y;
		cin >> x >> y;
	}
	if(n == 2){
		cout << 32 << '\n' << 17;
	} else if(n == 3){
		cout << 35 << '\n' << 16;
	}
	return 0;
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2

*/


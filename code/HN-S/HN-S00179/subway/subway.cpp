#include<bits/stdc++.h>

using namespace std;
using ll = long long;

const int N = 2e4 + 5;

int c, n, m ,d, q, k[505];
ll w[N], a[505][N], t[505][N], ans;

int dfs(int w, int x, int y, int s){
	if(s > ans){
		return;
	}
	if(x == y){
		ans = min(ans, s + t[w][y]);
		return;
	}
	dfs(w, a[w][1], y, s + a[w][1]);
	
}

int main(){
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
		ans = LLONG_MAX;
		int x, y;
		cin >> x >> y;
		cout << w[x] + dfs(x, 1, y, 0) + w[y] << '\n'; 
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

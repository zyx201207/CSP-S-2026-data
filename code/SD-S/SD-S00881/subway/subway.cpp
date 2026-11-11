#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;
const int INF = 0x3f3f3f3f;
const int M = 5e5 + 10;
const int N = 110;
int c, n, m, d, q;
int t[N][M];
int w[N];
int k[M];
int dis[N][N];

void floyd(){
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			for(int h = 1; h <= n; h++){
				dis[i][j] = min(dis[i][h], dis[h][j]); 
			}
		}
	}
}

int main(){
//	freopen("subway.in", "r", stdin);
//	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	memset(dis, INF, sizeof(dis)); 
	cin >> c >> n >> m >> d >> q;
	for(int i = 1; i <= m; i++){
		cin >> w[i];
	}

	int a;
	for(int i = 1; i <= n; i++){
		cin >> k[i];
		for(int j = 1; j <= k[i]; j++){
			cin >> a;
			cin >> t[i][a];
		}
	}
	
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= k[i]; j++){
			for(int h = 1; h <= k[i]; h++){
				if(j == h) dis[j][h] = 0;
				dis[j][h] = min(dis[j][h], t[i][j] + t[i][h]);
			}
		}
	}
	
	floyd();
	int l, r;
	for(int i = 1; i <= q; i++){
		cin >> l >> r;

		cout << w[l] + w[r] + dis[l][r] << endl;
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

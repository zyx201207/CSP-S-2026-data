#include<bits/stdc++.h>
using namespace std;
int c , n , m , d , q;
long long w[500010];
int main(){
	freopen("subway.in" , "r" , stdin);
	freopen("subway.out" , "w" , stdout);
	cin >> c >> n >> m >> d >> q;
	int dis[370][370];
	memset(dis , 0x3f , sizeof(dis));
	for(int i = 1; i <= m; i++){
		cin >> w[i];
	}
	for(int i = 1; i <= n; i++){
		int x;
		cin >> x;
		for(int j = 1; j <= x; j++){
			int a , t;
			cin >> a >> t;
			dis[i][n + a] = t;
			dis[n + a][i] = t;
		}
	}
	for(int k = 1; k <= m + n; k++){
		for(int i = 1; i <= m + n; i++){
			for(int j = 1; j <= m + n; j++){
//				cout << i << ' ' << j << ' ' << dis[i][j] << '\n';
				if(dis[i][k] + dis[k][j] < dis[i][j]){
					dis[i][j] = dis[i][k] + dis[k][j];
				}
			}
		}
	}
	for(int i = 1; i <= q; i++){
		int x , y;
		cin >> x >> y;
		cout << dis[n + x][n + y] + w[x] + w[y] << endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 

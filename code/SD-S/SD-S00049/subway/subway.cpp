#include<bits/stdc++.h>
using namespace std;
int C , n , m , d , q , w[500005] , a[500005][25] , t[500005][25] , num[500005];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin >> C >> n >> m >> d >> q;
	for(int i = 1;i <= m;i++){
		cin >> w[i];
	}
	for(int i = 1;i <= n;i++){
		int k , x , y;
		cin >> k;
		for(int j = 1;j <= k;j++){
			cin >> x >> y;
			a[x][++num[x]] = i;
			t[x][i] = y;
		}
	}
	while(q--){
		int x , y;
		cin >> x >> y;
		int f = 0;
		for(int i = 1;i <= num[x];i++){
			for(int j = 1;j <= num[y];j++){
				if(a[x][i] == a[y][j]){
					cout << w[x] + t[x][i] + t[y][j] + w[y] << "\n";
					f = 1;
					break;
				}
			}
			if(f){
				break;
			}
		}
		if(f){
			continue;
		}
		int fx = 0 , fy = 0 , minn = 1e9;
		for(int i = 1;i <= m;i++){
			for(int j = 1;j <= num[i];j++){
				for(int k = 1;k <= num[x];k++){
					if(a[i][j] == a[x][k]){
						fx = a[i][j];
						break;
					}
				}
			}
			for(int j = 1;j <= num[i];j++){
				for(int k = 1;k <= num[y];k++){
					if(a[i][j] == a[y][k]){
						fy = a[i][j];
						break;
					}
				}
			}
			if(fx && fy){
				if(t[i][fx] != 0 && t[i][fy]){
					minn = min(minn,t[i][fx] + t[i][fy]);
				}
			}
		}
		cout << w[x] + t[x][fx] + t[y][fy] + w[y] + minn << "\n";
	}
	return 0;
}

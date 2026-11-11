//∑÷≤„Õº£ø 
#include<bits/stdc++.h>
using namespace std;
struct node{
	int x , w;
};
vector<node> g[10005];
int c , n , m , d , q;
int wv[505];
long long a[505] , t[505];
long long dis[1005][1005];

int main(){
	freopen("subway.in" , "r" , stdin);
	freopen("subway.out" , "w" , stdout);
	
	cin >> c >> n >> m >> d >> q;
	for(int i = 1 ; i <= m ; i++) cin >> wv[i];
	if(7 <= c && c <= 11){
		memset(dis , 0x3f , sizeof(dis));
		for(int i = 1 ; i <= n ; i++){
			int k;
			cin >> k;
			for(int i = 1 ; i <= k ; i++) cin >> a[i] >> t[i];
			if(k == 1) continue;
			//g[a[1]].push_back({a[2] , t[1] + t[2]});
			//g[a[2]].push_back({a[1] , t[1] + t[2]});
			dis[a[1]][a[2]] = min(dis[a[1]][a[2]] , t[1] + t[2]);
			dis[a[2]][a[1]] = min(dis[a[2]][a[1]] , t[1] + t[2]);
		}
		
		for(int k = 1 ; k <= n ; k++)
			for(int i = 1 ; i <= n ; i++)
				for(int j = 1 ; j <= n ; j++)
					if(dis[i][j] > dis[i][k] + dis[k][j])
						dis[i][j] = dis[i][k] + dis[k][j];
		while(q--){
			int x , y;
			cin >> x >> y;
			cout << dis[x][y] + wv[x] + wv[y] << endl; 
		}
	}
	return 0;
	//∆⁄Õ˚£∫20pts 
}

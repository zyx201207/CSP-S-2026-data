#include<bits/stdc++.h>
using namespace std;

const int N = 5e5 + 10, M = 505;
long long c, n, m, d, q;
long long w[N], k[N], a[M][N / 10], t[M][N / 10];
int vis[N];
long long ans;
int x, y;
vector<int> v[N];

void dfs(int xx, long long s, int z){
	if(xx == y){
		ans = min(ans, s + w[x] + w[y]);
		return ;
	}
	
	for(auto i : v[xx]){
		for(int j = 1 ; j <= k[i] ; j++){
			if(xx == x && a[i][j] == x)s = t[i][j];
		}
		
		for(int j = 1 ; j <= k[i] ; j++){
			if(vis[a[i][j]] == 0){
				vis[a[i][j]] = 1;
				if(z != i && xx != x){
					for(int o = 1 ; o <= k[i] ; o++){
						if(a[i][o] == xx)dfs(a[i][j], s + t[i][j] + t[i][o], i);
					}
					
				}
				else dfs(a[i][j], s + t[i][j], i);
				vis[a[i][j]] = 0;
			}
		}
	}
	
}

int main(){
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	
	cin >> c >> n >> m >> d >> q;
	for(int i = 1 ; i <= m ; i++)cin >> w[i];
	for(int i = 1 ; i <= n ; i++){
		cin >> k[i];
		for(int j = 1 ; j <= k[i] ; j++){
			cin >> a[i][j] >> t[i][j];
			v[a[i][j]].push_back(i);	
		}
	}
	
	while(q--){
		for(int i = 1 ; i <= m ; i++)vis[i] = 0;
		ans = 1e9;
		cin >> x >> y;
		vis[x] = 1;
		dfs(x, 0, 0);
		cout << ans << '\n';
	}
	
	return 0;
}

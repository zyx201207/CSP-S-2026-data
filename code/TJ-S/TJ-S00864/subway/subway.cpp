#include<bits/stdc++.h>
using namespace std;
int c , n , m , d , q ;//表示测试点编号,地铁线路数,地铁站数,每个地铁站最多被几条线路经过,出行计划数
long long w[500005] ;
int k[505] ;
long long a[505][50005] , t[505][50005] ;
bool f[5005][5005] ;
struct Node{
	int che , wei ;
};
vector<Node> e[500005] ;
long long ans = 1e18 ;
int u , v ;
void dfs(int x , int when , int where , long long sum , int fx){
//	cout << "now station num:" << x << " now subway:" << when << " now station:" << where << " now time:" << sum << endl ;
	if(x == v){
		ans = min(ans , sum + w[v] + t[when][where]) ;
//		cout << "x:" << x << " ans:" << ans << endl ; 
		return ;
	}else{
		if(fx == 1){
			if(where + 1 <= m){
				f[when][where + 1] = 1 ;
				dfs(a[when][where + 1] , when , where + 1 , sum , fx) ;
				f[when][where + 1] = 1 ;
			}
		}else{
			if(where - 1 >= 1){
				f[when][where - 1] = 1 ;
				dfs(a[when][where - 1] , when , where - 1 , sum , fx) ;
				f[when][where - 1] = 1 ;
			}
		}
		
		if(e[x].size() != 1){
			for(auto i:e[x]){
				if(i.che != when && i.wei != where && f[i.che][i.wei] == 0){
					f[i.che][i.wei] = 1 ;
					dfs(x , i.che , i.wei , sum + t[when][where] + t[i.che][i.wei] , 1) ;
					dfs(x , i.che , i.wei , sum + t[when][where] + t[i.che][i.wei] , 2) ;
					f[i.che][i.wei] = 0 ;
				}
			}
		}
	}
	return ;
}
int main(){
	freopen("subway.in" , "r" , stdin) ;
	freopen("subway.out" , "w" , stdout) ;
	ios::sync_with_stdio(false) ;
	cin.tie(0) ;
	cout.tie(0) ;
	
	cin >> c >> n >> m >> d >> q ;
	for(int i = 1 ; i <= m ; i ++){
		cin >> w[i] ;
	}
	for(int i = 1 ; i <= n ; i ++){
		cin >> k[i] ;
		for(int j = 1 ; j <= k[i] ; j ++){
			cin >> a[i][j] >> t[i][j] ;
			e[a[i][j]].push_back({i , j}) ;
		}
	}
//	cout << "finished\n" ;
	while(q --){
		memset(f , 0 , sizeof(0)) ;
		ans = 1e18 ;
		cin >> u >> v ;
		for(int i = 1 ; i <= n ; i ++){
			for(int j = 1 ; j <= k[i] ; j ++){
				if(a[i][j] == u){
					dfs(u , i , j , w[u] + t[i][j] , 1) ;
					dfs(u , i , j , w[u] + t[i][j] , 2) ;
				}
			}
		}
		cout << ans << "\n" ;
	}
	return 0;
}

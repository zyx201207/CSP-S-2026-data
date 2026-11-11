#include <bits/stdc++.h>
using namespace std ;
#define int long long
const int N = 5e2 + 5 , NR = 1e5 + 5 ;
int c , n , m , d , q , w[N] , k[N] , a[N][NR] , t[N][NR] , dis[N][NR] , vis[N][NR] ;
struct node
{
	int csn , cst , id , w ;
} ;
vector <node> edge[NR] ;
set <pair <int , int>> st[NR] ;
void bfs(int qcs , int x)
{
	memset(dis , 0x3f , sizeof(dis)) ;
	memset(vis , 0 , sizeof(vis)) ;
	queue <node> q ;
	for(auto i : st[x]) q.push({i.first , i.first , x , 0}) , dis[i.first][x] = 0 , vis[i.first][x] = 1 ;
	while(!q.empty())
	{
		node t = q.front() ;
		q.pop() ;
		for(auto i : edge[t.id])
		{
			if(vis[i.csn][i.id]) continue ;
			if(i.csn == t.cst)
			{
				if(dis[i.csn][i.id] > dis[t.cst][t.id] + i.w)
				{
					dis[i.csn][i.id] = dis[t.cst][t.id] + i.w ;
					for(auto x : st[i.id]) q.push({i.csn , x.first , i.id , dis[i.csn][i.id]}) ;
					vis[i.csn][i.id] = 1 ;
				}
			} 
		}
	}
}
signed main()
{
	ios::sync_with_stdio(0) ;
	cin.tie(0) ;
	cout.tie(0) ;
	freopen("subway.in" , "r" , stdin) ;
	freopen("subway.out" , "w" , stdout) ;
	cin >> c >> n >> m >> d >> q ;
	for(int i = 1 ; i <= m ; i ++) cin >> w[i] ;
	for(int i = 1 ; i <= n ; i ++)
	{
		cin >> k[i] ;
		for(int j = 1 ; j <= k[i] ; j ++) cin >> a[i][j] >> t[i][j] , st[a[i][j]].insert({i , t[i][j]}) ;
		for(int j = 1 ; j < k[i] ; j ++)
		{
			edge[a[i][j]].push_back({i , i , a[i][j + 1] , 0}) ;
			edge[a[i][j + 1]].push_back({i , i , a[i][j] , 0}) ;
		}
	}
	for(int i = 1 ; i <= m ; i ++)
	{
		for(auto x : st[i])
		{
			for(auto y : st[i])
			{
				if(x.first == y.first) continue ;
				edge[i].push_back({x.first , y.first , i , x.second + y.second}) ;
				edge[i].push_back({y.first , x.first , i , x.second + y.second}) ;
			}
		}
	}
	while(q --)
	{
		int l , r ;
		cin >> l >> r ;
		int sum = w[l] + w[r] , ans = 0x3f3f3f3f3f3f3f3f ;
		for(auto i : st[l]) bfs(i.first , l) ;
		for(auto i : st[r]) ans = min(ans , sum + dis[i.first][r]) ;
		cout << ans << "\n" ;
	}
	return 0 ;
}


#include <bits/stdc++.h> 
using namespace std;
#define int long long
struct node{int x , y ;};
bool operator < (node x,node y){return x.y>y.y;}
int c , n , m , d , q , t , x , y , dis[1000505] , dx[1005][1005] ;
vector<node>g[1000505];
bool f[1000505] ;
inline void dij(int s,int T)
{
	memset(dis,0x3f,sizeof(int)*(2*m+n+1));
	memset(f,0,sizeof(int)*(2*m+n+1));
	priority_queue<node>pq;
	pq.push({s,0}); dis[s]=0;
	while (!pq.empty())
	{
		int t = pq.top().x ;
		pq.pop();
		if (t==T)return;
		if (f[t])continue;
		f[t]=1;
		for ( auto i : g[t] )
			if (dis[i.x]>dis[t]+i.y)
			{
				dis[i.x]=dis[t]+i.y;
				pq.push({i.x,dis[i.x]});
			}
	}
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin >> c >> n >> m >> d >> q ;
	for ( int i = 1 ; i <= m ; i ++ )
	{
		cin >> x ;
		g[i].push_back({i+m,x});
		g[i+m].push_back({i,x});
	}
	for ( int i = 1 ; i <= n ; i ++ )
	{
		cin >> t ;
		for ( ; t ; -- t )
		{
			cin >> x >> y ;
			g[i+2*m].push_back({x+m,y});
			g[x+m].push_back({i+2*m,y});
		}
	}
	if (c<12)
	{
		for ( int i = 1 ; i <= m ; i ++ )
		{
			dij(i,0);
			for ( int j = 1 ; j <= m ; j ++ )
				dx[i][j]=dis[j];
		}
		for ( ; q ; -- q )
		{
			cin >> x >> y ;
			write(dx[x][y]); puts("");
		}
		return 0;
	}
	for ( ; q ; -- q )
	{
		cin >> x >> y ; dij(x,y); 
		write(dis[y]); puts("");
	}
	return 0;
}

# include <bits/stdc++.h>
# define pb emplace_back
# define fst first
# define sec second
using namespace std;
typedef long long LL;
const int N = 5e5 + 10;
int c , n , m , d , q , x , y , k , u , v , h , tot , w[N];
LL dis[N * 5];
bool vis[N * 5];
vector <pair <int , int> > g[N];
LL dijk(int s , int t)
{
	memset(dis , 0x3f , sizeof(LL) * (tot + 5));
	memset(vis , 0 , sizeof(bool) * (n + 5));
	queue <int> q;
	dis[s] = 0 , q.push(s);
	while(q.size())
	{
		int t = q.front();
		q.pop();
		vis[t] = 0;
//		cout << t << ' ' << dis[t] << '\n';
		for(auto k : g[t])
		{
			int i = k.fst;
			LL w = k.sec;
			if(dis[t] + w < dis[i])
			{
//				cout << i << ' ' << dis[t] + w << " a\n";
				dis[i] = dis[t] + w;
				if(!vis[i]) vis[i] = 1 , q.push(i);
			}
		}
	}
	return dis[t];
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	freopen("subway.in" , "r" , stdin);
	freopen("subway.out" , "w" , stdout);
	cin >> c >> n >> m >> d >> q , tot = m;
	for(int i = 1 ; i <= m ; i ++)
	{
		cin >> w[i];
	}
	for(int i = 1 ; i <= n ; i ++)
	{
		cin >> k;
		if(c >= 9 && c <= 11)
		{
			for(int j = 1 ; j <= k ; j ++)
			{
				cin >> x >> y;
				if(j > 1)
				{
					g[v].pb(x , h + y);
					g[x].pb(v , h + y);
				}
				v = x , h = y;
			}
		}
		else
		{
			for(int j = 1 ; j <= k ; j ++)
			{
				cin >> v , ++ tot;
				if(j > 1)
				{
	//				cout << tot - 1 << ' ' << tot << " 0\n";
					g[tot].pb(tot - 1 , 0);
					g[tot - 1].pb(tot , 0);
				}
				cin >> h , u = v;
				g[v].pb(tot , h);
				g[tot].pb(v , h);
	//			cout << v << ' ' << tot << ' ' << h << '\n';
			}
		}
	}
//	cout << '\n';
	while(q --)
	{
		cin >> x >> y;
		cout << dijk(x , y) + w[x] + w[y] << '\n';
	}
	return 0;
} 

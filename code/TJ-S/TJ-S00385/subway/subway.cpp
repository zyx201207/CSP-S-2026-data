#include <bits/stdc++.h>
using namespace std;

#define int long long

const int N = 5e5 + 10;
const int NN = 510;

int exr_time[N];

vector <pair<int , int> > v[N];
int edge[NN][NN];

int dis[NN][NN];
bool vis[NN];
int c , n , m , d , q;

inline void disk(int x)
{
	memset(vis , false , sizeof(vis));
	priority_queue <pair <int , int> , vector <pair <int , int> > , greater <pair<int , int> > > q;
	dis[x][x] = 0;
	q.push(make_pair(0 , x));
	while(!q.empty())
	{
		pair <int , int> p = q.top();
		q.pop();
		if(vis[p.second])
		{
			continue;
		}
		vis[p.second] = true;
		for(int i = 1 ; i <= n ; i++)
		{
			if(vis[i])
			{
				continue;
			}
			if(p.first + edge[p.second][i] < dis[x][i])
			{
				dis[x][i] = p.first + edge[p.second][i];
				q.push(make_pair(dis[x][i] , i));
			}
		}
	}
	return;
}

signed main()
{
	freopen("subway.in" , "r" , stdin);
	freopen("subway.out" , "w" , stdout);
	
	int x , y;
	int use;
	scanf("%lld %lld %lld %lld %lld" , &c , &n , &m , &d , &q);
	for(int i = 1 ; i <= m ; i++)
	{
		scanf("%lld" , &exr_time[i]);
	}
	for(int i = 1 ; i <= n ; i++)
	{
		scanf("%lld" , &use);
		for(int j = 1 ; j <= use ; j++)
		{
			scanf("%lld %lld" , &x , &y);
			v[x].push_back(make_pair(i , y));
		}
	}
	for(int i = 1 ; i <= n ; i++)
	{
		for(int j = 1 ; j <= n ; j++)
		{
			edge[i][j] = 1e18;
			dis[i][j] = 1e18;
		}
	}
	for(int i = 1 ; i <= m ; i++)
	{
		for(int j = 0 ; j < v[i].size() ; j++)
		{
			for(int k = j + 1 ; k < v[i].size() ; k++)
			{
				edge[v[i][j].first][v[i][k].first] = min(edge[v[i][j].first][v[i][k].first] , v[i][j].second + v[i][k].second);
				edge[v[i][k].first][v[i][j].first] = min(edge[v[i][j].first][v[i][k].first] , v[i][j].second + v[i][k].second);
			}
		}
	}
	
	for(int i = 1 ; i <= n ; i++)
	{
		disk(i);
	}
	
	while(q--)
	{
		scanf("%lld %lld" , &x , &y);
		int minn = 1e18;
		for(int i = 0 ; i < v[x].size() ; i++)
		{
			for(int j = 0 ; j < v[y].size() ; j++)
			{
				minn = min(minn , dis[v[x][i].first][v[y][j].first] + v[x][i].second + v[y][j].second);
			}
		}
		printf("%lld\n" , minn + exr_time[x] + exr_time[y]);
	}

	return 0;
}

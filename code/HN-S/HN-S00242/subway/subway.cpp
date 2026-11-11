#include <bits/stdc++.h>
#define int long long
using namespace std;

int c , n , m , d , q , sum;
int dis[500005] , jz[500005] , cz[1005][1005];
bool vis[500005];

struct node2
{
	int zd , sj;
}wrq[500005];

struct node
{
	int v , w;
	bool operator <(const node &b)const
	{
		return b.w < w;
	}
};
priority_queue<node>pq;
vector<node>e[500005];
vector<int>e2[500005];

void dij(int s)
{
	for(int i = 1;i <= m;i ++)
	{
		dis[i] = 1e18;
		vis[i] = 0;
	}
	dis[s] = 0;
	pq.push({s , 0});
	while(!pq.empty())
	{
		node t = pq.top();
		int u = t.v;
		pq.pop();
		if(vis[u] == 1)
		{
			continue;
		}
		vis[u] = 1;
		for(int i = 0;i < e[u].size();i ++)
		{
			int v = e[u][i].v , w = e[u][i].w;
			if(dis[v] > dis[u] + w)
			{
				dis[v] = dis[u] + w;
				if(vis[v] == 0)
				{
					pq.push({v , dis[v]});
				}
			}
		}
	}
}

signed main()
{
	freopen("subway.in" , "r" , stdin);
	freopen("subway.out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> c >> n >> m >> d >> q;
	for(int i = 1;i <= m;i ++)
	{
		cin >> jz[i];
	}
	for(int i = 1;i <= n;i ++)
	{
		int k;
		cin >> k;
		sum += k;
		for(int j = 1;j <= k;j ++)
		{
			cin >> wrq[j].zd >> wrq[j].sj;
		}
		if(c >= 12 && c <= 19)
		{
			for(int j = 1;j <= k;j ++)
			{
				if(!e2[wrq[j].zd].empty())
				{
					for(int zy = 0;zy < e2[wrq[j].zd].size();zy ++)
					{
						int u = e2[wrq[j].zd][zy];
						e[u].push_back({i , wrq[j].sj});
						e[i].push_back({u , wrq[j].sj});
					}		
				}
				e2[wrq[j].zd].push_back(i);
			}
		}
		else
		{
			for(int j = 1;j <= k;j ++)
			{
				for(int xh = j + 1;xh <= k;xh ++)
				{
					e[wrq[j].zd].push_back({wrq[xh].zd , wrq[j].sj + wrq[xh].sj});
					e[wrq[xh].zd].push_back({wrq[j].zd , wrq[j].sj + wrq[xh].sj});
				}
			}	
		}
	}
	while(q --)
	{
		int st , ed;
		cin >> st >> ed;
		int ans = jz[st] + jz[ed];
		if(cz[st][ed] != 0 && sum <= 1000)
		{
			cout << ans + cz[st][ed] << "\n";
			continue;
		}
		dij(st);
		if(sum <= 1000)
		{
			for(int i = 1;i <= m;i ++)
			{
				cz[st][i] = dis[i];
			}
		}
		cout << ans + dis[ed] << "\n";
	}
	return 0;
}

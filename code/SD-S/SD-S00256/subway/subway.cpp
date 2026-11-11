#include <bits/stdc++.h>
#define int long long
#define DEBUG cout << "debug" << endl;
using namespace std;
vector <pair<int, int> > a[500505];
int c, n, m, d, q;
int k[505];
int w[500505];
int dis[500505];
int t, nw;
priority_queue <pair<int, int>, vector <pair<int, int> >, greater <pair<int, int> > > pq;
int ans[500005];
vector <pair<int, int> > que[500005];
vector <int> qq;
bool flag[500005], flag2[500005];
void dij(int x)
{
	pq.push({0, x});
	dis[x] = 0;
	while(!pq.empty())
	{
		int xx = pq.top().second, w = pq.top().first;
		pq.pop();
		if(flag[xx]) continue;
		//cout << xx << ' ' << dis[xx] << endl;
		flag[xx] = 1;
		for(int i = 0;i < a[xx].size();i++)
		{
			int y = a[xx][i].first, ne = a[xx][i].second;
			//cout << xx << ' ' << y << dis[y] << endl;
			if(dis[xx] + ne < dis[y])
			{
				dis[y] = dis[xx] + ne;
				pq.push({dis[y], y});
				//cout << xx << ' ' << y << ' ' << ne << ' ' << dis[y] << endl;
			}
		}
		
	}
	return ;
}
signed main()
{
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin >> c >> n >> m >> d >> q;
	for(int i = 1;i <= m;i++)
	{
		cin >> w[i];
	}
	//DEBUG;
	for(int i = 1;i <= n;i++)
	{
		cin >> k[i];
		for(int j = 1;j <= k[i];j++)
		{
			cin >> nw >> t;
			a[nw].push_back({m + i, t});
			a[m + i].push_back({nw, t});
			
		}
	}
	//DEBUG;
	int x, y;
	int cnt = 0;
	while(q--)
	{
		cin >> x >> y;
		cnt++;
		que[x].push_back({cnt, y});
		qq.push_back(x);
	}
	//DEBUG;
	for(int i = 0;i < qq.size();i++)
	{
		int nww = qq[i];
		if(flag2[nww]) continue;
		flag2[nww] = 1;
		memset(flag, 0, sizeof(flag));
		memset(dis, 0x3f, sizeof(dis));
		dij(nww);
		for(int j = 0;j < que[nww].size();j++)
		{
			int id = que[nww][j].first, md = que[nww][j].second;
			ans[id] = dis[md] + w[nww] + w[md];
			//cout << nww << ' ' << md << endl;
		}
	}
	//DEBUG;
	for(int i = 1;i <= cnt;i++)
	{
		cout << ans[i] << endl;
	}
	return 0;
}



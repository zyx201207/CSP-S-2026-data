#include <bits/stdc++.h>
using namespace std;
vector<int> G[55];
int n,k,ans,am,dis[55][55];
void bfs()
{
	memset(dis,0x3f,sizeof dis);
	for (int s = 1;s <= n;s++)
	{
		queue<int> q;
		q.push(s);
		dis[s][s] = 0;
		while(q.size())
		{
			int x = q.front();
			q.pop();
			for (auto nx : G[x])
				if(dis[s][nx] == 0x3f3f3f3f)
					dis[s][nx] = dis[s][x] + 1,q.push(nx);
		}
	}
}
void dfs(int x,int mask)
{
	if(x > k)
	{
		int maxn = 0;
		for (int i = 1;i <= n;i++)
		{
			int minn = 1e9;
			for (int b = 0;b < 10;b++)
				if((mask >> b) & 1)
					minn = min(minn,dis[i][b + 1]);
			maxn = max(maxn,minn);
		}
		if(ans > maxn)
		{
			ans = maxn;
			am = mask;
		}
		return ;
	}
	for (int b = 0;b < 10;b++)
		if(!((mask >> b) & 1))
			dfs(x + 1,mask | (1 << b));
}
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,t;
	cin >>c >> t;
	while(t--)
	{
		cin >>n >> k;
		for (int i = 1;i <= n;i++)
			G[i].clear();
		for (int i = 1;i < n;i++)
		{
			int x,y;
			cin >> x >>y;
			G[x].push_back(y);
			G[y].push_back(x);
		}
		bfs();
		dfs(1,0);
//		for (int i = 1;i <= n;i++)
//			for (int j = 1;j <= n;j++)
//				cout << dis[i][j] <<" \n"[j == n];
		cout << ans << endl;
	}
	return 0;
 } 

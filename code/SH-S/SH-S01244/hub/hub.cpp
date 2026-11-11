#include<bits/stdc++.h>
#define PII pair<int,int>
using namespace std;
int o,t,n,k,d[500005],vis[500005],vis2[500005],vis1[500005],ans = 2e9;
vector<int> v[500005];
vector<int> a;
void bfs(int st)
{
	queue<int> q;
	q.push(st);
	while(!q.empty())
	{
		int u = q.front();
		q.pop();
		for(auto i :v[u])
		{
			if(vis1[i])continue;
			vis1[i] = 1;
			d[i] = d[u] + 1;
			q.push(i);
		}
	}
}
bool bfs2()
{
	int fl = 1;
	queue<int> q;
	q.push(a[1]);
	while(!q.empty())
	{
		if(fl == 3)break;
		while(!q.empty())
		{
			int u = q.front();
			q.pop();
			vis2[u] = 1;
			for(auto i:v[u])
			{
				if(vis2[i])continue;
				for(auto j:a)
				{
					if(i == j)q.push(i);
				}
			}
		}
		for(auto i:a)
		{
			if(vis[i] == 0)
			{
				q.push(i);
				fl++;
				break;
			}
		}
	}
	if(fl <= 2)return 1;
	else return 0;
}
void dfs(int u)
{
	if(u == k + 1)
	{
		if(!bfs2())return;
		int maxn = -1;
		for(auto i:a)
		{
			dfs(i);
			for(auto j:a)
			{
				if(i == j)continue;
				maxn = max(maxn,d[j]);
			}
		}
		ans = min(ans,maxn);
		return;
	}
	for(int i = 1;i <= n;i++)
	{
		if(vis[i])continue;
		vis[i] = 1;
		a.push_back(i);
		dfs(u + 1);
		a.pop_back();
		vis[i] = 0;
	}
}
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin >> o >> t;
	while(t--)
	{
		cin >> n >> k;
		for(int i = 1;i < n;i++)
		{
			int x,y;
			cin >> x >> y;
			v[x].push_back(y);
			v[y].push_back(x);
		}
		dfs(1);
		cout << ans;
		memset(vis,0,sizeof(vis));
		memset(vis1,0,sizeof(vis1));
		memset(vis2,0,sizeof(vis2));
		memset(d,0,sizeof(d));
		a.clear();
		for(int i = 1;i <= n;i++)v[i].clear();
	}
	return 0;
}

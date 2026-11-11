#include<bits/stdc++.h>
#define PII pair<int,int>
using namespace std;
int t,o,a[200005],vis[200005],n,d;
PII v[200005];
void dfs(int u,int st)
{
	if(st >= v[u].second)return ;
	for(int i = u + 1;i <= n;i++)
	{
		if(a[i] - a[u] > d)break;
		if(vis[i])continue;
		if(st + 1 < v[i].second) v[i] = {1,st + 1};
		else if(st + 1 == v[i].second)v[i].first++;
		vis[u] = 1;
		dfs(i,st + 1);
		vis[u] = 0;
	}
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin >> o >> t;
	while(t--)
	{
		memset(vis,0,sizeof(vis));
		memset(a,0,sizeof(a));
		int ans = 0;
		cin >> n >> d;
		for(int i = 1;i <= n;i++)
		{
			cin >> a[i];
		}
		for(int i = 1;i <= n;i++)
		{
			dfs(i,0);
			//cout << "???";
			for(int j = 1;j <= n;j++)
			{
				if(v[j].first == 2)
				{
					ans++;
					//cout << i << " " << j << endl;
				}
			}
		}
		cout << ans << endl;
		for(int i = 1;i <= n;i++)
		{
			v[i] = {0,2e9};
		}
	}
	return 0;
}

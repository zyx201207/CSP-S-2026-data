#include<bits/stdc++.h>
using namespace std;
const int N = 5005;
int c,T,n,m,ans,cnt,fg[N],dis[N];
vector <int> e[N];
int calc(int x,int fa)
{
	int res = 0;
	if(fg[x] && !fg[fa])
	{
		cnt++;
		if(cnt > 2)
		{
			return 1e9;
		}
	}
	if(!fg[x])
	{
		dis[x] = dis[fa] + 1;
	}
	else
	{
		dis[x] = 0;
	}
	for(auto i : e[x])
	{
		if(i == fa)
		{
			continue;
		}
		res = max(calc(i,x),res);
		dis[x] = min(dis[x],dis[i] + 1);
	}
	return max(res,dis[x]);
}
void dfs(int step,int k)
{
	if(k > m)
	{
		return;
	}
	if(step == n + 1)
	{
		if(k != m)
		{
			return;
		}
		cnt = 0;
		memset(dis,0,sizeof(dis));
		dis[0] = 1e9;
		ans = min(ans,calc(1,0));
		return;
	}
	fg[step] = 1;
	dfs(step + 1,k + 1);
	fg[step] = 0;
	dfs(step + 1,k);
}
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin >> c >> T;
	while(T--)
	{
		ans = 1e9; 
		cin >> n >> m;
		for(int i = 1;i <= n;i++)
		{
			e[i].clear();
		}
		for(int i = 1;i < n;i++)
		{
			int u,v;
			cin >> u >> v;
			e[u].push_back(v);
			e[v].push_back(u);
		}
		dfs(1,0);
		cout << ans << '\n';
	}
} 

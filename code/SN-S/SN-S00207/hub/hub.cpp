#include<bits/stdc++.h>
//#define int long long
using namespace std;
int c,t,n,m,dis[1000010];
vector<int> vec[1000010];
bool fl[1000010],vis[1000010];

void dfs(int x)
{
	vis[x]=true;
	for(auto v:vec[x])
	{
		if(!vis[v] && fl[v])
		{
			dfs(v);
		}
	}
}

int bfs()
{
	queue<int> q;
	for(int i=1;i<=n;i++) if(fl[i]) q.push(i),vis[i]=true;
	int ans=0;
	while(!q.empty())
	{
		int tp=q.front();
		q.pop();
		for(auto v:vec[tp])
		{
			if(!vis[v])
			{
				vis[v]=true;
				dis[v]=dis[tp]+1;
				ans=max(ans,dis[v]);
				q.push(v);
			}
		}
	}
	return ans;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--)
	{
		cin>>n>>m;
		int u,v;
		for(int i=1;i<=n;i++) vec[i].clear();
		for(int i=1;i<n;i++)
		{
			cin>>u>>v;
			vec[u].push_back(v);
			vec[v].push_back(u);
		}
		int ans=0x3f3f3f3f;
		for(int j=0;j<(1<<n);j++)
		{
			memset(fl,0,sizeof(fl));
			memset(vis,0,sizeof(vis));
			int tot=0;
			for(int i=1;i<=n;i++)
			{
				if(j&(1<<(i-1))) fl[i]=true,tot++;
			}
			if(tot!=m) continue;
			int cnt=0;
			for(int i=1;i<=n;i++)
			{
				if(!vis[i] && fl[i])
				{
					cnt++;
					dfs(i);
				}
			}
			if(cnt<=2) 
			{
				memset(dis,0,sizeof(dis));
				memset(vis,0,sizeof(vis));
				ans=min(ans,bfs());
			}
		}
		cout<<ans<<"\n";
	}	
	return 0;
}

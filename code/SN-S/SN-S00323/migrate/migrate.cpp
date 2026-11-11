#include <iostream>
#include <cstdio>
#include <queue>
#include <vector>
#include <cstring>
using namespace std;
long long x[2000005],num[2000005];
int cnt[5005][5005];
bool vis[5005];
int n,t,c,ans;
long long d;
vector <int> G[5005];
void bfs(int s)
{
	for(int i=s;i<=n;i++)
	{
		num[i]=1e9;
		vis[i]=0;
	}
	queue <int> q;
	q.push(s);
	num[s]=0;
	while(!q.empty())
	{
		int u=q.front();
		q.pop();
		if(vis[u]) continue;
		vis[u]=1;
		for(int v=0;v<G[u].size();v++)
		{
			if(num[G[u][v]]>num[u]+1)
			{
				num[G[u][v]]=num[u]+1;
				cnt[s][G[u][v]]=1;
				q.push(G[u][v]);
			}
			else if(num[G[u][v]]==num[u]+1)
				cnt[s][G[u][v]]++;
		}
	}
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--)
	{
		ans=0;
		cin>>n>>d;
		memset(cnt,0,sizeof cnt);
		for(int i=1;i<=n;i++)
		{
			cin>>x[i];
			for(int j=i-1;(j>=1&&x[i]-x[j]<=d);j--)
			{
				G[j].push_back(i);
				G[i].push_back(j);
			}
		}
		if(c<=10)
		{
			for(int i=n;i>=1;i--)
			{
				bfs(i);
				for(int j=i+1;j<=n;j++)
					if(cnt[i][j]==2) ans++;
			}
			cout<<ans<<endl;
			for(int i=1;i<=n;i++) G[i].clear();
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

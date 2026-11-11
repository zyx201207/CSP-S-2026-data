#include<bits/stdc++.h>
using namespace std;
int a[100010];
struct node
{
	int nxt,to;
}g[2000010];
int head[2000010],tot;
void add(int u,int v)
{
	tot++;
	g[tot].to=v;
	g[tot].nxt=head[u];
	head[u]=tot;
}
int ans[2000010],vis[2000010],cnt[2000010];
void bfs(int u)
{
	queue<int> q;
	vis[u]=1;
	for(int i=head[u];i!=0;i=g[i].nxt)
	{
		int v=g[i].to;
		if(v<u)continue;
		q.push(v);
		ans[v]=1;
		cnt[v]=1;
	}
	while(!q.empty())
	{
		int u=q.front();
		q.pop();
		vis[u]=1;
		for(int i=head[u];i!=0;i=g[i].nxt)
		{
			int v=g[i].to;
			if(v<u)continue;
			if(vis[v]==1)continue;
			if(ans[v]==ans[u]+1)
			{
				cnt[v]++;
				continue;
			}
			ans[v]=ans[u]+1;
		}
	}
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--)
	{
		tot=0;
		int n,d;
		cin>>n>>d;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
		}
		for(int i=1;i<=n;i++)
		{
			for(int l=1;l<i;l++)
			{
				if(a[i]-a[l]<=d)
				{
					add(i,l);
					add(l,i);
				}
			}
		}
		int ans1=0;
		for(int i=1;i<=n;i++)
		{
			for(int l=1;l<=n;l++)
			{
				ans[l]=0;
				vis[l]=0;
				cnt[l]=0;
			}
			bfs(i);
			for(int i=i+1;i<=n;i++)
			{
				if(cnt[i]==2)
				{
					ans1++;
				}
			}
		}
		cout<<ans1<<endl;
	}
	return 0;
}

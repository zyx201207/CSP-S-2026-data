#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=2e6+10,M=1e7;
struct node
{
	int v,w;
};
vector<int> g[M];
int a[N],n,d;
int dis[N],vis[N],cnt[N];
void spfa(int x)
{
	memset(dis,0x3f,sizeof dis);
	memset(vis,0,sizeof vis);
	memset(cnt,0,sizeof cnt);
	queue<int> q;
	q.push(x);
	vis[x]=1;
	dis[x]=0;
	while(q.size())
	{
		int u=q.front();
		q.pop();
		vis[u]=0;
		for(auto f:g[u])
		{
			int v=f;
			if(dis[v]==dis[u]+1)
			{
				cnt[v]++;
				if(vis[v]==0)
				{
					q.push(v);
					vis[v]=1;
				}
			}
			if(dis[v]>dis[u]+1)
			{
				cnt[v]=1;
				dis[v]=dis[u]+1;
				if(vis[v]==0)
				{
					q.push(v);
					vis[v]=1;
				}
			}
		}
	}
	return;
}
signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int c,T;
	cin>>c>>T;
	while(T--)
	{
		cin>>n>>d;
		for(int i=1; i<=n; i++)
		{
			cin>>a[i];
		}
		for(int i=1;i<=a[n];i++) g[i].clear();
		if(c<=10)
		{
			for(int i=1; i<n; i++)
			{
				for(int j=i+1; j<=n; j++)
				{
					if(a[j]-a[i]<=d)
					{
						g[i].push_back(j);
					}
					else break;
				}
			}
//			for(int i=1;i<=n;i++)
//			{
//				cout<<i<<":";
//				for(auto f:g[i]) cout<<f<<" ";
//				cout<<endl;
//				
//			}
			int ans=0;
			for(int x=1; x<=n-1; x++)
			{
				spfa(x);
				for(int i=x+1; i<=n; i++)
				{
					if(cnt[i]==2) ans++;
				}
//				for(int i=1;i<=n;i++) cout<<cnt[i]<<" ";
//				cout<<endl;
			}
			cout<<ans<<endl;
		}
	}
	return 0;
}
/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5

0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6
*/

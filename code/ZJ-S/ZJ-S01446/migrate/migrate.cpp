#include<bits/stdc++.h>
using namespace std;
#define int long long
const int inf=1e18;
int c,t,n,d,ans,a[2000005],dis[2000005],f[2000005];
bool vis[2000005];
vector<int> v[2000005];
queue<int> q;
void work(int st)
{
	for(int i=1;i<=n;++i)
	{
		dis[i]=inf;
		vis[i]=false;
		f[i]=0;
	}
	dis[st]=0;
	q.push(st);
	f[st]=1;
	while(q.size())
	{
		int u=q.front();
		q.pop();
		if(vis[u]) continue;
		vis[u]=true;
		for(int i=0;i<v[u].size();++i)
		{
			int d=v[u][i];
			if(vis[d]) continue;
			if(dis[u]+1<dis[d])
			{
				dis[d]=dis[u]+1;
				f[d]=f[u];
				q.push(d);
			}
			else
			{
				if(dis[u]+1==dis[d])
					f[d]+=f[u];
			}
		}
	}
}
signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>c>>t;
	while(t--)
	{
		cin>>n>>d;
		for(int i=1;i<=n;++i)
			cin>>a[i];
		for(int i=1;i<=n;++i)
			for(int j=i+1;j<=n;++j)
			{
				int x=a[i]-a[j];
				if(a[i]<a[j]) x=a[j]-a[i];
				if(x<=d)
				{
					v[i].push_back(j);
					v[j].push_back(i);
				}
			}
		ans=0;
		for(int i=1;i<=n;++i)	
		{
			work(i);
			for(int j=i;j<=n;++j)
				if(f[j]==2)
				{
					ans++;	
				}
		}
		cout<<ans<<"\n";
		for(int i=1;i<=n;++i)
			v[i].clear();
	}
	return 0;
}
/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5
*/

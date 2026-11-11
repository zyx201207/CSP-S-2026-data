#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+10;
long long dis[maxn];
int f[maxn];
long long a[maxn];
long long d;
int n;
int tstid;
vector<int>g[maxn];
long long ans;
int t;
struct node
{
	int id;
	long long val;
};
void bfs(int s)
{
	for (int i=1;i<=n;i++)
	{
		dis[i]=1e9;
		f[i]=0;
	}
	dis[s]=0;
	f[s]=1;
	queue<node>q;
	q.push({s,0});
	while(!q.empty())
	{
		int u=q.front().id;
		int nwd=q.front().val;
		q.pop();
		if(nwd>dis[u])
			continue;
		if(f[u]>2)
			continue;
		for (int v:g[u])
		{
			if(dis[u]+1<dis[v])
			{
				dis[v]=dis[u]+1;
				f[v]=f[u];
				q.push({v,dis[v]});
			}
			else if(dis[u]+1==dis[v])
				f[v]+=f[u];
		}
	}
	for (int i=1;i<=n;i++)
		if(f[i]==2)
			ans++;
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>tstid>>t;
	while(t--)
	{
		ans=0;
		cin>>n>>d;
		for (int i=1;i<=n;i++)
		{
			cin>>a[i];
			g[i].clear();
			dis[i]=1e9;
			f[i]=0;
		}
		for (int i=1;i<=n;i++)
			for (int j=i+1;j<=n;j++)
				if(a[j]-a[i]<=d)
				{
//					cout<<i<<" "<<j<<endl;
					g[i].push_back(j);
				}
		for (int i=1;i<=n;i++)
			bfs(i);
		cout<<ans<<'\n';
	}
}

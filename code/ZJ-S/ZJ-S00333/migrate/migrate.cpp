#include<bits/stdc++.h>
using namespace std;

long long a[2000000+10];
int d[200000+10],cnt[200000+10];
bool vis[2000000+10];
vector<int> g[2000000+10];

void dfs(int x,int fa)
{
	for(int t:g[x])
	{
		if(t==fa) continue;
		if(d[x]==d[fa]+1)
		{
			cnt[x]++;
		}
		if(d[x]>d[fa]+1)
		{
			d[x]=d[fa]+1;
			dfs(t,x);
		}
	}
}

int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	int c,t;
	cin>>c>>t;
	while(t--)
	{
		long long n,p;
		long long cn=0;
		cin>>n>>p;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
		}
		for(int i=1;i<=n;i++)
		{
			int l=i+1;
			while(l<=n&&a[l]-a[i]<=p)
			{
				g[i].push_back(l);
				g[l].push_back(i);
				l++;
			}
		}
		for(int i=1;i<=n;i++)
		{
			//int cn=0;
			memset(d,0x3f,sizeof d);
			memset(cnt,0,sizeof cnt);
			d[0]=0;
			dfs(i,0);
			for(int j=i+1;j<=n;j++)
			{
				if(cnt[j]==1) cn++;
			}
		}
		cout<<cn<<"\n";
	}
	return 0;
}
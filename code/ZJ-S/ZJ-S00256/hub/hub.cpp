#include<bits/stdc++.h>
using namespace std;
vector<int>v[200005];
int a[200005];
int t[200005];
void dfs1(int x)
{
	for(int y:v[x])
	{
		if(a[y]==1&&t[y]==0)
		{
			t[y]=1;
			dfs1(y);
		}
	}
}
void dfs2(int x)
{
	for(int y:v[x])
	{
		if(t[y]>t[x]+1)
		{
			t[y]=t[x]+1;
			dfs2(y);
		}
	}
}
void solve(void)
{
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		v[i].clear();
	}
	for(int i=1;i<n;i++)
	{
		int x,y;
		cin>>x>>y;
		v[x].push_back(y);
		v[y].push_back(x);
	}
	int ans=n;
	for(int s=0;s<(1<<n);s++)
	{
		int k=0;
		for(int i=0;i<n;i++)
		{
			a[i+1]=(s>>i)&1;
			k+=a[i+1];
			t[i+1]=0;
		}
		if(k!=m)
		{
			continue;
		}
		int h=0;
		for(int i=1;i<=n;i++)
		{
			if(a[i]==1&&t[i]==0)
			{
				h++;
				t[i]=1;
				dfs1(i);
			}
		}
		for(int i=1;i<=n;i++)
		{
			t[i]=2e9;
		}
		for(int i=1;i<=n;i++)
		{
			if(a[i]==1)
			{
				t[i]=0;
				dfs2(i);
			}
		}
		if(h<=2)
		{
			int ak=1;
			for(int i=1;i<=n;i++)
			{
				ak=max(ak,t[i]);
			}
			ans=min(ans,ak);
		}
	}
	cout<<ans<<"\n";
}
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int RP,T;
	cin>>RP>>T;
	RP++;
	while(T--)
	{
		solve();
	}
	return 0;
}
/*
0 2
5 2
1 2
2 3
3 4
4 5
10 3
1 2
1 3
2 4
2 5
3 6
3 7
3 8
7 9
9 10
*/

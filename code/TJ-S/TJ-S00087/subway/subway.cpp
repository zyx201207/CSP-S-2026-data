#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,n,m,d,q;
int w[1000];
int k[600];
int f[600][1000],t[600][1000];
int x,y;
int minn=100000;
vector<bool> o(600,false);
vector<bool> p(600,false);
vector<vector<int>> a(600,vector<int>());
void dfs(int g,int i,int sum)
{
	if (o[i]==true)
	{
		return;
	}
	int temp2;
	if (f[i][0]==g)
	{
		temp2=0;
	}
	else
	{
		temp2=1;
	}
	if (g==y)
	{
		sum+=t[i][temp2]+w[g];
		minn=min(sum,minn);
		return;
	}
	if (p[i]==false)
	{
		p[i]=true;
		if (temp2==1) dfs(f[i][1],i,sum+t[i][0]+t[i][1]);
		else dfs(f[i][0],i,sum+t[i][0]+t[i][1]);
	}
	o[i]=true;
	for (int j=1;j<=a[g].size();j++)
	{
		if (a[g][j]==i)
		{
			continue;
		}
		dfs(g,a[g][j],sum);
	}
}
signed main()
{
	freopen ("subway.in","r",stdin);
	freopen ("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for (int i=1;i<=m;i++)
	{
		cin>>w[i];
	}
	for (int i=1;i<=n;i++)
	{
		cin>>k[i];
		for (int j=1;j<=k[i];j++)
		{
			int temp1;
			cin>>temp1>>t[i][j];
			a[temp1].push_back(i);
			f[i][j]=temp1;
		}
	}
	for (int r=1;r<=q;r++)
	{
		cin>>x>>y;
		int temp5;
		for (int i=1;i<=a[x].size();i++)
		{
			int temp2;
			if (f[a[x][i]][0]==x)
			{
				temp2=0;
			}
			else
			{
				temp2=1;
			}
			dfs(a[x][i],a[x][i],w[x]+t[a[x][i]][temp2]);
		}
 	}
 	cout<<minn;
	return 0;
}

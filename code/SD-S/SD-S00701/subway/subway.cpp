#include <bits/stdc++.h>
using namespace std;
int m,n,q,c,d,k[505],x[100005],y[100005],g[505][20005];
int w[20005],t[505][20005];
vector<int> v[505];
int dfs(int a,int b)
{
	if(v[a][b])
	{
		return t[a][b];
	}
	int ans=1000000000;
	for(int i=0;i<v[a].size();i++)
	{
		ans=min(ans,v[a][v[a][i]]+dfs(v[a][i],b));
	}
	return ans;
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("sumway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
	{
		cin>>w[i];
	}
	for(int i=1;i<=n;i++)
	{
		cin>>k[i];
		for(int j=1;j<=k[i];j++)
		{
			cin>>g[i][j]>>t[i][j];
			if(j!=1)
			{
				v[g[i][j-1]].push_back(g[i][j]);
				v[g[i][j-1]][g[i][j]]=t[i][j-1]+t[i][j];
			}
		}
	}
	for(int i=1;i<=q;i++)
	{
		cin>>x[i]>>y[i];
		int ans=w[x[i]]+w[y[i]];
		if(v[x[i]][y[i]]>0)
		{
			cout<<ans+t[x[i]][y[i]]+t[x[i]][x[i]]<<endl;
			continue;
		}
		else
		{
			cout<<ans+dfs(x[i],y[i]);
		}
	}
	return 0;
}

#include <bits/stdc++.h>
using namespace std;
int w[500005],a[25],t[505][25],ditu[55][55];
long long v[500005];
long long x,y,tim,l,la,o,ti;
long long c, n, m, d, q,k;
void dfs(long long a)
{
	if(a==y) 
	{
		tim+=t[l][a];
		o++;
		if(o==1)
		{
			ti=tim;
		}
		return;
	}
	v[a]=1;
	for(int i=1;i<=m;i++)
	{
		if(ditu[a][i]!=0&&v[i]==0)
		{
			if(ditu[a][i]!=l)
			{
				tim=tim+(t[l][a]+t[ditu[a][i]][a]);
				la=l;
				l=ditu[a][i];
				dfs(i);
				tim=tim-(t[l][a]+t[la][a]);
				l=la;continue;
			}
			dfs(i);
		}
	}
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	
	for(int i=1;i<=m;i++)
	{
		cin>>w[i];
	}
	for(int i=1;i<=n;i++)
	{
		cin>>k;
		for(int j=1;j<=k;j++)
		{
			cin>>a[j]>>t[i][j];
		}
		for(int j=1;j<k;j++)
		{
			ditu[a[j]][a[j+1]]=i;
			ditu[a[j+1]][a[j]]=i;
		}
	}
	
	while(q--)
	{
		cin>>x>>y;
		dfs(x);
		ti+=w[x]+w[y];
		cout<<ti;
	}
	return 0;
}

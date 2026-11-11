#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll c,n,m,d,q,w[500010],a[500010][22],t[500010][22],l[500010],dis[510][510];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			dis[i][j]=1000000000000000000;
		}
	}
	for(int i=1;i<=m;i++)
	{
		cin>>w[i];
	}
	for(int i=1;i<=n;i++)
	{		
		dis[i][i]=0;
		ll k;
		cin>>k;
		for(int j=1;j<=k;j++)
		{
			ll x,y;
			cin>>x>>y;
			l[x]++;
			a[x][l[x]]=i;
			t[x][l[x]]=y;
		}
	}
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=l[i];j++)
		{
			for(int k=j+1;k<=l[i];k++)
			{
				dis[a[i][j]][a[i][k]]=min(dis[a[i][j]][a[i][k]],t[i][j]+t[i][k]);
				dis[a[i][k]][a[i][j]]=min(dis[a[i][k]][a[i][j]],t[i][j]+t[i][k]);
			}
		}
	}
	for(int k=1;k<=n;k++)
	{
		for(int i=1;i<=n;i++)
		{
			if(k==i) continue;
			for(int j=1;j<=n;j++)
			{
				if(k==j || i==j) continue;
				if(dis[i][j]>dis[i][k]+dis[k][j])
				{
					dis[i][j]=dis[i][k]+dis[k][j];
				}
			}
		}
	}
	while(q--)
	{
		ll x,y,out=1000000000000000000;
		cin>>x>>y;
		for(int i=1;i<=l[x];i++)
		{
			for(int j=1;j<=l[y];j++)
			{
				out=min(out,dis[a[x][i]][a[y][j]]+t[x][i]+t[y][j]);
			}
		}
		cout<<out+w[x]+w[y]<<'\n';
	}
	return 0;
}

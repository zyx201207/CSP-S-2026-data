#include <bits/stdc++.h>
using namespace std;
long long c,n,m,d,q,w[500005],k[505],a[500005],t[500005];
long long x,y,cz[500005][25],v1,v2;
long long dt1[505][505],ze[500005],zes[500005][25],ans;
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for (int i=1;i<=m;i++)
		cin>>w[i];
	for (int i=1;i<=n;i++)
	{
		cin>>k[i];
		for (int j=1;j<=k[i];j++)
		{
			cin>>a[j]>>t[j];
			cz[a[j]][++ze[a[j]]]=t[j];
			zes[a[j]][ze[a[j]]]=i;
			if (ze[a[j]]>20)
			{
				cout<<i;
				return 0;
			}
		}
	}
	for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++)
			dt1[i][j]=1e18;
	for (int i=1;i<=n;i++)
		dt1[i][i]=0;
	for (int i=1;i<=m;i++)
		for (int j=1;j<=ze[i];j++)
			for (int k=j+1;k<=ze[i];k++)
			{
				dt1[zes[i][j]][zes[i][k]]=min(dt1[zes[i][j]][zes[i][k]],cz[i][j]+cz[i][k]);
				dt1[zes[i][k]][zes[i][j]]=min(dt1[zes[i][j]][zes[i][k]],cz[i][j]+cz[i][k]);
			}
	for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++)
			for (int k=1;k<=n;k++)
				dt1[k][j]=dt1[j][k]=min(dt1[j][k],dt1[j][i]+dt1[i][k]);
	while(q--)
	{
		ans=1e18;
		cin>>x>>y;
		for (int j=1;j<=ze[x];j++)
			for (int k=1;k<=ze[y];k++)
			{
				v1=zes[x][j];
				v2=zes[y][k];
				ans=min(ans,cz[x][j]+dt1[v1][v2]+cz[y][k]);
			}
		ans+=w[x]+w[y];
		cout<<ans<<"\n";
	}
	cout<<q;
	return 0;
}

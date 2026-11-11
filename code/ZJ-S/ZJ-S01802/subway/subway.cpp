#include<bits/stdc++.h>
using namespace std;
const int N=502;
const int M=1002;
const long long inf=1e18;
int c,n,m,d,q;
long long w[N],k[N],a[N][M],t[N][M],dis[M][M];
void solve1()
{
	for (int i=1;i<=m;i++)
		for (int j=1;j<=m;j++)
			dis[i][j]=inf;
	for (int i=1;i<=n;i++)
		for (int l=1;l<=k[i];l++)
			for (int r=1;r<=k[i];r++)
			{
				int u=a[i][l],v=a[i][r];
				dis[u][v]=min(dis[u][v],t[i][l]+t[i][r]);
			}
	for (int i=1;i<=m;i++)
		for (int j=1;j<=m;j++)
			for (int l=1;l<=m;l++)
				if (i!=j and i!=l and j!=l)
					dis[i][j]=min(dis[i][l]+dis[l][j],dis[i][j]);
	for (int i=1;i<=m;i++)
		for (int j=1;j<=m;j++)
			dis[i][j]+=w[i]+w[j];
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for (int i=1;i<=m;i++)
		cin>>w[i];
	for (int i=1;i<=n;i++)
	{
		cin>>k[i];
		for (int j=1;j<=k[i];j++)
			cin>>a[i][j]>>t[i][j];	
	}
	solve1();
	while (q--)
	{
		int x,y;
		cin>>x>>y;
		cout<<dis[x][y]<<"\n";
	}
	return 0;
} 

#include<bits/stdc++.h>
using namespace std;
const int MAXM=5e5+5;
const int MAXN=505;
int c,n,m,d,q;
int w[MAXM],k[MAXN],a[MAXM],t[MAXM];
long long dis[2000][2000];
void build(int lim)
{
	for(int i=1;i<=lim;i++)
	{
		for(int j=1;j<i;j++)
		{
			dis[a[i]][a[j]]=t[i]+t[j];
			dis[a[j]][a[i]]=t[i]+t[j];
		}
	}
}
void work()
{
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(i==j)
				continue;
			for(int k=1;k<=m;k++)
			{
				if(k==i||k==j)
					continue;
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
			}
		}
	}
}
void solve1()
{
	for(int i=1;i<=m;i++)
		cin>>w[i];
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=m;j++)
		{
			dis[i][j]=1e18;
		}
		dis[i][i]=0;
	}
	for(int i=1;i<=n;i++)
	{
		cin>>k[i];
		for(int j=1;j<=k[i];j++)
		{
			cin>>a[j]>>t[j];
		}
		build(k[i]);
	}
	work();
	while(q--)
	{
		int x,y;
		cin>>x>>y;
		cout<<w[x]+w[y]+dis[x][y]<<"\n";
	}
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	solve1();
	return 0;
}
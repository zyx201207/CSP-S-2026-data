#include<bits/stdc++.h>
using namespace std;
const int N=510,M=500010;
const long long inf=1e12;
int n,m,c,d,q,cnt[M];
long long w[M],dis[N][N],t[M][22],id[M][22];
void floyd()
{
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
			{
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
			}
	return;
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
	{
		cin>>w[i];
	}
	int k,a,ta;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			dis[i][j]=inf;
	for(int i=1;i<=n;i++) dis[i][i]=0;
	for(int i=1;i<=n;i++)
	{
		cin>>k;
		for(int j=1;j<=k;j++)
		{
			cin>>a>>ta;
			for(int p=1;p<=cnt[a];p++)
			{
				dis[id[a][p]][i]=ta+t[a][p];
				dis[i][id[a][p]]=ta+t[a][p];
			}
			id[a][++cnt[a]]=i;
			t[a][cnt[a]]=ta;
		}
	}
	floyd();
	long long x,y,ans=inf;
	while(q--)
	{
		cin>>x>>y;
		ans=inf;
		for(int i=1;i<=cnt[x];i++)
		{
			for(int j=1;j<=cnt[y];j++)
			{
				if(id[x][i]==id[y][j])
				{
					ans=min(ans,t[x][i]+t[y][j]);
				}
				else
				{
					ans=min(ans,t[x][i]+t[y][j]+dis[id[x][i]][id[y][j]]);
				}
			}
		}
		cout<<ans+w[x]+w[y]<<'\n';
	}
	return 0;
}

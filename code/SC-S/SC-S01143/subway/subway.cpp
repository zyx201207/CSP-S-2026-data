#include <bits/stdc++.h>
using namespace std;
const int N=5e5+5;
bool v[505][505];
long long w[N],d[505][505];
int c,n,m,e,q;
struct edge
{
	int y,w;
};
vector<edge> cnt[N];
long long floyd1(int i,int j)
{
	if(d[i][j]!=2e18)
		return d[i][j];
	for (int k=i;k<=j;k++)
	{
		if(k!=i&&k!=j)
			d[i][j]=min(floyd1(i,k)+floyd1(k,j),d[i][j]);
	}
	return d[i][j];
}
long long floyd2(int i,int j)
{
	if(d[i][j]!=2e18||v[i][j])
		return d[i][j];
	v[i][j]=1;
	for (int k=1;k<=n;k++)
	{
		if(k!=i&&k!=j)
			d[i][j]=min(floyd2(i,k)+floyd2(k,j),d[i][j]);
	}
	return d[i][j];
}
int main()
{
	freopen("subway3.in","r",stdin);
	freopen("subway3.out","w",stdout);
	for(int i=1;i<=500;i++)
	{
		for(int j=1;j<=500;j++)
		{
			d[i][j]=2e18;
		}
	}
	for (int i=1;i<=500;i++)
	{
		d[i][i]=0;
	}
	cin>>c>>n>>m>>e>>q;
	for(int i=1;i<=m;i++)
	{
		cin>>w[i];
	}
	for(int i=1;i<=n;i++)
	{
		int p;
		cin>>p;
		for (int j=1;j<=p;j++)
		{
			int x,t;
			cin>>x>>t;
			for(int k=0;k<cnt[x].size();k++)
			{
				d[i][cnt[x][k].y]=t+cnt[x][k].w;
				d[cnt[x][k].y][i]=t+cnt[x][k].w;
			}
			cnt[x].push_back({i,t});
		}
	}
	for (int i=1;i<=n;i++)
	{
		for (int j=i+1;j<=n;j++)
		{
			d[i][j]=min(floyd1(i,j),floyd2(i,j));
			d[j][i]=min(floyd1(j,i),floyd2(i,j));
		}
	}
	for (int i=1;i<=q;i++)
	{
		int x,y;
		cin>>x>>y;
		long long ans=9e18;
		for (int j=0;j<cnt[x].size();j++)
		{
			for (int k=0;k<cnt[y].size();k++)
			{
				ans=min(ans,w[x]+cnt[x][j].w+d[cnt[x][j].y][cnt[y][k].y]+cnt[y][k].w+w[y]); 
			}
		}
		cout<<ans<<endl;
	} 
	return 0;
}
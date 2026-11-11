#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
int c,d;
long long w[500005];
int n,m,q;
int k[505];
vector <int> lsid[505];
vector <long long> lst[505];
vector <int> slid[100005];
vector <long long> slt[100005];
long long G[505][505],f[505][505];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	for (int i=1;i<=m;i+=1) scanf("%lld",&w[i]);
	for (int i=1;i<=n;i+=1)
	{
		scanf("%d",&k[i]);
		for (int j=0;j<k[i];j+=1)
		{
			int id0;
			long long t0;
			scanf("%d%lld",&id0,&t0); 
			lsid[i].push_back(id0);
			lst[i].push_back(t0);
			slid[id0].push_back(i);
			slt[id0].push_back(t0);
		}
	}
	for (int d1=1;d1<=n;d1+=1)
	{
		for (int d2=d1+1;d2<=n;d2+=1)
		{
			G[d1][d2]=4e18;
		}
	}
	for (int i=1;i<=m;i+=1)
	{
		int num=slid[i].size();
		for (int id1=0;id1<num;id1+=1)
		{
			for (int id2=id1+1;id2<num;id2+=1)
			{
				int d1=slid[i][id1];
				int d2=slid[i][id2];
				G[d1][d2]=min(G[d1][d2],slt[i][id1]+slt[i][id2]);
			}
		}
	}
	for (int i=1;i<=n;i+=1)
	{
		for (int j=1;j<=n;j+=1)
		{
			f[i][j]=G[i][j];
		}
	}
	for (int T=1;T<=n;T+=1)
	{
		for (int i=1;i<=n;i+=1)
		{
			for (int j=1;j<=n;j+=1)
			{
				f[i][j]=min(f[i][j],f[i][T]+f[T][j]);
			}
		}
	}
	while (q--)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		int num1=slid[x].size();
		long long ans=2e18;
		for (int id1=0;id1<num1;id1+=1)
		{
			int d1=slid[x][id1];
			int num2=slid[y].size();
			for (int id2=0;id2<num2;id2+=1)
			{
				int d2=slid[y][id2];
				if (d1==d2) ans=min(ans,slt[x][id1]+slt[y][id2]);
				else ans=min(ans,slt[x][id1]+f[d1][d2]+slt[y][id2]);
			}
		}
		printf("%d\n",w[x]+ans+w[y]);
	}
	return 0;
}

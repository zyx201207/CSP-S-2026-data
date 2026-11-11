#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
int c,n,m,d,q;
struct node
{
	int route;
	long long time;
};
node sta[500001][21];
int num[500001];
long long w[500001];
long long f[501][501];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	for(int i = 1;i <= m;i++)
	{
		scanf("%d",&w[i]);
	}
	memset(f,999999,sizeof(f));
	for(int i = 1;i <= n;i++)
	{
		f[i][i] = 0;
	}
	for(int i = 1;i <= n;i++)
	{
		int k;
		scanf("%d",&k);
		int a;
		long long b;
		for(int j = 1;j <= k;j++)
		{
			scanf("%d%lld",&a,&b);
			num[a]++;
			sta[a][num[a]] = {i,b};
			for(int l = 1;l < num[a];l++)
			{
				int x = sta[a][l].route;
				long long y = sta[a][l].time + b;
				f[x][i] = f[i][x] = min(f[x][i],y);
			}
		}
	}
	for(int k = 1;k <= n;k++)
	{
		for(int i = 1;i <= n;i++)
		{
			if(f[k][i] >= 1e18) continue;
			for(int j = 1;j <= n;j++)
			{
				f[i][j] = min(f[i][j],f[i][k] + f[k][j]);
			}
		}
	}
	int x,y;
	while(q--)
	{
		scanf("%d%d",&x,&y);
		long long ans = 9e18;
		for(int i = 1;i <= num[x];i++)
		{
			for(int j = 1;j <= num[y];j++)
			{
				node t1 = sta[x][i],t2 = sta[y][j];
				ans = min(ans,t1.time + t2.time + f[t1.route][t2.route]);
			}
		}
		printf("%lld\n",ans + w[x] + w[y]);
	}
} 

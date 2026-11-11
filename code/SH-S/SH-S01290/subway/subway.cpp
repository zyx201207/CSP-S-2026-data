#include<bits/stdc++.h>
using namespace std;
#define int long long
int read()
{
	int ret = 0;
	char g = getchar();
	while(!isdigit(g))
	{
		g = getchar();
	}
	while(isdigit(g))
	{
		ret = ret * 10 + g - '0';
		g = getchar();
	}
	return ret;
}
const int maxn = 502,maxm = 5e5 + 7;
int C,n,m,D,q,w[maxm];
int len[maxn];
int c[maxm][22],cnt[maxm];
int t[maxm][22];
int f[maxn][maxn];
signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	C = read();n = read();m = read();D = read();q = read();
	for(int i = 1;i<=m;i++) cin>>w[i];
	for(int i = 1;i<=n;i++)
	{
		int len = read();
		for(int j = 1;j<=len;j++)
		{
			int a,tt;
			a = read();tt = read();
			c[a][++cnt[a]] = i;
			t[a][cnt[a]] = tt;
		}
	}
//	for(int i = 1;i<=m;i++)
//	{
//		for(int j = 1;j<=cnt[i];j++) printf("%d ",c[i][j]);
//		printf("\n");
//		for(int j = 1;j<=cnt[i];j++) printf("%d ",t[i][j]);
//		printf("\n");
//	}
	for(int i = 1;i<=n;i++)
	{
		for(int j = 1;j<=n;j++)
		{
			f[i][j] = 1e18;
		}
	}
	for(int i = 1;i<=n;i++) f[i][i] = 0;
	for(int i = 1;i<=m;i++)
	{
		for(int j1 = 1;j1 <= cnt[i];j1++)
		{
			for(int j2 = 1;j2 <= cnt[i];j2++)
			{
				int p1 = c[i][j1],p2 = c[i][j2];
				f[p1][p2] = min(f[p1][p2],t[i][j1]+t[i][j2]);
				f[p2][p1] = min(f[p2][p1],f[p1][p2]);
			}
		}
	}
	//floyd
	for(int k = 1;k<=n;k++)
	{
		for(int i = 1;i<=n;i++)
		{
			for(int j = 1;j<=n;j++)
			{
				f[i][j] = min(f[i][j],f[i][k]+f[k][j]);
			}
		}
	}
	
//	for(int i = 1;i<=n;i++)
//	{
//		for(int j = 1;j<=n;j++)
//		{
//			printf("%lld ",f[i][j]);
//		}
//		printf("\n");
//	}
	while(q--)
	{
		int x,y,ans = 1e18,c1,c2;
		x = read();y = read();
		for(int i = 1;i<=cnt[x];i++)
		{
			for(int j = 1;j<=cnt[y];j++)
			{
				if(ans > f[c[x][i]][c[y][j]])
				{
					ans = f[c[x][i]][c[y][j]];
					c1 = i;c2 = j;
				}
			}
		}
		//printf("%d %d %d ",c1,c2,ans);
		printf("%lld\n",ans + w[x] + w[y] + t[x][c1] + t[y][c2]);
	}
	return 0;
}

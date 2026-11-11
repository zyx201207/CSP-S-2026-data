#include<bits/stdc++.h>
#include<cstdio>
using namespace std;

const int N=5e5+10;
const int M=1e5+10;
int w[N],k[N],dp[2020][2020];
int a[510][N],t[510][N];
struct sta{
	int x,y;
}r[M];
int bj[N],num[N];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	memset(dp,2147483647,sizeof(dp));
	int c,n,m,d,p;
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&p);
	for(int i=0;i<=m-1;i++)
		scanf("%d",&w[i]);
	for(int i=0;i<=n-1;i++)
	{
		scanf("%d",&k[i]);
		for(int j=0;j<=k[i]-1;j++)
		{
			scanf("%d%d",&a[i][j],&t[i][j]);
			bj[num[a[i][j]]]=i;
			num[a[i][j]]++;
		}
	}
	for(int i=0;i<=m-1;i++)
		for(int j=0;j<=num[i];j++)
			for(int ii=j+1;ii<=num[i];ii++)
				dp[bj[j]][bj[ii]]=t[bj[j]][i]+t[bj[ii]][i];
	for(int i=0;i<=n-1;i++)
		for(int j=0;j<=n-1;j++)
			for(int ii=0;ii<=n-1;ii++)
				if(dp[i][ii]!=2147483647&&dp[ii][j]!=2147483647&&dp[i][j]>dp[i][ii]+dp[ii][j])
					dp[i][j]=dp[i][ii]+dp[ii][j];
	for(int i=0;i<=p;i++)
	{
		scanf("%d%d",&r[i].x,&r[i].y);
		printf("%d\n",w[r[i].x]+w[r[i].y]+t[0][r[i].x]+t[r[i].y][3]+dp[r[i].x][r[i].y]);
	}
	return 0;
}

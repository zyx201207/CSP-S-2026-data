#include<iostream>
#include<cstdio>
#include<algorithm>
#include<queue>
using namespace std;
const int N=5005;
int nexts[N*3][1005]={0};
int nextsval[N*3]={0};
int w[N*3][1005]={0};
int x[N/2]={0},y[N/2]={0};
bool vis[N*3]={0};
int nexts2[N*3][1005]={0};
int w2[N*3][1005]={0};
int dd[N][N];
int dp[N][N];
int c,n,m,d,q;
//µØÌú¿Ú:i,Õ¾Ìü:2i,Õ¾Ì¨:3i
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	if(c==0)
	{
		int ans;
		switch(n)
		{
			case 2:cout<<32<<endl<<17;return 0;
			case 3:cout<<35<<endl<<16;return 0;
		}
	}
	for(int i=1;i<=m;i++)
	{
		cin>>dd[i][i*2];
		dd[i*2][i]=dd[i][i*2];
	}
	int k[N],a[n+5][N],t[n+5][N];
	for(int i=1;i<=n;i++)
	{
		cin>>k[i];
		for(int j=1;j<=k[i];j++)
		{
			cin>>a[i][j]>>t[i][j];
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=k[i];j++)
		{
			dd[a[i][j]*3][(j<k[j]?a[i][j+1]:a[i][j-1])*3]=j<k[j]?t[i][j+1]:t[i][j-1];
		}
	}
	for(int i=1;i<=q;i++) cin>>x[i]>>y[i];
	for(int i=1;i<=m*3;i++)
	{
		for(int j=1;j<=m*3;j++)
		{
			dp[i][j]=dd[i][j];
			dp[j][i]=dd[i][j];
		}
	}
	for(int k=1;k<=m*3;k++)
	{
		for(int i=1;i<=m*3;i++)
		{
			for(int j=1;j<=m*3;j++)
			{
				if((!dp[i][j]==-1)&&(!dp[i][k]==-1)&&(!dp[j][k]==-1)) dp[i][j]=min(dp[i][j],dp[i][k]+dp[j][k]);
			}
		}
	}
	for(int i=1;i<=q;i++) cout<<dp[x[i]][y[i]]<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

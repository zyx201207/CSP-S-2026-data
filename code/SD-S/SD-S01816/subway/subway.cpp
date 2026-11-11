#include<bits/stdc++.h>
#define int long long
using namespace std;
int read()
{
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9')
	{
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')
	{
		x=x*10+ch-'0';
		ch=getchar();
	}
	return x*f;
}
const int N=5e5+5;
int dp[505][505],cnt,t[N][21][2],di,n,m,tot[N],wo[N];
struct node
{
	int nxt,to;
}e[N];
signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int C=read();n=read();m=read();di=read();int Q=read();
	for(int i=1;i<=m;i++)wo[i]=read();
	for(int i=1;i<=n;i++)
	{
		int kp=read();
		for(int j=1;j<=kp;j++)
		{
			int a=read(),b=read();
			t[a][++tot[a]][0]=i;
			t[a][tot[a]][1]=b;
		}
	}
	for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)if(i!=j)dp[i][j]=2e18;
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=tot[i];j++)
		{
			for(int k=j+1;k<=tot[i];k++)
			{
				int x=t[i][j][0],y=t[i][k][0];
				dp[x][y]=min(dp[x][y],t[i][j][1]+t[i][k][1]);
				dp[y][x]=dp[x][y];
			}
		}
	}
	for(int k=1;k<=n;k++)
	{
		for(int i=1;i<=n;i++)
		{
			if(i==k)continue;
			for(int j=1;j<=n;j++)
			{
				if(j==k)continue;
				dp[i][j]=min(dp[i][k]+dp[k][j],dp[i][j]);
			}
		}
	}
//	for(int i=1;i<=n;i++)
//	{
//		for(int j=1;j<=n;j++)cout<<dp[i][j]<<" ";
//		cout<<'\n';
//	}
	while(Q--)
	{
		int a=read(),b=read();
		int ans=2e18;
		for(int i=1;i<=tot[a];i++)
		{
			for(int j=1;j<=tot[b];j++)
			{
				int x=t[a][i][0],y=t[b][j][0];
				ans=min(ans,dp[x][y]+t[a][i][1]+t[b][j][1]);
			}
		}
		cout<<ans+wo[a]+wo[b]<<'\n';
	}
	return 0;
 }


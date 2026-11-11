#include<bits/stdc++.h>
#define int long long
#define db double
#define endl "\n"
using namespace std;
const int N=3010,inf=0x7f7f7f7f;
inline int read()
{
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-48;ch=getchar();}
	return x*f;
}
int c,n,m,d,q;
int w[N],k[N],a[N][N],t[N][N];
int dp[N][N];
signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	c=read();
	n=read();m=read();d=read();q=read();
	for(int i=1;i<=m;i++)
	{
		w[i]=read();
	}
	memset(dp,inf,sizeof(dp));
	for(int i=1;i<=n;i++)
	{
		k[i]=read();
		for(int j=1;j<=k[i];j++)
		{
			a[i][j]=read();t[i][j]=read();
		}
	}
	for(int i=1;i<=n;i++)
	{
		if(k[i]==1) continue;
		for(int j=1;j<=k[i];j++)
		{
			for(int l=1;l<=k[i];l++)
			{
				if(j==l) continue;
				dp[a[i][j]][a[i][l]]=t[i][j]+t[i][l];
			}
		}
	}
	for(int i=1;i<=m;i++)
	{
		for(int l=1;l<=m;l++)
		{
			if(i==l) continue;
			for(int j=1;j<=m;j++)
			{
				if(i==j||l==j) continue;
				if(dp[i][l]+dp[l][j]<dp[i][j])
				{
					dp[i][j]=dp[i][l]+dp[l][j];
				}
			}
		}
	}
	while(q--)
	{
		int s,t;
		s=read();t=read();
		cout<<dp[s][t]+w[s]+w[t]<<endl;
	}
	return 0;
}

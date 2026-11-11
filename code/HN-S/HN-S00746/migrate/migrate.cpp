#include<bits/stdc++.h>
//#include<bits/extc++.h>
#define int long long
#define double long double
#define unsigned unsigned int
using namespace std;
//using namespace __gnu_cxx;
//using namespace __gnu_pbds;
int t,n,m,d,now,ans,w[2000005],dp[1005][1005],dis[1005][1005];
int read()
{
	int x=0,op=1;
	char c=getchar();
	while(c<'0'||c>'9')
	{
		if(c=='-')op=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9')
	{
		x=(x<<1)+(x<<3)+(c^48);
		c=getchar();
	}
	return x*op;
}
void write(int x)
{
	if(x<0)
	{
		x*=-1;
		putchar('-');
	}
	if(x>=10)write(x/10);
	putchar(x%10+'0');
	return;
}
signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	now=read(),t=read();
	while(t--)
	{
		n=read(),d=read();ans=0;
		for(int i=1;i<=n;i++)
			w[i]=read();
		if(d==1)
		{
			write(0);
			putchar('\n');
			continue;
		}
//		if(now==11||now==12)
//		{
//			int siz=w[2]-w[1];
//			int res=d/siz*2-1;
//			ans=max(0ll,n-res);
//			write(ans);
//			putchar('\n');
//			continue;
//		}
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
			{
				dp[i][j]=0;
				dis[i][j]=2e18;
			}
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				if(abs(w[i]-w[j])<=d)
				{
					dp[i][j]=1;
					dis[i][j]=1;
				}
		for(int i=1;i<=n;i++)
		{
			dp[i][i]=1;
			dis[i][i]=0;
		}
		for(int k=1;k<=n;k++)
			for(int i=1;i<k;i++)
				for(int j=k+1;j<=n;j++)
				{
					int len=dis[i][k]+dis[k][j];
					if(len==dis[i][j])
						dp[i][j]+=dp[i][k]*dp[k][j];
					else if(len<dis[i][j])
					{
						dis[i][j]=len;
						dp[i][j]=dp[i][k]*dp[k][j];
					}
				}
		for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++)
				if(dp[i][j]==2)
					ans++;
		write(ans);
		putchar('\n');
	}
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
long long c,T,n,d,a[2004],dp[2004][2004],w[2004][2004],ans=0;
long long read()
{
	long long x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9')
	{
		if(ch=='-')
		{
			f=-1;
			ch=getchar();
			break;
		}
	}
	while(ch>='0'&&ch<='9')
	{
		x=x*10+(ch-'0');
		ch=getchar();
	}
	return x*f;
}
void dfs(long long st,long long x,long long dis)
{
	if(dis<w[st][x])
	{
		w[st][x]=dis;
		dp[st][x]=1;
	}
	else if(dis==w[st][x])
	{
		dp[st][x]++;
	}
	for(long long i=x+1;i<=n;i++)
	{
		if(a[i]-a[x]<=d) dfs(st,i,dis+1);
	}
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	c=read();
	T=read();
	while(T--)
	{
		n=read();
		d=read();
		ans=0;
		memset(a,0,sizeof(a));
		memset(dp,0,sizeof(dp));
		memset(w,0x3f3f3f,sizeof(w));
		for(long long i=1;i<=n;i++)
		{
			a[i]=read();
		}
		for(long long i=1;i<=n;i++)
		{
			dfs(i,i,0);
		}
		for(long long i=1;i<n;i++)
		{
			for(long long j=i+1;j<=n;j++)
			{ 
				if(dp[i][j]==2)
				{
					ans++;
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}

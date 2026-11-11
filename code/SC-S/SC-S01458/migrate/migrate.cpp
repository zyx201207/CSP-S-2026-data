#include<bits/stdc++.h>
using namespace std;
int c,t,n,ans,now,m=200000000;
long long d,x,prex,len[2000005],nlen;
void dfs(int a,int b,int mf)
{
	if(a==b)
	{
		if(mf<m)
		{
			m=mf;
			now=1;
			return;
		}
		if(mf==m)now++;
		return;
	}
	for(int i=a+1;i<=b;i++)
	{
		if(len[i]-len[a]<=d)dfs(i,b,mf+1);
	}
	return;
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%d%d",&c,&t);
	while(t--)
	{
		ans=0;
		scanf("%d%lld",&n,&d);
		scanf("%lld",&prex);
		for(int i=2;i<=n;i++)
		{
			scanf("%lld",&x);
			nlen=x-prex;
			len[i]=len[i-1]+nlen;
			prex=x;
		}
		for(int i=1;i<n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				now=0;
				m=200000000;
				dfs(i,j,0);
				if(now==2)ans++;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
} 
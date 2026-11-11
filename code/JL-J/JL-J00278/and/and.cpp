#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,ans=0,top=0,mx=0;
int a[200005][35],cnt[35],vis[200005],x[200005],s[200005];
signed main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&x[i]);
		mx=max(mx,x[i]);
		for(int j=0;j<=31;j++)
		{
			a[i][j]=((x[i]>>j)&1ll);
			if(a[i][j]==1)
			{
				cnt[j]++;
			}
		}
	}
	if(m==1)
	{
		printf("%lld",mx);
		return 0;
	}
	for(int j=31;j>=0;j--)
	{
		for(int i=1;i<=n;i++)
		{		
			if(vis[i]&&(a[i][j]==1))
			{
				cnt[j]--;
			}
		}
		if(cnt[j]!=0)
		{
			for(int i=1;i<=n;i++)
			{
				if(a[i][j]==0&&!vis[i])
				{
					vis[i]=1;
					s[++top]=i;
				}
			}
		}
	}
	ans=(1ll<<30)-1;
	for(int i=1;i<=n;i++)
	{
		if(!vis[i])
		{
			s[++top]=i;
		}
	}
	for(int i=top-m+1;i<=top;i++)
	{
		ans&=x[s[i]];
	}
	printf("%lld",ans);
	return 0;
}
#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll read()
{
	ll ret=0;
	ll pos=1;
	char c=getchar();
	while(!isdigit(c)&&c!='-') c=getchar();
	if(c=='-')
	{
		pos=-1;
		c=getchar();
	}
	while(isdigit(c))
	{
		ret=ret*10+(c-'0');
		c=getchar();
	}
	return ret*pos;
}
const int N=2000010;
int n;
ll d;
ll x[N];
ll s[N];
ll dp[N];
ll cnt[N];
int main()
{
	freopen("migrate.in","r",stdin);//Oct31==Dec25?
	freopen("migrate.out","w",stdout);
	int c=read();
	int t=read();
	while(t--)
	{
		scanf("%d",&n);
		d=read();
		x[1]=read();
		s[1]=0;
		for(int i=2;i<=n;i++)
		{
			x[i]=read();
			s[i]=s[i-1]+(x[i]-x[i-1]);
		}
		long long ans=0;
		for(int i=1;i<n;i++)
		{
			memset(dp,0x3f,sizeof(dp));
			memset(cnt,0,sizeof(cnt));
			dp[i]=0;cnt[i]=1;
			for(int j=i+1;j<=n;j++)
			{
				for(int k=j-1;k>=i;k--)
				{
					long long dis=s[j]-s[k];
					if(dis>d) break;
					if(dp[k]+1==dp[j])
					{
						cnt[j]+=cnt[k];
					}
					if(dp[k]+1<dp[j])
					{
						dp[j]=dp[k]+1;
						cnt[j]=cnt[k];
					}
				}
				if(cnt[j]==2) ans++;
			}
		}
		printf("%lld",ans);
		if(t) printf("\n");
	}
	
	fclose(stdin);
	fclose(stdout);
	
	return 0;
}

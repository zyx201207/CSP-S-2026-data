#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e6+5;
ll a[N],sum[N],dp[N],ans;
int lr[N][2];
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int c,t;
	cin>>c>>t;
	while(t--)
	{
		int n;
		ll d;
		ans=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++) cin>>a[i];
		for(int i=1;i<=n;i++)
		{
			lr[i][0]=min(lower_bound(a,a+i+1,a[i]-d)-a,1ll*n);
			lr[i][1]=min(lower_bound(a+i,a+n+1,a[i]+d)-a,1ll*n);
		}
		for(int i=1;i<=n;i++)
		{
			if(lr[i][0]==i) break;
			int pp=lr[i][0],p=lr[lr[i][0]][0];
			sum[i]=1;
			for(int j=i-1;j>=lr[i][0];j--)
				sum[j]=sum[j+1]+1;
			for(int j=lr[i][0]-1;j>=1;j--)
			{
				if(lr[j][0]==j) break;
				if(lr[j][1]>=pp)
				{
					ll t=sum[pp]-sum[lr[j][1]+1];
					sum[j]=sum[j+1]+t;
					if(t==2) dp[i]++;
				}
				if(j==p)
				{
					pp=p;
					p=lr[j][0];
				}
			}
			for(int j=1;j<=i;j++) sum[j]=0;
		}
		for(int i=1;i<=n;i++) ans+=dp[i];
		cout<<ans<<'\n';
		for(int i=1;i<=n;i++)
		{
			dp[i]=a[i]=0;
			lr[i][0]=lr[i][1]=0;
		}
	}
	return 0;
}
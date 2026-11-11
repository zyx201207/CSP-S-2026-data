#include<bits/stdc++.h>//48
#define LL long long
using namespace std;
const LL N=2000020;
LL a[N],dis[N],dp[N],t[N];
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	LL C,T;
	cin>>C>>T;
	while (T--)
	{
		LL i,j;
		LL n,k;
		cin>>n>>k;
		for (i=1;i<=n;i++) cin>>a[i];
		LL ans=0;
		bool flag=false;
		for (i=n;i>=1;i--)
		{
			for (j=1;j<=n;j++) dis[j]=1e18,dp[j]=0,t[j]=0;
			dis[i]=0;dp[i]=1;t[0]=1;
			LL o=i;
			for (j=i-1;j>=1;j--)
			{
				while (a[o]-a[j]>k) t[dis[o]]-=dp[o],o--;
				if (o==j) break;
				dis[j]=dis[o]+1;
				dp[j]=t[dis[o]];
				t[dis[j]]+=dp[j];
				ans+=(dp[j]==2);
			}
			if (C==11||C==12)
			{
				flag=true;
				LL cnt=0;
				for (j=1;j<=n;j++) if (dp[j]==2) cnt+=j;
				cout<<cnt<<"\n";
				break;
			}
		}
		if (!flag) cout<<ans<<"\n";
	}
	return 0;
}


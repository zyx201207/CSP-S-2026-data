#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e6+10;
int c,T,n,d,a[N],dp[N],cnt[N],tong[N],st,ans;
signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>c>>T;
	while(T--)
	{
		cin>>n>>d;
		for(int i=1;i<=n;i++)
			cin>>a[i];
		for(int i=1;i<n;i++)
		{
			for(int j=1;j<=n;j++)
				dp[j]=cnt[j]=tong[j]=0;
			cnt[i]=1;
			st=i;
			tong[0]=1;
			for(int j=i+1;j<=n;j++)
			{
				while(a[st]+d<a[j])
				{
					tong[dp[st]]-=cnt[st];
					st++;
				}
				if(st==j)
					break;
				dp[j]=dp[st]+1;
				cnt[j]=tong[dp[st]];
				tong[dp[j]]+=cnt[j];
				if(cnt[j]==2)
					ans++;
			}
		}
		for(int i=0;i<=n;i++)
			a[i]=dp[i]=cnt[i]=tong[i]=0;
		cout<<ans<<"\n";
		ans=0;
	}
	return 0;
}

#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=305;
int c,t,n,d,ans,a[N],pre[N],dp[N][N];
signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--)
	{
		cin>>n>>d;
		ans=0;
		for(int i=1;i<=n;++i) cin>>a[i];
		for(int i=1;i<=n;++i)
		for(int j=1;j<=n;++j)
		if(a[i]-a[j]<=d)
		{
			pre[i]=j;
			break;
		}
		for(int i=1;i<=n;++i)
		{
			for(int j=1;j<=n;++j)
			for(int k=0;k<=n;++k) dp[j][k]=0;
			dp[i][0]=1;
			for(int j=i+1;j<=n;++j)
			for(int k=1;k<=n;++k)
			{
				int flag=0;
				for(int l=pre[j];l<=j-1;++l)
				{
					dp[j][k]+=dp[l][k-1];
					if(dp[l][k-1]) flag=1;
				}
				if(flag) break;
			}
			for(int j=1;j<=n;++j)
			{
				int id=0;
				for(int k=1;k<=n;++k)
				if(dp[j][k])
				{
					id=k;
					break;
				}
				if(dp[j][id]==2) ans++;
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
/*
0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6
*/

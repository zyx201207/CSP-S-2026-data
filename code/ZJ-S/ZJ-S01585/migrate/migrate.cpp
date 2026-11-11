#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e6+10;
int a[N],f[N],dp[N],s[N];
void solve()
{
	int n,d,ans=0;
	cin>>n>>d;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		dp[i]=s[i]=0;
	}
	for(int k=1;k<=n;k++)
	{
		for(int i=1;i<=n;i++)
		{
			dp[i]=s[i]=0;
		}
		dp[k]=1;
		for(int i=k+1,l=k;i<=n;i++)
		{
			while(abs(a[i]-a[l])>d)
			{
				l++;
			}
			int minn=1e9;
			for(int j=l;j<i;j++)
			{
				minn=min(minn,s[j]);
			}
			for(int j=l;j<i;j++)
			{
				if(minn==s[j])
				{
					dp[i]+=dp[j];
				}
			}
			s[i]=minn+1;
			ans+=(dp[i]==2);
		}
	}

	cout<<ans<<'\n';
}
signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,T;
	cin>>c>>T;
	while(T--)
	{
		solve();
	}
	return 0;
}


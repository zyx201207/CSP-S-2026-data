#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e6+5;
int c,t;
int a[N];
int dp[3005][3005];
int cnt[3005][3005];
int n,d;
void init()
{
	for(int i=0;i<=n;i++)
	{
		a[i]=0;
	}
	if(c!=11&&c!=12)
	{
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
			{
				if(i==j)
					dp[i][j]=0;
				dp[i][j]=1e18; 
			}
	}
}
void solve()
{
	init();
	cin>>n>>d;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	if(c==11||c==12)
	{
		int s=a[2]-a[1];
		int k=d/s;
		int sum=0;
		if(k<=1||n-2*k+1<=0)
		{
			cout<<0<<"\n";
			return;
		}
		cout<<n-k-k+1<<"\n";
		return;
	}
	for(int i=1;i<=n;i++)
	{
		int r=i+1;
		while(a[r]-a[i]<=d&&r<=n)
		{
			dp[i][r]=1;
			cnt[i][r]=1;
			r++;
		}
	}
	int ans=0;
	for(int ii=1;ii<=n;ii++)
	{
		for(int jj=1;jj+ii<=n;jj++)
		{
			int j=ii+jj;
			int i=jj;
			if(dp[i][j]!=1)
				dp[i][j]=1e18;
			for(int k=i+1;k<j;k++)
			{
//				cout<<i<<" "<<j<<" "<<k<<":"<<" "<<dp[i][j]<<" "<<dp[i][k]<<" "<<dp[k][j]<<"\n";
				if(dp[i][j]==dp[i][k]+dp[k][j])
					cnt[i][j]++;
				else if(dp[i][j]>dp[i][k]+dp[k][j])
				{
					dp[i][j]=dp[i][k]+dp[k][j];
					cnt[i][j]=cnt[i][k]*cnt[k][j];
				}
			} 
//			cout<<i<<" "<<j<<":"<<dp[i][j]<<"\n";
			if(cnt[i][j]==2)
				ans++;
		}
	}
	cout<<ans<<"\n";
}
signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>t;
	while(t--)
		solve(); 
	return 0;
} 
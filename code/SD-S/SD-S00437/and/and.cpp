#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=500000+10;
int a[N],dp[N];
void solve_problems()
{
	int n,m,sum=-1,maxx=-0x3f3f3f3f3f3f3f3f;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		maxx=max(maxx,a[i]);
		sum=(sum&a[i]);
	}
	if(n==1)
	{
		cout<<maxx;
		return ;
	}
	else if(m==n)
	{
		cout<<sum;
		return ;
	}
	memset(dp,0,sizeof(dp));
	dp[0]=-1;
	for(int i=1;i<=n;i++)
	{
		for(int j=m;j>=1;j--)
		{
			dp[j]=max(dp[j],(dp[j-1]&a[i]));
		}
	}
	cout<<dp[m];
}
signed main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int T=1;
//	cin>>T;
	for(int t=1;t<=T;t++)
	{
		solve_problems();
	}
	return 0;
}

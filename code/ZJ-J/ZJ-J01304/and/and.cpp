#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,ans,a[200005],dp[200005];
bool bmp(int a,int b)
{
	return a>b;
}
signed main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+1+n,bmp);
	ans=a[1];
	for(int i=2;i<=m;i++)
		ans=ans&a[i];
	if(n*m<=80000000)
	{
		dp[1]=a[1];
		for(int i=2;i<=n;i++)
			for(int j=m;j>=1;j--)
				dp[j]=max(dp[j],dp[j-1]&a[i]);
		ans=max(ans,dp[m]);
	}
	cout<<ans;
	return 0;
}
#include<bits/stdc++.h>
using namespace std;
int n,m,a[300000],dp[300000];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	memset(dp,0x80808080,sizeof(dp));
	for(int i=1;i<=n;i++)
		for(int j=m;j>=1;j--)
		{
			if(j==1) dp[j]=max(dp[j],a[i]);
			else dp[j]=max(dp[j],dp[j-1]&a[i]);
		}
	cout<<dp[m]<<endl;
	return 0;
}

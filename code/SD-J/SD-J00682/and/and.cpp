#include<bits/stdc++.h>
using namespace std;
long long dp[200010];
long long a[200010];
int n,m;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	int t;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		dp[1]=max(dp[i],a[i]);
		if(a[i]>dp[1])
		{
			t=i;
		}
	}
	a[t]=0;
	for(int i=1;i<=m;i++)
	{
		int r;
		for(int j=1;j<=n;j++)
		{
			if(dp[i]<dp[i-1] & a[j])
			{
				r=j;
			}
			dp[i]=max(dp[i],dp[i-1] & a[j]);
			
		}
		a[r]=0;
		//cout<<dp[i]<<endl;
	}
	cout<<dp[m];
	return 0;
}

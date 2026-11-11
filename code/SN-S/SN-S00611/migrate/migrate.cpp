//SN-S00611
//¶­¹ú¶°
#include<bits/stdc++.h>
using namespace std;
int c,T;
long long n,d;
long long a[2000005];
long long dp[5005][5005];
int mian()
{
	cin>>n>>d;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	memset(dp,0,sizeof dp);
	for(int i=1;i<=n;i++)
		dp[i][i]=1;
	for(int k=1;k<=n;k++)
		for(int u=1;u<=n;u++)
			for(int v=1;v<=n;v++)
				if(abs(a[k]-a[v])<=d)
					dp[v][u]+=dp[u][k];
	long long ans=0;
	for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++)
			ans+=(dp[i][j]/2==2);
	cout<<ans<<endl;
	return 0;
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c;cin>>T;
	while(T--)
		mian();
	return 0;
}

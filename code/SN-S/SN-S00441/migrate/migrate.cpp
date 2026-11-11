// 门可铭 辅轮中学 SN-S00441
#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,minn[5010][5010],d,x[5010],dp[5010][5010],ans;
void solve()
{
	ans=0;
	cin>>n>>d;
	for(int i=1;i<=n;i++) cin>>x[i];
	for(int i=1;i<=n;i++)
	for(int j=1;j<=n;j++) minn[i][j]=(abs(x[i]-x[j])<=d?1:1e16L);
	for(int k=1;k<=n;k++)
	for(int i=1;i<=n;i++)
	for(int j=1;j<=n;j++) {minn[i][j]=min(minn[i][j],minn[i][k]+minn[k][j]);}
//	for(int i=1;i<=n;i++)
//	for(int j=1;j<=n;j++) cerr<<i<<" "<<j<<" "<<minn[i][j]<<'\n';
	for(int l=1;l<=n;l++)
	for(int i=1;i+l-1<=n;i++)
	{
		int r=i+l-1;
		int sum=(x[r]-x[i]<=d);
		for(int k=i+1;k<r;k++)
		{
			if(minn[i][k]+minn[k][r]==minn[i][r])
			{
				sum+=dp[i][k]*dp[k][r];
			}
		}
		if(sum>2) sum=3;
		dp[i][r]=sum;
		if(sum==2) ans++;
//		cerr<<i<<" "<<r<<" "<<dp[i][r]<<'\n';
	}
	cout<<ans<<'\n';
	return;
}
signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,T=1;
	cin>>c>>T;
	while(T--) solve();
	return 0;
}

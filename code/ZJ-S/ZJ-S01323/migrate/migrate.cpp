#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e6+5;
int c,T,n,pos[N];
ll d,x[N],ans,dp[N][2];
inline void solve()
{
	cin>>n>>d;
	for(int i=1;i<=n;i++)cin>>x[i];
	dp[1][0]=1;
	for(int i=2,j=1;i<=n;i++)
	{
		while(j<i&&x[i]-x[j]>d)j++;
		pos[i]=j;
		dp[i][1]=dp[pos[i]][1];
		dp[i][0]=dp[pos[i]][0]+1;
		if(pos[i]==i)continue;
		if(pos[i]+1<i&&pos[pos[i]+1]!=pos[i])
		{
			if(pos[i]+2<i&&pos[pos[i]+2]<=pos[pos[i]+1])continue;
			dp[i][1]+=dp[pos[pos[i]+1]][0];
			if(pos[pos[pos[i]+1]]!=pos[pos[i]+1]&&pos[pos[pos[i]+1]]==pos[pos[i]])dp[i][1]--;
		}
	}
//	for(int i=1;i<=n;i++)cout<<pos[i]<<' ';
//	cout<<'\n';
//	for(int i=1;i<=n;i++)cout<<dp[i][0]<<' '<<dp[i][1]<<'\n';
//	cout<<'\n';
	ans=0;
	for(int i=1;i<=n;i++)ans+=dp[i][1];
	cout<<ans<<'\n';
	for(int i=1;i<=n;i++)dp[i][0]=dp[i][1]=pos[i]=0;
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>T;
	while(T--)solve();
	return 0;
}
#include<bits/stdc++.h>
#define int long long 
using namespace std;
const int N=5e5+5,M=5005,inf=1e18+1;
int n,m;
int a[N],dp[M][M],cnt[M][M];
int c;
void solve()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	if(c==11||c==12)
	{
		int x=a[2]-a[1];
		if(x*2==m) cout<<n*(n-1)/2<<endl;
		else cout<<0<<endl;
		return ;
	}
	if(c==13||c==14)
	{
		cout<<(n-1)*n/2<<endl;
		return ;
	}
	for(int i=0;i<=n;i++) for(int j=0;j<=n;j++) dp[i][j]=inf,cnt[i][j]=0;
	for(int i=1;i<=n;i++) if(a[i]-a[i-1]<m) dp[i-1][i]=1,cnt[i-1][i]=1;
	for(int len=2;len<=n;len++)
	{
		for(int i=1;i+len-1<=n;i++)
		{
//			bool flag=1;
//			for(int j=i+1;j<=i+len-1;j++)
//			{
//				if(a[j]-a[j-1]>m) 
//				{
//					flag=0;
//					break;
//				}	
//			} 
//			if(!flag) continue;
			if(a[i+len-1]-a[i]<=m) 
			{
				dp[i][i+len-1]=1;
				cnt[i][i+len-1]=1;
				continue;
			}
			
			for(int j=i+1;j<=i+len-1;j++)
			{
				if(a[j]-a[j-1]>m) break;
				int now=min(dp[i][i+len-1],dp[i][j]+dp[j+1][j+len-1]);
				if(now==dp[i][i+len-1]) cnt[i][i+len-1]++;
				else if(now<dp[i][i+len-1]) cnt[i][i+len-1]=0;
				dp[i][i+len-1]=now;
//				cout<<i<<" "<<i+len-1<<" "<<cnt[i][i+len-1]<<" "<<dp[i][i+len-1]<<endl;
			} 
		}
//		for(int i=1;i<=n;i++) 
//		{
//			for(int j=1;j<=n;j++) cout<<cnt[i][j]<<" ";
//			cout<<endl;
//		}
//		cout<<endl;
	}
	int ans=0;
	for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) if(cnt[i][j]==2) ans++;
	cout<<ans<<endl; 
}

signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int T;
	cin>>c;
	cin>>T;
	while(T--) solve(); 
	return 0;
}
//15:09  AC T1

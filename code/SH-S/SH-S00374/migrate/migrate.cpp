#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=305;
int C,t,dp[N][N],dis[N][N];
ll x[N];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>C>>t;
	while(t--)
	{
		memset(dis,0x3f,sizeof(dis));
		memset(dp,0,sizeof(dp));
		int n,ans=0;
		ll d;
		cin>>n>>d;
		for(int i=1;i<=n;i++)
		{
			cin>>x[i];
			if(i==1) continue;
			if(x[i]-x[i-1]<=d) dis[i-1][i]=1,dp[i-1][i]=1;
		}
		for(int len=3;len<=n;len++)
		{
			for(int i=1;i+len-1<=n;i++)
			{
				int j=i+len-1;
				if(x[j]-x[i]<=d)
				{
					dp[i][j]=1,dis[i][j]=1;
					continue;
				}
				for(int k=i+1;k<j;k++)
				{
					int tmp=dis[i][k]+dis[k][j];
					if(tmp==dis[i][j]) dp[i][j]++;
					else if(tmp<dis[i][j]) dp[i][j]=1,dis[i][j]=tmp;
				}
			}
		}
		for(int len=2;len<=n;len++)
		{
			for(int i=1;i+len-1<=n;i++)
			{
				int j=i+len-1;
				if(dp[i][j]==2) ans++;
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}

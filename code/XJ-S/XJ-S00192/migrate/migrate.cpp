#include <bits/stdc++.h>
#define ll long long

using namespace std;

ll n,m;
ll x[2000010];
ll dp[2000010];
int cnt;

int main()
{
	
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	
	int c,t;
	cin>>c>>t;
	while(t--)
	{
		cin>>n>>m;
		for(ll i = 1;i<=n;i++)
		{
			cin>>x[i];
		}
		ll cnt = 0;
		for(ll i = 1;i<n;i++)
		{
			for(ll j = 1;j<=n;j++)
			{
				dp[j] = 0;
			}
			dp[i] = 1;
			for(ll j = i+1;j<=n;j++)
			{
				ll xx = x[j]-m;
				ll jj = j-1;
				while(x[jj]>=xx)
				{
					dp[j] += dp[jj];
					jj--;
				}
				if(dp[j]==3&&j>i+2) cnt++;
//				if(dp[j]>3) break;
			}
			
//			for(int j = 1;j<=n;j++)
//			{
//				cout<<dp[j]<<" ";
//			}
//			cout<<endl;
			
		}
		cout<<cnt<<endl;
	}
	
	return 0;
}

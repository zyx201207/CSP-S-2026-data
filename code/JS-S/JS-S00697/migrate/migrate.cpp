#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define i128 __int128
#define F first
#define S second

const ll INF=2e18+1e10;
ll C,T,n,d;

int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin>>C>>T;
	while(T--)
	{
		if(C==11||C==12)
		{
			ll ans=0;
			cin>>n>>d;
			vector<ll> a(n);
			for(auto&x:a)
			{
				cin>>x;
			}
			sort(a.begin(),a.end());
			if(n!=1&&(a[1]-a[0])*2<=d&&(a[1]-a[0])*3>d)
			{
				ans=n*(n-1)/2;
			}
			cout<<ans<<'\n';
		}else
		{
			ll ans=0;
			cin>>n>>d;
			vector<ll> a(n);
			for(auto&x:a)
			{
				cin>>x;
			}
			sort(a.begin(),a.end());
			vector<vector<pair<ll,ll>>> dp(n,vector<pair<ll,ll>>(n,{0,1}));
			for(ll l=1;l<n;l++)
			{
				for(ll i=0;i+l<n;i++)
				{
					ll j=i+l;
					dp[i][j]={INF,0};
					for(ll k=i;k<j;k++)
					{
						if(a[j]-a[k]<=d)
						{
							if(dp[i][j].F==dp[i][k].F+1)
							{
								dp[i][j].S+=dp[i][k].S;
							}else if(dp[i][j].F>dp[i][k].F+1)
							{
								dp[i][j]={dp[i][k].F+1,dp[i][k].S};
							}
						}
					}
					if(dp[i][j].F<INF&&dp[i][j].S==2)
					{
						ans++;
					}
				}
			}
			cout<<ans<<'\n';
		}
	}
	return 0;
}

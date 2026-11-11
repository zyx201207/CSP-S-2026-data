#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll c,t;
bool hasland[20001]={false};
ll dp[20001][20001];
ll land[20001];
int main()
{
	ios::sync_with_stdio(false);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--)
	{
		ll n,d;
		cin>>n>>d;
		ll ans=0;
        for(ll i=1;i<=20000;++i)
        {
        	for(ll j=1;j<=20000;++j)
        	    dp[i][j]=0;
		}
		for(ll j=1;j<=20000;++j)
		    hasland[j]=false;
		for(ll i=1;i<=n;++i)
		{
			cin>>land[i];
			hasland[land[i]]=true;
		}
		for(ll i=1;i<=20000;++i)
		{
			for(ll j=1;j<=20000;++j)
			{
				if(j<=d)
				{
					dp[i][i+j]=1;
				}
			}
		}
		for(ll i=1;i<=20000;++i)
		{
			for(ll j=1;j<=20000;++j)
			{
				for(ll k=d;k>=1;--k)
				{
					if(i+j-k>=1&&hasland[land[i+j]-k])
					{
						ll index;
						for(ll m=i+j-1;m>=1;--m)
						{
							if(land[i+j]-land[m]==k)
							{
							    index=m;
							    break;
						    }
						}
						dp[i][i+j]=dp[i][index]+1;
					}	   
				}
				if(dp[i][i+j]==2)
				    ans++;
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}

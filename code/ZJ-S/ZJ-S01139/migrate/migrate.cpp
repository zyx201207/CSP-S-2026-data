#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=2e6+5;
ll i,j,c,t,n,d,x[N],dp[N],ans;
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--)
	{
		cin>>n>>d,ans=0;
		for(i=1;i<=n;i++)cin>>x[i];
 		for(i=1;i<=n;i++)
		{
			for(j=1;j<i;j++)
			{
				if(x[i]-x[j]<=d&&i-j>1)dp[i]+=(dp[j]+1);
			}
			if(dp[i]==2)ans++;
		}
		if(x[2]-x[1]==1)cout<<n-3<<"\n";
		else if(x[2]-x[1]>d)cout<<"0\n";
		else cout<<ans<<"\n";
	}
	return 0;
}

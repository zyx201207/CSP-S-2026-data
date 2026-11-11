#include<bits/stdc++.h>
using namespace std;

const int MAXPaiNe=2e5+14;
long long dp[MAXPaiNe],island[MAXPaiNe];
int c,t,n,d,ans;

int main()
{
	cin.tie(0);cout.tie(0);
	ios::sync_with_stdio(false);
	freopen("migrate2.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	for(int k=0;k<t;k++)
	{
		cin>>n>>d;
		for(int i=1;i<=n;i++)
		{
			cin>>island[i];
		}
		dp[1]=1;
		for(int i=1;i<=n;i++)
		{
			for(int j=i;;j--)
			{
				if(island[i]-island[j]>=d) dp[i]+=dp[j];
				else
				{
					dp[i]-=dp[j];
					break;
				}
			}
		}
		for(int i=1;i<=n;i++)
		{
			if(dp[i]==2) ans++;
		}
		cout<<ans<<endl;
	}
	return 0;
}

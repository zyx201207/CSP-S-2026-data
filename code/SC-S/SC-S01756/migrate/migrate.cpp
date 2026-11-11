#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
#define int long long
int a[2000005],z[2000005];
unsigned long long dp[2000005],dpp[2000005];
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int o,t;
	cin>>o>>t;
	while(t--)
	{
		memset(z,0,sizeof(z));
		memset(dpp,0,sizeof(dpp));
		int n;
		unsigned long long m;
		cin>>n>>m;
		int l=1;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
			while(a[i]-a[l]>m)
			{
				l++;
			}
			z[i]=l;
		}
		unsigned long long cnt=0;
		for(int k=1;k<=n;k++)
		{
			memset(dp,0,sizeof(dp));
			memset(dpp,0,sizeof(dpp));
			dpp[k]=dp[k]=1;
			bool is=1;
			while(!dp[n]&&is)
			{
				is=0;
				for(int i=k+1;i<=n;i++)
					dpp[i]=dp[i]+dpp[i-1];
				for(int i=n;i>=k;i--)
				{
					if(dp[i])
						break;
					dp[i]=dpp[i-1]-dpp[z[i]-1];
					if(dp[i])
						is=1;
				}
			}
			for(int i=k;i<=n;i++)
				if(dp[i]==2)
					cnt++;
		}
		cout<<cnt<<endl;
	}
	
} 
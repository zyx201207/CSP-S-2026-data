#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll inf=0x3f3f3f3f3f3f3f3fLL;
void f()
{
	ll n,d;
	cin>>n>>d;
	vector<ll> x(n);
	for (int i=0;i<n;i++) cin>>x[i];
	vector<vector<ll> > dp(n,vector<ll>(n,inf)),kind(n,vector<ll>(n,0));
	for (int i=0;i<n;i++)
	{
		dp[i][i]=0;
		kind[i][i]=1;
	}
	int ans=0;
	for (int i=0;i<n;i++)
	{
		for (int j=i+1;j<n;j++)
		{
			int cnt=0;
			for (int k=i;k<j;k++)
			{
				if (x[j]-x[k]>d) continue;
				ll tmp=dp[i][k]+1;
				if (tmp==dp[i][j]&&i!=k) cnt+=kind[i][k];
				if (tmp<dp[i][j])
				{
					dp[i][j]=tmp;
					cnt=kind[i][k];
				}
			}
			kind[i][j]=cnt;
			ans+=cnt==2;
		}
	}
	cout<<ans<<'\n';
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while (t--) f();
	return 0;
}

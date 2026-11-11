#include<bits/stdc++.h>
#define ll long long
#define db double
const int N=1e6+10,inf=0x3f3f3f3f;
using namespace std;
int dp[110][110],a[N];
void solve()
{
	int n,d,ans;
	cin>>n>>d;
	for(int i=1;i<=n;i++)
		cin>>ans;
	if(ans>d)
	{
		cout<<0;
		return ;
	}
	
}
void solve2()
{
	int n,d;
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	memset(dp,inf,sizeof(dp));
	
	for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++)
		{
			if(a[i]+d>=a[j])
				dp[i][j]=dp[i][j];
		}
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int c,t;
	cin>>c>>t;
	while(t--)
	{
		if(c>=13&&c<=14)
			solve();
	}
	
}

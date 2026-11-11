#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+5;
int c,t,n,d;
int x[N],dp[N];

signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>c>>t;
	while(t--)
	{
		int n,d;
		cin>>n>>d;
		for(int i=1;i<=n;i++) cin>>x[i];
		dp[1]=1;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=i-d;j++)
			{
				dp[i]+=dp[j];
			}
		}
		cout<<dp[n];
	}
	return 0;
}

//0 1
//4 2
//1 2 3 4
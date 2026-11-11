#include <bits/stdc++.h>
using namespace std;
int a[2000050];
int dp[2000050];
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--)
	{
		int n,d,ans=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
			int l=1,r=n;
			int co;
			while(l<r)
			{
				int mid=l/2+r/2;
				if(a[mid]<=a[i]-d)
				{
					l=mid+1;
					co=mid;
				}else
				{
					r=mid-1;
				}

			}
				for(int j=co;j<=i-1;j++)
				{
					dp[i]++;
				}
				if(dp[i]-dp[i-2]==2)
				{
					ans++;
				}
		}
		cout<<ans<<endl;;
	}

	return 0;
}

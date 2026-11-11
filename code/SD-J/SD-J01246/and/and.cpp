#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[2005],dp[2005][2005];
signed main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	if(m==1)cout<<a[n];
	if(m==n)
	{
		int ans=a[1];
		for(int i=2;i<=n;i++)ans=ans&a[i];
		cout<<ans;
	}
	if(m==2)
	{
		int ans=0;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
			{
				if(i==j)continue;
				ans=max(ans,a[i]&a[j]);
				//cout<<a[i]<<" "<<a[j]<<endl;
			}
		cout<<ans;
	}
	return 0;
}


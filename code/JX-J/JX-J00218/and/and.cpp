#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200050],dp[200050];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    if(m==1)
	{	
		cout<<0;
		return 0;
	}
	if(m==2)
	{
		long long maxx=0;
		for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++)
				maxx=max(maxx,a[i]&a[j]);
		cout<<maxx;
		return 0;
	}
	if(m==n)
	{
		long long ans=a[1];
		for(int i=2;i<=n;i++)
			ans=ans&a[i];
		cout<<ans;
		return 0;
	}
	cout<<0;
    return 0;
}

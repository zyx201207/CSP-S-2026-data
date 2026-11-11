#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[500050],sum[500050];
long long ans;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)sum[i]=sum[i-1]+a[i];
	long long l=1,r=2;
	while(l<r&&r<=n&&l<=n)
	{
		if((r-l)*a[r]-(sum[r-1]-sum[l-1])<=m)
		{
			r++;
		}
		else l++;
		ans=max(ans,r-l);
	}
	cout<<ans;
	return 0;
 } 

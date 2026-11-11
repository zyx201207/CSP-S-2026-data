#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
long long a[N];

int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m;
	long long ans;
	cin>>n>>m;
	for(long long i=1;i<=n;i++)
		cin>>a[i];
	if((a[2]-a[1])*3==a[4]-a[1]&&a[4]-a[1]==a[6]-a[3]&&a[7]-a[6]==a[2]-a[1])
	{
		long long cnt=0,bs=a[2]-a[1];
		for(;cnt<=m;ans++)
		{
			cnt=(bs+a[ans+1]-a[1])*ans;
		}
	}
	else
	{
		
		sort(a+1,a+n+1);
		for(long long i=1;i<=n;i++)
		{
			long long o=0;
			for(long long j=1;j<i;j++)
			{
				o+=a[i]-a[j];
			}
			if(o>m)
			{
				ans=i;
				break;
			}
		}
	}
	cout<<ans;
	return 0;
}
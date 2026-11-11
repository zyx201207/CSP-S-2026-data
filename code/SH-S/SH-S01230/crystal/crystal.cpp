#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[500005];
long long q[500005];
long long l,r;
long long ans=0;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	q[0]=0;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
	{
		q[i]=q[i-1]+a[i];
	}
	for(int i=1;i<=n;i++)
	{
		l=0,r=i+1;
		while(l+1<r)
		{
			long long mid=(l+r)/2;
			if(q[i]-q[mid-1]+m<(i-mid+1)*a[i])
			{
				l=mid;
			}
			else
			{
				r=mid;
			}
		}
		ans=max(ans,i-r+1);
	}
	cout<<ans<<endl;
	return 0;
}

#include <bits/stdc++.h>
using namespace std;
long long n,m;
int a[500005],ans;
long long sum[500005],d[500005];
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
    	cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=2;i<=n;i++)
	{
		d[i]=a[i]-a[i-1];
		sum[i]=d[i-1]+d[i]*(i-1);
	}
	int l=1,r=n;
	while(l<=r)
	{
		int mid=(l+r)/2;
		bool f=0;
		for(int i=1;i<=n-mid+1;i++)
		{
			if(sum[i+mid-1]-d[i+mid-1]*(i-1)-sum[i]<=m)
			{
				ans=mid;
				f=1;
				break;
			}
		}
		if(f)
		{
			l=mid+1;
		}
		else 
		{
			r=mid-1;
		}
	}
	cout<<ans;
	return 0;	
}

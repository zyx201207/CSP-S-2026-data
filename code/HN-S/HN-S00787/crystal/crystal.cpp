#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[500007],sum[500007],ans=0;
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)
	{
		sum[i]=a[i]+sum[i-1];
	}
	int maxi=0;
	for(int i=1;i<=n;i++)
	{
		int l=1,r=i;
		while(l<r)
		{
			int mid=(l+r)/2;
			if((i-mid+1)*a[i]-(sum[i]-sum[mid-1])>m)
			{
				l=mid+1;
			}
			else
			{
				r=mid;
			}
		}
		maxi=max(maxi,i-l+1);
	}
	cout<<maxi;
	return 0;
}

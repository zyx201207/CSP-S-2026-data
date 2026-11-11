#include<bits/stdc++.h>
using namespace std;
int n,l,r,ans;
long long m,a[500005],sc[500005];
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
	for(int i=1;i<n;i++)
	{
		sc[i+1]=sc[i]+i*(a[i+1]-a[i]);
//		cout<<sc[i]<<" ";
	}
	for(int i=1;i<=n;i++)
	{
		l=1;
		r=i;
		while(l<r)
		{
			int mid=(l+r)>>1;
			if(sc[i]-sc[mid]-(a[i]-a[mid])*(mid-1)>m)
			{
				l=mid+1;
			}
			else
			{
				r=mid;
			}
		}
		ans=max(ans,i-l+1);
	}
	cout<<ans;
	return 0;
}

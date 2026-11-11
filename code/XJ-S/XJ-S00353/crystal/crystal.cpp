#include<bits/stdc++.h>
using namespace std;
#define int long long 
int n,m,a[500005],ans,qzh[500005],hzh[500005];
int check(int x)
{
    int l=1,r=x;
    while(l<r)
    {
    	int mid=(l+r)/2;
    	if(hzh[mid]-(x-mid+1)*hzh[x]+hzh[x+1]*(x-mid)<=m)
    	{
    		r=mid;
		}
		else l=mid+1;
	}
	return x-r+1;
}
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
	{
		qzh[i]=a[n]-a[i];
	}
	for(int i=n;i>=1;i--)
	{
		hzh[i]=qzh[i]+hzh[i+1];
	}
	for(int i=1;i<=n;i++)
	{
//		cout<<1;
		ans=max(ans,check(i));
	}
	cout<<ans;
	return 0;
} 

#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;
int n;
long long m;
long long a[500005];
long long sum[500005];
int ans=0;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++) sum[i]=sum[i-1]+a[i];
	ans=0;
	for(int i=1;i<=n;i++)
	{
		int l=0,r=i-1,res=i-1;
		while(l<=r)
		{
			int mid=(l+r)/2;
			if(1ll*a[i]*(i-mid)-(sum[i]-sum[mid])<=m) res=mid,r=mid-1;
			else l=mid+1;
		}
		ans=max(ans,i-res);
	}
	cout<<ans<<endl;
	return 0;	
} 

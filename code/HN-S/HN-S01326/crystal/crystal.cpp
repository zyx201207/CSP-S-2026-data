#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[500005],ans;
bool ok(int x)
{
	int s=0,cnt=0;
	for(int i=1;i<=n;i++)
	{
		if(a[i]<=x)
		{
			s+=x-a[i];
			cnt++;
		} 
	}
	if(s>m)
		return 0;
	ans=max(ans,cnt);
	return 1;
}
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1);
	int l=a[1],r=a[n],mid;
	while(l<=r)
	{
		mid=(l+r)/2;
		if(ok(mid))
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


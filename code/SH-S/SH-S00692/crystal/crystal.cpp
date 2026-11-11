#include<bits/stdc++.h>
using namespace std;
const long long inf=2e18;
int n;
long long m,a[500005];
bool check(int mid)
{
	long long cnt=0,ans=inf;
	for(int i=1;i<=mid;i++)cnt+=(long long)abs(a[i]-a[mid]);
	ans=cnt;
	for(int i=2;i+mid-1<=n;i++)
	{
		cnt+=(long long)abs(a[i+mid-1]-a[i+mid-2])*mid-(long long)abs(a[i+mid-1]-a[i-1]);
		ans=min(ans,cnt);
	}
	return (ans<=m);
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	int l=1,r=n,ans=1;
	while(l<=r)
	{
		int mid=(l+r)>>1;
		if(check(mid))
		{
			ans=mid;
			l=mid+1;
		}
		else r=mid-1;
	}
	cout<<ans;
	return 0;
}
//RP++

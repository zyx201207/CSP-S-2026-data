#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
int a[500010],q[500010];
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)q[i]=q[i-1]+a[i];
	int l,r,mid,pos,ans=0;
	for(int i=1;i<=n;i++)
	{
		l=1;r=i;
		while(l<=r)
		{
			mid=(l+r)/2;
			pos=i-mid+1;
			if(a[i]*mid-(q[i]-q[pos-1])<=m)l=mid+1;
			else r=mid-1;
		}
		ans=max(ans,r);
	}
	cout<<ans;
	return 0;
}

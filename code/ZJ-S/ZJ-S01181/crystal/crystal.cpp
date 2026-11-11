#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[500005],b[500005],ans;
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
	  b[i]=b[i-1]+a[i];
//	for(int i=1;i<=n;i++)cout<<b[i]<<' ';
	for(int i=1;i<=n;i++)
	{
		int l=1,r=i;
		while(l<=r)
		{
			int mid=(l+r)/2;
			if(a[i]*(i-mid+1)-(b[i]-b[mid-1])<=m)r=mid-1;
			else l=mid+1;
		}
//		cout<<l<<' '<<i<<' '<<a[i]*(r-+1)endl;
		ans=max(ans,i-l+1);
	}
	cout<<ans;
	return 0;
}

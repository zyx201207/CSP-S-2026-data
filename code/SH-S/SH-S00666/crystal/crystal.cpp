#include <bits/stdc++.h>
using namespace std;
#define int long long
#define N 500010
int a[N],b[N];
signed main ()
{
//	ios::sync_with_stdio(false);
//	cin.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,t,ans=0;
	cin>>n>>t;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++) b[i]=b[i-1]+a[i];
	for(int i=1;i<=n;i++)
	{
		int l=1,r=i;
		while(l<=r)
		{
			int mid=(l+r)/2;
			int c=(i-mid+1)*a[i];
			c-=(b[i]-b[mid-1]);
			if(c<=t) r=mid-1;
			else l=mid+1;
		}
		ans=max(ans,i-l+1);
	}
	cout<<ans;
	return 0;
}


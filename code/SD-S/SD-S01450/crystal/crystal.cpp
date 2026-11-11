#include<bits/stdc++.h>
#define int long long 
using namespace std;
const int N=5e5+10;
int a[N],sum[N];
int n,m;
bool check(int x)
{
	for(int i=1;i+x-1<=n;i++)
	{
		int lst=i+x-1;
		int k=sum[lst]-sum[i-1];
		if(x*a[lst]-k<=m) return true;
	}
	return false;
}
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i]; 
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++) sum[i]=sum[i-1]+a[i];
	int l=1,r=n,ans=-1;
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
	while(ans+1<=n&&check(ans+1)) ans++;
	cout<<ans;
	return 0;
}


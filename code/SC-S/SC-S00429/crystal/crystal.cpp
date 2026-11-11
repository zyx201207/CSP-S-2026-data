#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+5;
int n,m,a[N],b[N],ans=1;
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=n;i;i--)b[i]=b[i+1]+a[n]-a[i];
	for(int i=n;i;i--)
	{
		int l=1,r=i,mid;
		while(l<r)
		{
			mid=(l+r)>>1;
			if((b[mid]-b[i+1]-(i-mid+1)*(a[n]-a[i]))<=m)r=mid;
			else l=mid+1;
		}
		ans=max(ans,i-r+1);
	}
	cout<<ans;
	return 0;
}
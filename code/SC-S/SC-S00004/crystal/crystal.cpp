#include<bits/stdc++.h>
#define int long long
using namespace std;
int p[500005],n,ans;
int a[500005],m,top;
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int i,l,r;
	cin>>n>>m;
	for(i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	l=1;
	for(i=1;i<=n;i++)p[i]=p[i-1]+a[i];
	for(i=1;i<=n;i++)
	{
		while(l<=i&&(i-l+1)*a[i]-(p[i]-p[l-1])>m)l++;
		ans=max(ans,i-l+1);
//		cout<<i<<" "<<l<<"\n";
	}
	cout<<ans<<"\n";
	return 0;
}
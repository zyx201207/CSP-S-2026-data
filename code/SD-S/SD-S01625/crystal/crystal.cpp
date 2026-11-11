#include<bits/stdc++.h>
#define endl "\n"
#define int long long
using namespace std;
int n,m,a[500005];
bool check(int x)
{
	int now=0;
	for(int i=1;i<=x;i++) now+=a[x]-a[i];
	if(now<=m) return 1;
	for(int i=x+1;i<=n;i++)
	{
		now+=(a[i]-a[i-1])*x;
		now-=a[i]-a[i-x];
		if(now<=m) return 1;
	}
	return 0;
}
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	int l=1,r=n,ans;
	while(l<=r)
	{
		int mid=(l+r)/2;
		if(check(mid)) l=mid+1,ans=mid;
		else r=mid-1;
	}
	cout<<ans;
	return 0;	
} 

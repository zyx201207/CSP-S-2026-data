#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+5;
int n;
ll m,a[N];
ll sum[N];
bool check(int mid)
{
	for(int i=mid;i<=n;i++)
		if(1ll*mid*a[i]-(sum[i]-sum[i-mid])<=m)
			return true;
	return false;
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)sum[i]=sum[i-1]+a[i];
	int l=1,r=n,mid,ans=-1;
	while(l<=r)
	{
		mid=l+r>>1;
		if(check(mid))
		{
			ans=mid;
			l=mid+1;
		}
		else	r=mid-1;
	}
	cout<<ans<<'\n';
	return 0;
}
/*
Ô¤¼Æ100 
*/

#include<iostream>
#include<algorithm>
using namespace std;
#define ll long long
const int N=5e5+5;
ll m,n;
ll ans=0;
ll a[N],s[N];
ll find(int x)
{
	ll l=1,r=x+1;
	while(l<r)
	{
		ll mid=(l+r)>>1;
		if( ((x-mid+1)*a[x]-(s[x]-s[mid-1])) <=m)
		{
			r=mid;
		}
		else l=mid+1;
	}
	return l;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
	{
		s[i]=s[i-1]+a[i];
	}
	for(ll i=1;i<=n;i++)
	{
		ll pos=find(i);
		ans=max(ans,i-pos+1);
	}
	cout<<ans;
	return 0;
 } 

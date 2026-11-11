#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e6+5;
int maxx;
ll a[N],sum[N],m;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int n;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
		sum[i]=sum[i-1]+a[i];
	for(int i=1;i<=n;i++)
	{
		int l=1,r=i;
		while(l<r)
		{
			int mid=(l+r)>>1;
			ll t=1ll*(i-mid+1)*a[i];
			if(m>=t-(sum[i]-sum[mid-1])) r=mid;
			else l=mid+1;
		}
		maxx=max(maxx,i-r+1);
	}
	cout<<maxx;
	return 0;
}
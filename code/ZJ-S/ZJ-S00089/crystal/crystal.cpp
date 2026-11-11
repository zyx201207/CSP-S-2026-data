#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e5+10;
ll n,m,a[N],maxt=0,sum[N];
bool check(int mid,int i)
{
	ll ans;
	ans=a[i]*(i-mid+1)-(sum[i]-sum[mid-1]);
	if(ans<=m) return true;
	else return false;
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++) sum[i]=sum[i-1]+a[i];
	for(int i=1;i<=n;i++)
	{
		ll l=1,r=i;
		while(l<=r)
		{
			ll mid=(l+r)/2;
			if(check(mid,i))
			{
				r=mid-1;
			}
			else l=mid+1;
		}
		ll len=i-l+1;
		maxt=max(maxt,len);
	}
	cout<<maxt;
	return 0;
}

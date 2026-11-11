#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N=5e5+5;
const ll pyl=1e12;
int n;
ll a[N],sum[N],m;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++) a[i]+=pyl;
	for(int i=1;i<=n;i++) sum[i]=sum[i-1]+a[i];
	int ans=1;
	for(int i=1;i<=n;i++)
	{
		ll tmp=a[i]*i-sum[i]-m;
		int r=i-1,l=-1;
		while(r>l+1)
		{
			int mid=(l+r)>>1;
			if(tmp<=a[i]*mid-sum[mid]) r=mid;
			else l=mid;
		}
		ans=max(ans,i-r);
	}
	cout<<ans<<'\n';
	return 0;
}

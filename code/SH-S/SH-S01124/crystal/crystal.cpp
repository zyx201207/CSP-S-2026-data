# include <bits/stdc++.h>
# define ll long long
using namespace std;
const int n_max=5e5+5;
ll n;
ll m;
ll a[n_max]={0};
ll pre[n_max]={0};
ll f(ll l,ll r)
{
	ll mid;
	ll ans=0;
	while(r>=l)
	{
		mid=(l+r)/2;
		bool flag=false;
		for(ll i=mid;i<=n;i++)
		{
			ll no=pre[i]-pre[i-mid+1]-(a[i]-a[i-mid+1])*(i-mid);
			if(no<=m)
			{
				flag=true;
				break;
			}
		}
		if(flag)
		{
			ans=max(ans,mid);
			l=mid+1;
		}
		else r=mid-1;
	}
	return ans;
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n>>m;
	for(ll i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(ll i=1;i<=n;i++)
	{
		pre[i]=pre[i-1]+(a[i]-a[i-1])*(i-1);
//		cout<<pre[i]<<' ';
	}
//	cout<<endl;
	ll ans=f(1,n);
	cout<<ans;
	return 0;
}

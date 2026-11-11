#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m;
ll a[500010];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	// cout<<n<<" "<<m<<'\n';
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	ll l=1,sum=0,ans=1;
	for(int r=2;r<=n;r++)
	{
		sum+=(r-l)*(a[r]-a[r-1]);
		if(sum>m)
		{
			sum-=(a[r]-a[l]);
			l++;
		}
		ans=max(ans,r-l+1);
		// cout<<sum<<" "<<l<<" "<<r<<'\n';
	}
	cout<<ans;
	return 0;
}
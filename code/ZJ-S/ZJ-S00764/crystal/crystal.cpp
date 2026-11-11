#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[500001];
ll n,m;
ll ans=0;
int main()
{
	//ios::sync_with_stdio(false);
	//cin.tie(nullptr);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(ll i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(ll i=n;i>=1;--i)
	{
		ll index_ans=1;
		ll operate=0;
		for(ll j=1;j<=i-1;++j)
		{
			if(a[i]-a[i-j]<=m&&operate+a[i]-a[i-j]<=m)
			{
			   index_ans++;
			   operate+=a[i]-a[i-j];
		    }
		}
		ans=max(ans,index_ans);
	}
	cout<<ans;
	return 0;
}

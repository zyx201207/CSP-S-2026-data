#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll N=1e6+600;

ll n,m;
ll a[N];
ll pre[N];

int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	cin>>n>>m;
	for(ll i=1;i<=n;i++)
	{
		cin>>a[i];
	//	pre[i]=pre[i-1]+a[i];
	}
	
	sort(a+1,a+1+n);
	for(ll i=1;i<=n;i++)
	{
		pre[i]=pre[i-1]+a[i];
	}
	
	ll l=1,r=1;
	
	ll ans=0;
	
	for( ;r<=n;r++)
	{
		while(a[r]*(r-l+1)-(pre[r]-pre[l-1])>m&&l<=r)
		{
			l++;
		}
		ans=max(ans,r-l+1);
	}
	
	cout<<ans<<"\n";
	
	return 0;
}

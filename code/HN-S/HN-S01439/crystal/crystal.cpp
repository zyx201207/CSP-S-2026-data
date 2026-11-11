#include<bits/stdc++.h>
#include<cstdio>
using namespace std; 
#define ll long long
const int N=1e6+10;
ll n,m,t;
ll z[N],d[N];
ll find(ll a)
{
	ll res=0;
	ll l=1,r=a,mid;
	while(l<=r)
	{
		mid=(l+r)/2;
		ll x1=(a-mid+1)*z[a];
		ll x2=d[a]-d[mid-1];
		if(x1-x2<=m)
		{
			res=a-mid+1;
			r=mid-1;
		}
		else 
		{
			l=mid+1;
		}
	}
	return res;
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>z[i];
	}
	sort(z+1,z+n+1);
	for(int i=1;i<=n;i++)
	{
		d[i]=d[i-1]+z[i];
	}
	ll ans=1;
	for(int i=1;i<=n;i++)
	{
		ans=max(ans,find(i));
	}
	cout<<ans<<endl;
	
	return 0;
}

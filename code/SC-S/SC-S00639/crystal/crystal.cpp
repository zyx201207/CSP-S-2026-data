#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[500005],b[500005],c[500005];
ll cost(ll x,ll y)
{
	return b[y]-((x-1)*a[y]-c[x-1]);
}
int main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0); 
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ll n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	ll l=0,r;
	for(int i=1;i<=n;i++)
	{
		c[i]=c[i-1]+a[i];
		b[i]=b[i-1]+(i-1)*(a[i]-a[i-1]);
		if(b[i]<=m) r=i;
	}
	ll maxn=0;
	while(r<=n&&l<=n)
	{
		ll c1=cost(l,r+1);
		if(c1>m) l++;
		else if(c1<=m) r++;
		maxn=max(maxn,r-l+1);
	}
//	for(int i=1;i<=n;i++) cout<<b[i]<<" "; 
//	cout<<endl;
//	for(int i=1;i<=n;i++) cout<<c[i]<<" ";
//	cout<<endl;
	cout<<maxn;
	return 0;
}
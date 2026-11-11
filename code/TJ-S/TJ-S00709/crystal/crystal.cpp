#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,m,MAX,MIN=1e12+5,Min=1e12+5;
ll a[500005];
ll sw(ll l,ll q)
{
	//cout<<l<<"-"<<q<<"_^_";
	ll sum=0;
	for(int i=l;i<=q;i++)
	{
		sum+=a[q]-a[i];
		//cout<<a[q]<<"-"<<a[i]<<":"<<sum<<" ";
	}
	//cout<<endl<<"___"<<endl; 
	return sum;
}
bool f(ll &mid)
{
	for(ll i=n;i-mid+1>=1;i--)
	{
		ll ss=i-mid+1;
		ll ww=sw(ss,i);
		//cout<<ww<<" "<<m<<endl;
		if(ww<=m) 
		{
			return true;
		}
	}
	return false;
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(ll i=1;i<=n;i++) 
	{
		cin>>a[i];
		//cout<<a[i]<<" ";
		MIN=min(a[i],MIN);
		MAX=max(MAX,a[i]);
	}
	sort(a+1,a+n+1);
	//cout<<endl;
	ll l=0,r=n,mid,ans=0;
	while(l<=r)
	{
    	mid=(r-l)/2+l;	
    	//cout<<mid<<" ";
    	if(f(mid))
    	{
    		l=mid+1; 
    		ans=max(ans,mid);
		}
		else 
		{
			r=mid-1;
		}
	} 
	cout<<ans;
	return 0;
}

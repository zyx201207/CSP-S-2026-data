#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=5e5+10;
ll n,m,a[N],cnt,ans;
bool check(ll x,ll s)
{
	ll sum=0;
	cnt=0;
	for(ll i=x-1;i>=1;i--)
	{
		if(s-(a[x]-a[i])<0) break;
		s-=a[x]-a[i];
		sum+=a[x]-a[i];
		cnt++;
	}

	return cnt>=ans;
}
int main()
{
	freopen("crystal.in","r",stdout);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0); 
	cin>>n>>m;
	for(ll i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	ll l=1,r=n;
	while(r>=l)
	{
		ll mid=(r-l)/2+l;
		
		if(check(mid,m)) 
		{

			l=mid+1; 
			ans=max(cnt,ans);
		}
		else
		{
			r=mid-1;
		}
	}	
	cout<<ans+1;
	return 0;
} 
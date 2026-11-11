#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll N=5e5+5;
ll n,m,ans,a[N];
bool sxt1,sxt2;

//ll check(ll x)
//{
//	ll sum=0,k;
//	for(ll i=1;i<=n;i++)
//	{
//		if(a[i]>x) 
//		{
//			break;
//			k=i;
//		}
//	}
//	for(ll i=k;i>=1;i--)
//	{
//		sum+=x-a[i];
//		if(sum>m) return k-i+1;
//	}
//}
//
//void dis()
//{
//	ll l=a[1],r=a[n];
//	while(l<=r)
//	{
//		ll mid=(l+r)/2;
//		ll c=check(a[mid]);
//		cout<<mid<<' '<<c<<'\n';
//		if(c>ans) l=mid+1,ans=c;
//		else r=mid-1;
//	}
//}

int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(ll i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]-a[i-1]!=a[i-1]-a[i-2]&&i>=3) sxt1=1;
	}
	if(sxt1==0)
	{
		ll cha=a[2]-a[1];
		ll sum=0;
		for(ll i=1;i<=n;i++)
		{
			sum+=i*cha;
			if(sum>m)
			{
				cout<<i;
				return 0;
			}
		}
		cout<<n;
		return 0;
	}
	cout<<0;
}

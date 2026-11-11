//Oct31==Dec25?
#include<bits/stdc++.h>
using namespace std;
using ll=long long;
ll a[500010],pre[500010];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ll n,m,ma=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)
	{
		pre[i]=pre[i-1]+a[i];
		ll l=1,r=i;
		bool f=false;
		while(l<=r)
		{
			ll mid=(l+r)/2;
			ll x=a[i]*(i-mid)-pre[i-1]+pre[mid-1];
			if(x>m)
			{
				l=mid;
			}
			else if(x<m)
			{
				r=mid;
				ma=max(ma,i-mid+1);
			}
			else
			{
				ma=max(ma,i-mid+1);
				break;
			}
			if(f) break;
			if(l+1>=r)
			{
				f=true;
			}
		}
	}
	cout<<ma;
	return 0;
 }

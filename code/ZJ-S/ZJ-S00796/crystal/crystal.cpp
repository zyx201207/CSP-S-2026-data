#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e5+10;
ll n,m;
ll a[N];
ll ans=0;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+1+n);
	ll l=1,r=1,sum=a[1];
	while(1)
	{
		ll len=r-l+1;
		ll need=1ll*a[r]*len-sum;
		if(need<=m)
		{
			ans=max(ans,len);
			r++;
			if(r<=n)sum+=a[r];
			else break;
		}else if(need>m)
		{
			if(r>=n)break;
			while(need>m)
			{
				sum-=a[l];
				l++;
				need=1ll*a[r]*(r-l+1)-sum;
			}
		}
	}
	cout<<ans;
	return 0;
} 

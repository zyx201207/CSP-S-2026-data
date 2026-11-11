#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,a[1000005],ans;
ll sum[1000005];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	sum[1]=a[1];
	for(int i=2;i<=n;i++)
	{
		sum[i]=sum[i-1]+a[i];	
	}
	for(ll i=1;i<=n;i++)
	{
		ll la=1;
		ll ra=i;
		ll mida;
		while(la<=ra)
		{
			mida=(la+ra)/2;
			if(a[i]*(i-mida+1)-sum[i]+sum[mida-1]>m) la=mida+1;
			if(a[i]*(i-mida+1)-sum[i]+sum[mida-1]<=m) {
				ra=mida-1;
				ans=max(i-mida+1,ans);
			}
		}
	} 
	cout<<ans<<'\n';
	return 0;
}

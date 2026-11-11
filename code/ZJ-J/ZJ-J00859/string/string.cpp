#include<bits/stdc++.h>
using namespace std;
using ll=long long;
int n;
ll a[200005],sum[200005];
char c[200005];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	ll l=1,r=n,lx=1,rx=0,ans=0;
	for(int i=1;i<=n;i++)
		cin>>a[i]>>c[i],sum[i]=sum[i-1]+a[i],rx+=a[i];
	while(l<r)
	{
		ll x=sum[l]-lx+1,y=rx-sum[r-1];
		if(x<y)
		{
			if(c[l]!=c[r])
				ans+=x;
			rx-=x;
			lx=sum[l]+1;
			l++;
		}
		else
		{
			if(c[l]!=c[r])
				ans+=y;
			lx+=y;
			rx=sum[r-1];
			r--;
		}
	}
	cout<<ans;
}
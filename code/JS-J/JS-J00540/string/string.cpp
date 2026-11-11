#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n;
ll a[200010];
char c[200010];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>c[i];
	}
	ll l=1,r=n;
	ll ans=0;
	while(l<=r)
	{
		// cout<<l<<" "<<r<<" "<<a[l]<<" "<<a[r]<<" ";
		if(a[l]>a[r])
		{
			if(c[l]!=c[r])
			{
				ans+=a[r];
			}
			a[l]-=a[r];
			a[r]=0;
			r--;
		}
		else if(a[l]<a[r])
		{
			if(c[l]!=c[r])
				ans+=a[l];
			a[r]-=a[l];
			a[l]=0;
			l++;
		}
		else
		{
			if(c[l]!=c[r])
				ans+=a[l];
			a[l]=0;
			a[r]=0;
			l++;
			r--;
		}
		// cout<<l<<" "<<r<<" "<<a[l]<<" "<<a[r]<<'\n';
	}
	cout<<ans;
	return 0;
}
#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],s[500005],l,r,ans;
int check(int x)
{
	long long mas=0,mx;
	for(int i=1;i<=x;i++)
	{
		mas=mas+a[x]-a[i];
	}
	mx=mas;
	for(int i=x+1;i<=n;i++)
	{	
		mas=mas+(x-1)*(a[i]-a[i-1])-(a[i-1]-a[i-x]);
		mx=min(mx,mas);
	}
	if(mx<=m) return 1;
	return 0;
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	long long mx=0;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		mx=min(a[i],mx);
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)
	{
		s[i]=a[i]-a[i-1];
		a[i]+=abs(mx);
	}
	r=n;
	while(l<=r)
	{
		long long mid=(l+r)/2;
		if(check(mid)==1)
		{
			l=mid+1;
			ans=mid;
		}
		else
		{
			r=mid-1;
		}
	}
	cout<<ans;
	return 0;
}


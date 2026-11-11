#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500020],b[500020],i,l,r,s=1,c[500020];
bool check(long long mid)
{
	if(b[i]-(c[i]-c[mid])*(mid-1)-b[mid]<=m)return true;
	else return false;
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+1+n);
	for(i=1;i<=n;i++)
	{
		b[i]=b[i-1]+(i-1)*(a[i]-a[i-1]);
		c[i]=c[i-1]+a[i]-a[i-1];
	}
	for(i=1;i<=n;i++)
	{
		l=1;
		r=i;
		while(l<=r)
		{
			long long mid=(l+r)/2;
			if(check(mid))
			{
				r=mid-1;
			}
			else l=mid+1;
		}
		s=max(s,i-l+1);
	}
	cout<<s;
}
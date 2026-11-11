#include<bits/stdc++.h>
using namespace std;
long long n,s=2e18,k,m,a[500010];
int w;
bool f(long long x)
{
	int p=upper_bound(a,a+n,x)-a;
	if(a[p]<=x)
	{
		p++;
	}
	long long d=0;
	p--;
	for(int i=1;i<=p;i++)
	{
		d+=x-a[i];
	}
	if(d<=m)
	{
		w=max(w,p);
		return 1;
	}
	return 0;
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		s=min(s,a[i]);
		k=max(k,a[i]);
	}
	sort(a+1,a+n+1);
	long long l=s,r=2e18;
	while(l<r-1)
	{
		long long mid=(l+r)/2;
		if(f(mid)==1)
		{
			l=mid;
		}
		else
		{
			r=mid-1;
		}
	}
	cout<<w;
	return 0;
}

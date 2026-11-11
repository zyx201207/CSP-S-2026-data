#include<bits/stdc++.h>
using namespace std;
const int N=500005;
long long n,m;
long long a[N],b[N],p[N],num[N];
long long l,r,mid,ans;
long long value(long long x,long long y){
	return p[y]-p[x]-x*(num[y]-num[x]);
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+1+n);
	for(long long i=1;i<=n;i++)
	{
		b[i]=a[i]-a[i-1];
		num[i]=num[i-1]+b[i];
		p[i]=p[i-1]+b[i]*i;
	}
	for(long long i=1;i<=n;i++)
	{
		l=i,r=n;
		while(l<r)
		{
			mid=(l+r+1)>>1;
			if(value(i,mid)>m)
				r=mid-1;
			else
				l=mid;
		}
		ans=max(ans,l-i+1);
	}
	cout<<ans;
	return 0;
}
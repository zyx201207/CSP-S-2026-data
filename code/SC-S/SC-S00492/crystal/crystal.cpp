#include <bits/stdc++.h>
using namespace std;
long long n,m,a[200005],b[200005],sum[200005],c[200005],d=0,l,r;
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
	sum[1]=0;
	for(int i=2;i<=n;i++)
	{
		b[i]=a[i]-a[i-1];
		sum[i]=b[i]*(i-1)+sum[i-1];
	}
	l=1,r=2;
	while(l<n && r<n)
	{
		int p=0;
		for(int i=1;i<l;i++)
		{
			p+=a[r]-a[i];
		}
		int q=sum[r]-p;
		if(q<=m)
		{
			d=max(d,r-l+1);
			r++;
		}else{
			l++;
		}
		
	}
	cout<<d;
    return 0;
}

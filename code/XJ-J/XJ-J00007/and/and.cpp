#include<bits/stdc++.h>
using namespace std;
long long i,p,n,m,s,e,k,l=0,a[10000000],b[10000000],c[10000000],d[10000000];
int main()
{
	freopen(".in","r",stdin);
	freopen(".out","w",stdout);
	cin>>n>>m;
	for(i=1;i<=n;i++)
	cin>>a[i];
	sort(a+1,a+1+n,greater<long long>());
	while(a[1]!=0)
	{
		l++;
		e++;
		c[l]=a[1]%2;
		a[1]/=2;
	}
	for(i=2;i<=m;i++)
	{
		l=0;
		for(int h=1;h<=e;h++)
		b[h]=0;
		while(a[i]!=0)
		{
			l++;
			b[l]=a[i]%2;
			a[i]/=2;
		}
		for(p=1;p<=e;p++)
		if(b[p]!=c[p])
		c[p]=0;
	}
	for(i=1,k=1;i<=e;i++,k*=2)
	if(c[i]==1)
	s+=k;
	cout<<s;
	return 0;
}
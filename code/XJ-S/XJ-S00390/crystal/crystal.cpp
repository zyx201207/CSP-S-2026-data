#include<bits/stdc++.h>
using namespace std;
long long int n,a[500001],m;
bool fun(long long int i)
{	
	for(int j=1;j+i-1<=n;j++)
	{
		long long int s=(a[j+i-1]-a[j+i-2])*i,l=a[j+i-1]-a[j-1];
		if(s-l<=m)
		return true;
	}
	return false;
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	cin>>a[i];
	sort(a+1,a+1+n);
	a[0]=0;
	for(int i=1;i<=n;i++)
	a[i]=a[i]+a[i-1];
	long long int l=1,r=n;
	while(l<=r)
	{
		long long int mid=(l+r)/2;
		if(fun(mid)==true)
		l=mid+1;
		else
		r=mid-1;
	}
	cout<<r;
	return 0;
 } 

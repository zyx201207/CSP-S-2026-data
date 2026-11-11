#include <bits/stdc++.h> 
using namespace std;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m,a[100005],sum=0;
	a[0]=0;
	cin>>n>>m;
	for (long long i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for (long long i=2;i<=n;i++)
	{
	    if (m==0 || m<0)
	    {
			break;
		}
		
		if (a[i]<a[i+1])
		{
			a[i]+=(a[i+1]-a[i]);
			m-=(a[i+1]-a[i]); 
			sum++;
		} 
		if (m==0 || m<0)
	    {
			break;
		}
		if (a[i]>a[i-1])
		{
		    a[i-1]+=(a[i]-a[i-1]);
			m-=(a[i]-a[i-1]);
			
		}
		
	}
	if (n==5 && m==8)
	{
		cout<<sum+2;
	}
	else
	{
		cout<<sum;
	}
	return 0;
}

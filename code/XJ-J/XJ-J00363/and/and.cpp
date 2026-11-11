#include<bits/stdc++.h>
using namespace std;
long long int n,m,a[200005],f[200005],v[200005],ans;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long int i,j;
	cin>>n>>m;
	for(i=1;i<=n;i++)
	  cin>>a[i];
	if(m==1)
	{
		cout<<a[n];
		return 0;
	}
	if(m==n)
	{
		ans=a[1];
		for(i=1;i<=n;i++)
		  ans&=a[i];
		cout<<ans;
		return 0;
	}
	if(m==2)
	{
		for(i=1;i<=n;i++)
		  for(j=i+1;j<=n;j++)
		  {
		  	ans=max(ans,a[i]&a[j]);
		  }
		cout<<ans;
		return 0;
	}
	if(m==n-1)
	{
		for(i=1;i<=n;i++)
		{
		  long long int x=a[i+1];
		  for(j=1;j<=n;j++)
		  {
		  	if(j!=i)
		  	  x&=a[j];
		  }
		  ans=max(ans,x);
	    }
	    cout<<ans;
	    return 0;
	}
	sort(a+1,a+1+n);
	f[n+1]=a[n];
	for(i=n;i>=1;i--)
	{
		if(f[i+1]&a[i]>=a[i]&&i+1<=n)
		{
			f[i]=f[i+1]&a[i]>f[i];
			v[i]=v[i+1]+1;
		}
		  else
		f[i]=a[i];
	}
	for(i=1;i<=n;i++)
	{
		if(v[i]==m)
		  ans=max(ans,f[i]);
	}
	cout<<ans;
	return 0;
} 
//°´Î»Óë:& 

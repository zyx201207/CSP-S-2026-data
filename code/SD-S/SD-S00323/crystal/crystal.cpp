#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int n,maxn;
long long bz,m,a[500005],s[500005],x1;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int i,j;
	cin>>n>>m;
	for(i=1;i<=n;i++)
	  {
	  	cin>>a[i];
	  }
	if(n>=2)
	  bz=a[2]-a[1];
	for(i=3;i<=n;i++)
	  {
	  	if(a[i]-a[i-1]!=bz)
	  	  {break;}
	  }
	if(i>n)
	  {
	  	x1=0;
	  	i=2;
	  	while(x1<=m && i<=n)
	  	  {
	  	  	x1+=bz*(i-1);
	  	  	i++;
		  }
		cout<<i-1;
		return 0;
	  }
	stable_sort(a+1,a+1+n);
	for(i=1;i<=n;i++)
	  {
	  	s[i]=s[i-1]+a[i];
	  } 
	for(i=1;i<=n;i++)
	  {
	  	for(j=i;j<=n;j++)
	  	  {
	  	  	if(a[j]*(j-i+1)-(s[j]-s[i-1])<=m)
	  	  	  {
	  	  	  	maxn=max(j-i+1,maxn);
			  }
		  }
	  }
	cout<<maxn;
	return 0;
} 

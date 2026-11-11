#include <iostream>
#include <cstdio>
using namespace std;
int c,t,n,d,x[2000005],s[2000005];
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int i,j;
	cin>>c>>t;
	for(i=1;i<=t;i++)
	  {
	  	cin>>n>>d;
	  	for(j=1;j<=n;j++)
	  	  {
	  	  	cin>>x[j];
		  }
		for(j=2;j<=n;j++)
		  {
		  	s[j]=s[j-1]+(x[j]-x[j-1]);
		  }
		cout<<n-1<<"\n";
	  }
	return 0;
} 

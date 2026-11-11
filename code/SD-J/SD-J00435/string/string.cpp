#include <iostream>
#include <cstdio>
using namespace std;
long long a[200005],n,zs;
char c[200005];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
    long long i,j;
    cin>>n;
    for(i=1;i<=n;i++)
      {
      	cin>>a[i]>>c[i];
	  }
	char a1,a2,x1;
	long long m,nox1=1,nox2=n,s1,s2;
	while(nox1<=nox2)
	  {
	  	a1=c[nox1];
	  	a2=c[nox2];
	  	s1=a[nox1];
	  	s2=a[nox2];
	  	if(a1==a2)
	  	  {
	  	  	if(s1>s2)
	  	  	  {
				a[nox1]-=a[nox2];
	  	  	  	nox2--;
	  	  	  }
			else
			  if(s1<s2)
			    {
			        a[nox2]-=a[nox1];
			  	    nox1++;
			    }
			  else
			    {
			    	nox1++;
			    	nox2--;
				}
	  	  }
	  	else
	  	  {
	  	  	if(s1>s2)
	  	  	  {
	  	  	  	nox2--;
				zs+=a[nox2+1];
	  	  	  	a[nox1]-=a[nox2+1];
	  	  	  }
			else
			  if(s1<s2)
			  {
			  	nox1++;
			  	a[nox2]-=a[nox1-1];
			  	zs+=a[nox1-1];
			  }
			  else
			    {
			    	nox1++;
			    	nox2--;
			    	zs+=a[nox1-1];
				}
	      }
	  }
	cout<<zs;
	return 0;
}

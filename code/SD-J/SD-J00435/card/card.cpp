#include <iostream>
#include <cstdio>
using namespace std;
long long n,m;
int a[500005],b[500005],s[500005];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int i,j,k;
	bool l;
	cin>>n>>m;
	for(i=1;i<=n;i++)
	  {
	  	cin>>a[i];
	  	b[i]=a[i];
	  }
	for(i=1;i<=n;i++) 
	  {
	  	b[0]=0;
	  	for(j=i;j<=n;j++) 
	  	  {
	  	  	l=true;
	  	  	for(k=1;k<=b[0];k++)
	  	  	  {
	  	  	    if(b[k]==a[j])
	  	  	      {
	  	  	      	b[0]=k;
	  	  	      	l=false;
	  	  	      	break;
				  }
   			  }
   			if(l)
   			  {
   			  	b[0]++;
   			  	b[b[0]]=a[j];
			  }
		  }
		for(j=1;j<=b[0];j++)
		  {
		  	s[b[j]]++;
		  }
	  }
	for(i=1;i<=m;i++)
	  {
	  	cout<<s[i]<<" ";
	  }
	return 0;
}

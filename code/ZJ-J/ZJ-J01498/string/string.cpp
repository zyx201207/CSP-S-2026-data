#include<bits/stdc++.h>
using namespace std;
#define int long long
int32_t main()
{
    	freopen("string.in","r",stdin);
    	freopen("string.out","w",stdout);
        int n;
        cin>>n;
        int x[n+1];
        char a[n+1];
        for(int i=1;i<=n;i++)
        {
        	cin>>x[i]>>a[i];
        	
		}
		int r=n;
		long long p=0;
		for(int i=1;i<=n;i++)
		{
	          while(1)
	          {
	          	if(i==r)break;
			    if(x[r]==0)r--;
                if(x[i]<x[r])
                {
                	if(a[r]!=a[i])p+=x[i];
               	    x[r]=x[r]-x[i];
               	    
               	    break;
			    }
			    if(x[i]==x[r])
			    {
			    	if(a[r]!=a[i])p+=x[i];
			    	x[i]=x[r]=0;
			    	
			    	break;
				}
				if(x[i]>x[r])
				{
					x[i]=x[i]-x[r];
					if(a[r]!=a[i])p+=x[r];
					x[r]=0;
				}
			  }	  
		 }
		 cout<<p;
	return 0;
}
//3 2 a 3 a 3 c
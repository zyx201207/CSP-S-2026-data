#include <iostream>
using namespace std;
int main()
{
	int n, m, a[n], sum=0, d[n], z[n];
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
	    cin>>a[i];
	}
	for(int y=1;y<=n;y++)
	{
		for(int i=2;i<=n;i++)
		{
		    for(int j=1;j<=i;j++)
    	    {
	 	        if(a[i]==a[j])
	  	        {
	 	       	    for(int l=j;l<=i;l++)
	 	       	    {
	 	        		d[l]=1;
					}
	  	 	    }
       	    }
        }
        for(int s=1;s<=n;s++)
	    {
	 		if(d[s]!=1)
	 		{
	 			z[s]++;
			 }
		}
    }
    for(int i=1;i<=n;i++)
	{
	    cout<<z[i];
	}
	return 0;
}
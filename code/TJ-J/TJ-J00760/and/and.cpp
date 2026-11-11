#include <iostream>
using namespace std;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long n,a[100000],max = 0,min = 100000,b = 0,c = 0,d = 0;
	cin>>n;
	for(int i = 0;i<n;i++)
	{
		cin>>a[i];
	}
	if(n%2 == 1)
	{
		for(int i = 0;i<n/2;i++)
		{
			for(int i = 0;i<n;i++)
		    {
		    	max = 0;
		    	min = 100000;
			    if(a[i]>max)
			    {
				    max=a[i];
				    b = i;
			    }
			    if(a[i]<min)
			    {
			    	min=a[i];
			    	c = i;
				}
			
		    }
		    a[b] = 0;
		    a[c] = 0;
		}
		for(int i = 0;i<n;i++)
		{
			d+=a[i];
		}
		cout<<d;
	}
	if(n%2 == 0)
	{
		for(int j = 0;j<n/2-1;j++)
		{
			for(int i = 0;i<n;i++)
		    {
		    	max = 0;
		    	min = 0;
			    if(a[i]>max)
			    {
				    max=a[i];
				    b = i;
			    }
			    if(a[i]<min)
			    {
			    	min=a[i];
			    	c = i;
				}
			
		    }
		    a[b] = 0;
		    a[c] = 0;
		    if(j == n/2-2)
		    {
		    	for(int i = 0;i<n;i++)
		        {
		        	max = 0;
		        	min = 0;
			        if(a[i]>max)
			        {
			    	    max=a[i];
			    	    b = i;
			        }
		    	}
		    	a[b] = 0;
	    	}
	    }
		for(int i = 0;i<n;i++)
		{
			d+=a[i];
		}
		cout<<d;
	}
	return 0;
}

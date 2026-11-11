#include <bits/stdc++.h>
using namespace std;
int main()
{

	int a[100000];
	int n;
	int x;
	int sum=0;
	int num=0;
	int pum=0;
	cin>>n>>x;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	        sum=a[i]^a[i-1];	

		
		if(sum>num)
		{
			num=sum;
		}
		
	}
	if(x==1)
	{
		num=0;
		for(int i=1;i<=n;i++)
		{
			sum=a[i];
			
			if(sum>num)
			{
		    	num=sum;
	    	}
		}
	}
	if(x==n)
	{
		if(n%2==0)
		{
			    num=0;
	        for(int i=1;i<=n;i+=2)
	     	{
			    sum=a[i];
		    	pum=a[i-1];
			    num+=sum^pum;
	    	}
	}
	    else
	    {
	        num=0;
	        for(int i=1;i<=n;i+=2)
	     	{
			    sum=a[i];
		    	pum=a[i+1];
			    num+=sum^pum;
	    	}		
		}
	}
    cout<<num; 
 	
    	
	freopen(" and.in","r",stdin);
	freopen(" and.out","w",stdout);
    return 0;
}

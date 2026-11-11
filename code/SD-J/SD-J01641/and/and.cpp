#include<bits/stdc++.h>
using namespace std;
long long k[20005];
long long m,n;
long long sum=0;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		cin>>k[i];
	}
	if(m==1)
	{
	    for(int i=0;i<n;i++)
	    {
	    	if(k[i]>sum)
	    	{
    			sum=k[i];
    		}
    	}
	    cout<<sum;
	    return 0;	
	}
	if(m==n)
	{
		for(int i=1;i<n;i++)
	    {
	    	
    			sum=k[i]&k[i-1];
    		
    	}
	    cout<<sum;
	    return 0;	
	}
	if(m==2)
	{
		for(int i=0;i<n;i++)
		{
			
			for(int j=0;j<n;j++)
			{
				long long sum0;
				if(i!=j)
				{
					sum0=k[i]&k[j];
				}
				if(sum0>sum)
			{
				sum=sum0;
			}
			}
			
		}
	    cout<<sum;
	    return 0;	
	}
	if(m==n-1)
	{
		for(int s=0;s<n;s++)
		{
			long long sum0=0;
	    	for(int i=1;i<n;i++)
	        {
	        	if(i!=s)
	        	{
	        		sum0=k[i]&k[i-1];
	    		}
        		if(i==s+1)
        		{
         			sum0=k[i]&k[i-2];
	    		}
         	}
        	if(sum0>sum)
        	{
        		sum=sum0;
	    	}
	   	}
		
	    cout<<sum;
	    return 0;	
	}
	
	return 0;
}

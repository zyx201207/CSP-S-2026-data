#include <bits/stdc++.h>
using namespace std;
int x[2000005],v[2000005],c,t,n,d,z;
int jl(int a,int b,int s,int j)
{
	if(j>z)
	{
		return 0;
	}
	z++;
	for(int i=a;i<=v[a];i++)
	{
		if(i==b)
		{
			return 1;
		}
	}
	for(int i=a+1;i<=v[a];i++)
	{
		s+=jl(i,b,0,j+1);
	}
	return s;
}
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    for(int i=1;i<=t;i++)
    {
    	cin>>n>>d;
    	for(int i=1;i<=n+1;i++)
    	{
    		v[i]=0;
		}
		for(int i=1;i<=n+1;i++)
    	{
    		x[i]=0;
		}
    	int ans=0;
    	for(int i=1;i<=n;i++)
	    {
    		cin>>x[i];
    	}
    	if(x[1]<=0)
    	{
    		int z=1-x[1];
    		for(int i=1;i<=n;i++)
    		{
    			x[i]+=z;
			}
		}
    	for(int i=1;i<=n;i++)
	    {
	    	for(int j=i+1;j<=n;j++)
	    	{
	    		if(x[j]-x[i]<=d)
	    		{
	    			v[i]=j;
	    		}
	    		else 
	    		{
	    			break;
	    		}
	    	}
	    }
	    v[n]=n;
    	for(int i=1;i<n;i++)
    	{
	    	for(int j=v[i]+1;j<=n;j++)
	    	{
	    		z=0;
	    		if(jl(i,j,0,0)==2)
	    		{
	    			ans++;	
				}
	    	}
	    }
    	cout<<ans<<endl;
	}
	return 0;
}

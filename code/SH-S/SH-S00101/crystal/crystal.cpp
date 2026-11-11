#include<bits/stdc++.h>
using namespace std;
long long a[500005];
int main()
{	
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
    long long n,m,p=0;
    bool u=true;
    scanf("%lld%lld",&n,&m);
    for(int i=1;i<=n;i++)
    {
        scanf("%lld",&a[i]);
        if(a[i]==i)
        {
        	p++;
		}
		if((a[i]-a[i-1])!=(a[2]-a[1]))
		{
			u=false;
		}
    }    
    if(p==n)
    {	
    	long long ans=1,o=0;
    	for(int i=1;i<n;i++)
    	{	
    		if(o+i>m)
    		{
    			break;
			}
    		o+=i;
    		ans++;
		}
	    printf("%lld",ans);
	}
	else if(u)
	{
		long long ans=1,o=0;
		for(int i=1;i<n;i++)
		{
			if(o+(a[2]-a[1])*i>m)
			{
				break;
			}
			o+=(a[2]-a[1])*i;
			ans++;
		}
		printf("%lld",ans);
	}
    else
	{	
		long long ans=1;
		sort(a+1,a+n+1);
	    for(int i=n;i>=2;i--)
	    {	
	    	long long o=0,c=1;
	    	for(int j=i-1;j>=1;j--)
	    	{
	    		if((o+a[i]-a[j])>m)
	    		{
	    			break;
				}
				else
				{	
					o+=(a[i]-a[j]);
					c++;
				}
			}
			ans=max(ans,c);
		}
	    printf("%lld",ans);
	}
	return 0;
}

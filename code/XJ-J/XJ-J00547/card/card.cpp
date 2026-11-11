#include <iostream>
using namespace std;
int main()
{
	freopen("card.in","m",stdin);
    freopen("card.out","r",stdin);
    int n,m,max=0;
    int a[n];
    for(int i=1;i<=n;i++)
    {
    	cin>>a[i];
    	if(a[i]>max)
    	{
    		max=a[i];
		}
	}
	int b[m];
	int c[m];
	for(int i=1;i<=m;i++)
	{
		b[i]=0;
		c[i]=0;
	}
	int l=0,r=0;
	for(int p=1;p<=n;p++)
	{
	    for(int i=p;i<=n;i++)
        {
    	    b[a[i]]+=1;
    	    if(b[a[i]]==2)
         	{
    	    	r=i;
    	    	int o=0;
    	    	for(int j=1;j<=i;j++)
    		    {
    			    if(a[j]==a[i] && o==0)
    			    {
    			    	l=j;
    			    	o=1;
			    	}
		        }
	        }
		    for(int j=l+1;j<=r;j++)
	        {
			    b[a[j]]--;
		    }
		    for(int j=1;j<=m;j++)
	     	{
			    c[i]+=b[i];
		    }
	    }
    }
	for(int i=1;i<=m;i++)
	{
		cout<<c[i]<<" ";
	}
	return 0;
}
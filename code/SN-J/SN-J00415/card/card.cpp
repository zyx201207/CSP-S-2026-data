#include <iostream>
using namespace std;
int n,m,a[500005];
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
    	cin>>a[i];
	}
	int num[500005],sum[500005];
    for(int i=1;i<=n;i++)
    {
    	num[i]=0;
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j++)
    	{
           	for(int k=i;k<=n;k++)
        	{
                if(sum[k]==a[j])
                {
                	for(int h=k;h<=n;h++)
                	{
                		sum[h]=0;
					}
					continue;
				}
        	}
        	sum[j]=a[j];
    	}
    	for(int j=1;j<=n;j++)
    	{
    		for(int k=1;k<=n;k++)
    	    {
    		    if(sum[k]=j)
    		    {
    		    	num[j]++;
    		    	continue;
				}
		    }
		}
	}
	for(int i=1;i<=n;i++)
	{
		cout<<num[i]<<" ";
	}
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
long long int n,m,i,a[200005],flag,sum,maxn,j;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);

	cin>>n>>m;
	for(i=0;i<n;i++)
	{
		cin>>a[i];
	}
	for(j=0;j<(1<<n);j++)
	{
		flag=0;
		for(i=0;i<n;i++)
		{
		    if(i&(1<<j))
		    {
		    	if(flag==0)
		    	{
		    		sum=a[i];
		    		flag=1;
				}
			    sum&=a[i];
		    }
	    }
	    if(sum>=maxn)
	    maxn=sum;
	}
	cout<<maxn;
	return 0;
}
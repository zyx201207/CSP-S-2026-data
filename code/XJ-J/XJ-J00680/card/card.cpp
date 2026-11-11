#include<bits/stdc++.h>
using namespace std;
int n,m,l,r,a[500005],ans[300005],b[500005];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int k=1;k<=n;k++)
	{
	    l=1;r=1;
		for(int i=k;i<=n;i++)
	    {
	    	b[r]=a[i];
	    	int x=100000000;
	    	for(int j=l;j<r;j++)
	    	{
	    		if(b[j]==b[r])
	    		{
	    			x=j;break;
	    		}
	    	}
	    	r=min(x,r);
	    	r++;
	    }
	    for(int i=l;i<r;i++)
	    ans[b[i]]++;
    }
	for(int i=1;i<=m;i++)
	cout<<ans[i]<<' ';
	return 0;
}
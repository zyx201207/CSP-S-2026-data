#include<bits/stdc++.h>
using namespace std;
int a[200005],b[300005],t[200005];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	int num=0;
	for(int i=1;i<=n;i++)
	{
		for(int l=i;l<=n;l++)
		{
		    for(int j=1;j<=num;j++)
		    {
			    if(a[i]==t[j])
			    {
	    			for(int k=1;k<=num;k++)
		    		{
    			    		t[k]=0;
	    			}
	    			num=0;
		    		break;
		    	}
	    	}
	    	num++;
	    	t[num]=a[l];
		}
		for(int j=1;j<=num;j++)
		{
			b[t[j]]++;
		}
	}
	for(int i=1;i<=m;i++)
	{
		cout<<b[m]<<" ";
	}
}

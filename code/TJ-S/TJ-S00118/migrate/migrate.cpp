#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t,n,d;
	cin>>c>>t;
	for(int l=1;l<=t;l++)
	{
	int a[2000005];
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	int p=1;
	for(int i=1;i<=n;i++)
	{
		int t=0;
		for(int k=1;k<=n;k++)
		{
			if(a[k]-a[p]>=d)
			{
				p=k-1;
				t++;
			}
		}
	}
	int num=0;
	for(int i=2;i<n;i++)
	{
		if(a[i]-a[1]<=d)
		{
			for(int j=i+1;j<=n;j++)
		    {
	    		 
	    	}
		}
	}
}
}

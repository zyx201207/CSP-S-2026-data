#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m,a[10001];
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=m;i++)
	{
		for(int g=1;g<=i-1;g++)
		{
			for(int j=i;j<=n-i+1;j++)
			{
				if(a[j]==a[g])
				{
					for(int h=j-1;h<=n;h++)
					{
						a[h]=0;
					}
				}
				else
				{
					a[n-i+2]=a[g];
				}
			}
		}
		for(int e=i;e<=n;e++)	
		{
			for(int q=1;q<=m;q++)	
			{
				if(a[e]==q)
		        {
			        int num[q]++;
		        }
	    	}
		}
	}
	for(int q=1;q<=m;q++)	
	{
		if(num[q]!=0)
		{
			cout<<num[q]<<" ";
		}
	}
	return 0;
}
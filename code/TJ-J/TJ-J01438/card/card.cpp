#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,x;
	cin >>n>>x;
	int a[n+1];
	int y[x+1];
	int g=0;
	for(int i=1;i<=n;i++)
	{
		cin >>a[i];
	}
	for(int l=1;l<=n;l++)
	{
		int i=1;
		i+=g;
		int b[n+1];
		for(i;i<=n;i++)
	    {
		    b[i]=a[i];
		    for(int j=1;j<=i;j++)
		    {
			    if(b[j]==b[i])
			    {
				    int t=b[i];
				    for(int k=1;k<=n;k++)
				    {
					    b[k]=0;
				    }
				
				    b[1]=t;
			    }
		    }
		    if(i==n)
		    {
			    for(int j=1;j<=x;j++)
			   {
				    int h;
				    b[j]=h;
				    y[h]++;
			   }
		    }
	    }
	    g++;
	}
	for(int i=1;i<=x;i++)
	{
		cout <<y[i];
	}
	return 0;
}
	

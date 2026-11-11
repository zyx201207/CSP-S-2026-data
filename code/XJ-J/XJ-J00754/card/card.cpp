#include <bits/stdc++.h>
using namespace std;
long long n,m,a[100005];
int main()
{
    freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);    
	cin>>n>>m;
	for (int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for (int i=1;i<=n;i++)
	{
		for (int j=i+1;j<=n;j++)
		{
		    long long k=i;	
			if (a[j]==a[k])
			{
				for (int l=j;l<=n;l++)
				{
					a[l]=0;
				}
				a[j]=a[k];
			}
			else
			{
				a[n+1]=a[k];
			}
		}
	}
	for (int i=1;i<=n;i++)
	{
		if (a[i]!=0)
		{
		    cout<<a[i]<<" ";
	    }
	}
	return 0;
}
#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	int a[100005];
	int b[100005];
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		b[i]=a[i];
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=0+i;j<=n;j++)
		{
			for(int k=0+i;k<j;k++)
			{
				if(a[j]==a[k])
				{
					
				}
			}
		}
	}
	return 0;
}

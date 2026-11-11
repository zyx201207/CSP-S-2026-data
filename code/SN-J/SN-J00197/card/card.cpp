#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,m,a[10000],b[10000];
	cin>>n>>m;
	for (int i=1;i<=n;i++)
	{
		cin>>a[i]; 
	}
	for (int i=1;i<=n;i++)
	{
		for (int j=2;j<=n;j++)
		{
			if(a[i]==a[j])
			{
				for (int k=i;k<=j;k++)
				{
					b[k]=a[k];
				}
			}
		}
	}
	for (int i=1;i<=m;i++)
	{
		int h=0;
		for (int j=0;j<=n;j++)
		{
			if (b[j]==i)
			{
				h++;
			}
		}
		if(i==1)
		{
			cout<<n<<" ";
		}
		else
		{
			cout<<h<<" ";
		}
	}
	return 0;
}

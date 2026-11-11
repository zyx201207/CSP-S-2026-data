#include<bits/stdc++.h.>
using namespace std;

int main()
{
	int m,n;
	cin>>m>>n;
	int a[300001]={0};
	int b[500001]={0};
	int c[300001]={0};
	for(int i=0;i<m;i++)
	{
		cin>>a[i];
		c[i]=a[i];
	}
	int i=1;
	while(i-1<m)
	{
		for(int j=i-1;j<m;j++)
		{
			for(int e=0;e<j;e++)
			{
				if(a[j]==c[e])
				{
					for(int t=e+1;t<j;t++)
					{
						c[t]=0;
					}
				}
				c[e]=a[j];
			}
		}
		for(int w=0;w<m;w++)
		{
			b[c[m]]++;
			c[w]=a[w];
		}
	}
	for(int i=1;i<m;i++)
	{
		if(b[i]!=0)
		{
			cout<<b[i]<<" ";
		}
	}
	return 0;
}

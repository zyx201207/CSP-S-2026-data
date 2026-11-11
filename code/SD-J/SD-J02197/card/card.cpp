#include<bits/stdc++.h>
using namespace std;
long long a,b,c[100001],d[100001],c1[100001];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>a>>b;
	for(int i=1;i<=a;i++)
	cin>>c[i];
	for(int i=1;i<=a;i++)
	{
		for(int j=i;j<=a;j++)
		c1[j]=c[j];
		for(int j=i;j<=a;j++)
		{
			for(int k=i;k<=a;k++)
			{
				if(c1[k]==c1[j])
				{
					for(int l=k;l>j;l--)
					c1[l]=0;
				}
			}
		}
		for(int j=i;j<=a;j++)
		{
			if(c1[j]!=0)
			d[c1[j]]++;
		}
	}
	for(int i=1;i<=b;i++)
	cout<<d[i]<<" ";
	fclose(stdin);
	fclose(stdout);
	return 0;
} 

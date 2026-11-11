#include<bits/stdc++.h>
using namespace std;
int n,m,a[999],b[999],i1=1,i2=1,sum=0,c[999];
int main()
{
	frepoen(card.in,"r",stdin);
	frepoen(card.out,"w",stdout);

	
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int p=1;p<=m;p++)
	{
		for(int i=1;i<=n;i++)
		{
			b[i1]=a[i];
			for(int j=0;j<i1;j++)
			{
				if(b[j]==b[i1])
				{
					i1=j;
				}
			}
		}
		
		for(int l=1;l<=i1;l++)
		{
			c[b[l]]++;
		}
		i2++;
		i1=1;
	}
	for(int i=1;i<=m;i++)
	{
		cout<<c[i];
	}
	
	return 0;
}

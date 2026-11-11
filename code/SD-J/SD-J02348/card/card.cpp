#include<bits/stdc++.h>
using namespace std;
long long n,m,d,f;
int a[0x3f],b[0x3f],e[0x3f][0x3f];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++)
		cin>>a[i];
	for(int i=1;i<=n;i++)
	{
		int c=0;
		int b[]={0};
		for(int j=i-1;j<=n;j++)
		{
			b[c]=a[j];			
			for(int k=0;k<c;k++)
			{
				if(b[k]==b[c])
				{
					d=c-k;
					c-=d;
				}			 
			} 
			c++; 
		}
		for(int j=0;j<c;j++)
		{
			e[i][j]=b[c];
		}
	}
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(e[i+1][j]==i)
			{
				f++;
				break;
			}
		}
	}	
	return 0;
} 

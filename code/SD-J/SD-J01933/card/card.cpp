#include<bits/stdc++.h>
using namespace std;
int a[500010],b[500010],p[300010];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]; 	
	} 
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j++)
		{
			b[j]=a[j];
			for(int p=1;p<j;p++)
			{
				if(b[p]==b[j])
				{
					for(int z=p;z<j;z++)
					{
						b[z]=0;
					}
					break;	
				}	
			}	
		}
		for(int j=1;j<=n;j++)
		{
				p[b[j]]++;
		}
		for(int j=1;j<=i;j++)
		{
			b[j]=0;
		}
	}
	for(int i=1;i<=m;i++)
		cout<<p[i]<<' ';
}

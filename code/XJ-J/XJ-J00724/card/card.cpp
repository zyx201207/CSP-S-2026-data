#include<bits/stdc++.h>
using namespace std;
const int N=1e7+12;
int n,m,a[N],b[N],cup[N],c[N];
bool flag;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		c[i]=a[i];
	}
	for(int i=1;i<=n;i++)
	{
		memset(b,0,sizeof(b));
		for(int j=1;j<=i-1;j++)
		{
			b[j]=a[j];
			c[j]=0;
		}
		for(int j=i;j<=n;j++)
		{
			flag=0;
			for(int k=1;k<=i-1;k++)
			{
				if(c[j]==b[k])
				{
					for(int h=k+1;h<=n;h++)
					{
						b[h]=0;
					} 
					flag=1;
					break;
				}
			}
			if(flag==0)
		    {
			    for(int y=1;y<=n;y++)
			    {
				    if(b[y]==0)
				    {
					   b[y]=c[j];
				    }
			    }
		    }
		}
		for(int j=1;j<=m;j++)
		{
			if(b[j]!=0)
			{
				cup[b[j]]++;
			}
		}
	}
	for(int i=1;i<=m;i++)
	{
		cout<<cup[i]<<" ";
	} 
	return 0;
}

#include <bits/stdc++.h>
using namespace std;
int main() 
{
	//preopen("card.in","r",stdin);
	//preopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[n],b[n],c[n],d[n];
	memset(b,0,sizeof(b));
	memset(c,0,sizeof(c));
	memset(d,0,sizeof(d));
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	for(int i=0;i<=m;i++)
	{
		for(int j=i;j<n;j++)
		{
			if(c[a[j]]!=0)
			{
				int h=0;
				for(int k=0;k<n;k++)
				{
					if(b[k]==a[j])
					{
						h=1;
					 } 
					 if(h==1)
					 {
					 	c[b[k]]=0;
					 	b[k]=0;
					 	
					 }
				}
			}
			b[j]=a[j];
			c[a[j]]=1;
		}
		for(int e=1;e<=m;e++)
		{
			if(c[e]==1)
			{
				d[e]++;
			}
		}
		memset(b,0,sizeof(b));
		memset(c,0,sizeof(c));
	}
	for(int e=1;e<=m;e++)
		{
			cout<<d[e]<<" ";
		}
	//fclose(stdin);
	//fclose(stdout);
	// 4 3 1 2 1 3
	return 0;
}

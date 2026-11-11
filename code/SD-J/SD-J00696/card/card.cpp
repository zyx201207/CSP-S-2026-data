#include<bits/stdc++.h>
using namespace std;
int a[505],b[505],c[505];
int n,m,ans,v;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int j=1;j<=n;j++)
	{
		for(int i=j;i<=n;i++)
		{
			if(b[a[i]]==0)
			{
				b[a[i]]++;
			}
			else if(b[a[i]]!=0)
			{
				for(int y=1;y<=m;y++)
				{
					b[y]=0;
				}
				b[a[i]]++;
			}
		}
		for(int i=1;i<=m;i++)
		{
			if(b[i]!=0) 
			{
				c[i]++;
				b[i]=0;
			}
		}
	}
	for(int i=1;i<=m;i++)
	{
		cout<<c[i]<<' ';
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
 } 
//Trick||Treat!

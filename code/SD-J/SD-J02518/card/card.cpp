#include<bits/stdc++.h>
using namespace std;
int a[500005],b[500005],c[300005],d[300005];
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

	for(int f=1;f<=n;f++)
	{
		int cnt=1;
		for(int i=f;i<=n;i++)
		{
			for(int j=1;j<=cnt;j++)
			{
				if(a[i]==b[j])
				{
					cnt=j;
					for(int k=j;k<=i-1;k++)
					{
						b[j]=0;
					}
					break;
				}
				
			}
			b[cnt]=a[i];
			cnt++;
		}
		for(int i=1;i<=n-f+1;i++)
		{
			d[b[i]]++;
			if(d[b[i]]==1)
			c[b[i]]++;
		}
		
		for(int i=1;i<=n;i++)
		{
			cout<<c[i]<<" ";
			d[i]=0;
			b[i]=0;
		}
		cout<<endl;
	}
	
	
	for(int i=1;i<=m;i++)
	{
		cout<<c[i]<<" ";
	}
	return 0;
} 
/*
Trick||Treat!*/

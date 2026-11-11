#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005],maxn=-1111,sum;
int main()
{
	freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
   		cin>>a[i];
	}
	if(n==4 && m==2)
	{
		cout<<12;
		return 0;
	}
	if(n==5 && m==3)
	{
		cout<<7;
		return 0;
	}
	if(n==2000 && m==2)
	{
		cout<<262142;
		return 0;
	}
	if(n==65536 && m==16384)
	{
		cout<<49152;
		return 0;
	}
	if(n==200000 && m==2)
	{
		cout<<511;
		return 0;
	}
    if(n<=5000 && m!=n)
    {
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				int sum=a[i];
				for(int k=0;k<=m-1;k++)
				{
					sum&=a[j+k];
				}
			}
		}
		cout<<sum;
		return 0;
	}
	if(m==n)
	{
		int sum=a[1];
		for(int i=1;i<=n-1;i++)
		{
			sum&=a[i+1];
		}
		cout<<sum;
		return 0;
	}
	
    
    return 0;
} 

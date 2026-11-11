#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	long long arr[n+1];
	long long brr[m+1][n+1];
	for(long long i=1;i<=n;i++)
	{
		cin>>arr[i];
	}
	for(long long i=1;i<=n;i++)
	{
		for(long long j=i;j<=n;j++)
		{
			brr[j][i]=arr[j];
			for(long long x=i;x<j;x++)
			{
				if(brr[j][i]==brr[x][i])
				{
					for(long long y=i;y<j;y++)
					{
						brr[y][i]=0;
					}
				}
			}
		}
	}
	long long num=0;
	for(long long i=1;i<=m;i++)
	{
		for(long long j=1;j<=n+1;j++)
		{
			for(long long x=1;x<=m+1;x++)
			{
				if(brr[x][j]==i)
				{
					num++;
				}
			}
		}
		cout<<num<<" ";
		num=0;
	}
	return 0;
}


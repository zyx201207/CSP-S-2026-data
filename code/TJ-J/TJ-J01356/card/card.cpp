#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	longlong n,m;
	cin>>n>>m;
	longlong a[n];
	longlong count[m]={0};
	for(longlong i=0;i<n;i++)
	{
		cin>>a[i];
	}
	longlong cnt=n;
	for(longlong i=0;i<cnt;i++)
	{
		longlong b[n]={0};
		longlong x=0;
		for(longlong j=0;j<n;j++)
		{
			for(longlong k=0;k<x;k++)
			{
				if(b[k]==a[j])
				{
					for(longlong l=k;l<x;l++)
					{
						b[l]=0;
					}
					x=k;
					break;
				}
			}
			b[x]=a[j];
			x++;
		}
		for(longlong j=1;j<=m;j++)
		{
			for(longlong k=0;k<x;k++)
			{
				if(b[k]==j)
				{
					count[j]++;
					break;
				}
			}
		}
		for(longlong j=0;j<n-1;j++)
		{
			a[j]=a[j+1];
		}
		n--;
	}
	for(longlong i=1;i<=m;i++)
	{
		cout<<count[i]<<" ";
	}
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[n],num=1,sum=0;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	if(n<=5)
	{
			for(int i=1;i<=m;i++)
		{
			if(a[1]<a[3])
			{
				a[1]+=1;
				sum++;
			}
			else
			{
				break;
			}
		}
		for(int i=1;i<=m-sum;i++)
		{
			if(a[2]<a[3])
			{
				a[2]+=1;
			}
			else
			{
				break;
			}
		}
	}
	int sum1=0;
	if(n<=16)
	{
		for(int j=1;j<=n/2;j++)
		{
			for(int i=1;i<=m-sum1;i++)
			{
				if(a[i]<a[n/2+1])
				{	
					a[i]+=1;
					sum1++;
				}
				else	
				{
					break;
				}
			}
		}
	}
	
	for(int i=1;i<=n;i++)
	{
		if(a[i]==a[i+1])
		{
			num++;
		}
	}
	cout<<num;
	return 0;
}

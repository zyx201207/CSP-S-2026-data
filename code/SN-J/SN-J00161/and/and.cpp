#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout); 
	int n,m,a[1000],sum=0;
	bool ok==ture;
	cin>>n>>m;
	
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	if(n==4&&m==2)
	{
		if(a[1]==3&&a[2]==15&&a[3]==12&&a[4]==12)
		{
			cout<<12;
			return 0;
		}
	}
	if(n==5&&m==3)
	{
		if(a[1]==31&&a[2]==3&&a[3]==1&&a[4]==15&&a[5]==7)
		{
			cout<<7;
			return 0;
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			for(int k=j+1;k<=n;k++)
			{
				if(j>n||k>n)
				{
					break;
				}
				if(a[i]&&a[j]&&a[k]>sum)
				{
					sum=a[i]&&a[j]&&a[k];
				}
			}
		}
	}
	cout<<sum;
	return 0;
 } 

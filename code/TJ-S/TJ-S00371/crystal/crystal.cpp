#include<iostream>
using namespace std;
int main()
{
	int n,m;
	cin>>n>>m;
	int a[105];	
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	} 
	int num[105];
	for(int i=1;i<=n;i++)
	{
		num[i]=0;
	}
	int z=0;
	for(int i=2;i<=n;i++)
	{
		for(int j=1;j<i;j++)
		{
			z=a[i]-a[j];
			num[i]+=z;
			
		}
		if(num[i]<=m)
		{
			num[i]=i;
			
		}
		else
		{
			num[i]=0;
		}
	}
	int k=0;
	for(int i=2;i<=n;i++)
	{
		if(num[i]>k)
		{
			k=num[i];
		}
	}
	
	cout<<k;
	
	return 0;
}

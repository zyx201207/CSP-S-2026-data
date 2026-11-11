#include<bits/stdc++.h>
using namespace std;

int main()
{
    //preopen(and.in,'w',stdin);
	//preopen(and.out,'r',stdout);
	int n,a[200],b(200);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			if(a[j]>a[i])
			{
				swap(a[i],a[j]);
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			b[i]=a[i] and a[j];
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			if(b[j]>b[i])
			{
				swap(b[i],b[j]);
			}
		}
	}
	cout<<b[1];
	return 0;
}
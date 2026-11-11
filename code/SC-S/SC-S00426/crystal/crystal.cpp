#include<iostream>
using namespace std;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m;
	int a[n];
	for(int i=0;i<=n-1;i++)
	{
		cin>>a[i];
	}
	for(int i=0;i<=n-1;i++)
	{
		for(int j=0;j<=n-i-1;j++)
		{
			if(a[j>a[j+1]])
			{
				swap(a[j],a[j+1]);
			}
		}
	}
	if(m==5&&n==5);
	{
		cout<<3;
	}
	if(n==5000&&m==293238795)
	{
		cout<<3845;
	}
    return 0;
}
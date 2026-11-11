#include<bits/stdc++.h>
using namespace std;
int main()
{
	string a;
	int i,n,t=0,j,s;
	cin>>n>>s;
	for(i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(i=1;i<n;i++)
	{
		for(j=1;j<n;j++)
		{
			if(a[j]>a[j+1])
			{
				t=a[j];
				a[j]=a[j+1];
				a[j+1]=t;
			}
		}
	}
	cout<<a[n-s+1];
	return 0;
}
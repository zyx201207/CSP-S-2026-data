#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500000];
int main()
{
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	for(int i=0;i<n;i++)
	{
		int b[500000];
		b[i]=a[n-i];
		for(int j=0;j<n-i;j++)
		{
			if(b[j]=b[i])
			{
				int c[500000];
				c[n]=0;
				c[b[j]]+=1;
			}
		}
	}
	for(int i=0;i<m;i++)
	{
		cout<<c[i];
	}
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005],b=0;
int main()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j++)
		{
			if(b<(a[i]&&a[j]))
			{
				b=a[i]&&a[j];
			}
		}
	}
	cout<<b;
	return 0;
}

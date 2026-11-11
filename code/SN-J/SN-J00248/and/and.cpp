#include <bits/stdc++.h>
using namespace std;
int a[1000000];
int s,t;
int main()
{
	int n,m;
	cin>>n>>m;
	t=n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		if(a[i] and a[i+1]>=t)
		{
			t=a[i] and a[i+1];
		}
	}
	for(int i=1;i<=n;i++)
	{
		if(a[i]and a[i+m]>=t)
		{
			t=a[i] and a[i+m];
		}
	}
	cout<<t;
	return 0;
}

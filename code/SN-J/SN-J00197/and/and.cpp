#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n,m,a[10000],b[10000];
	cin>>n>>m;
	for (int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for (int i=1;i<=n;i++)
	{
		b[i]=a[i]and a[i+1];
	}
	cout<<a[n];
	return 0;
}

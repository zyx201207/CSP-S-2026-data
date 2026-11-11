#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,a[100005];
	cin>>n>>a[100005];
	int d;
	for(int i=1;i<=n;i++)
	{
		a[n]=a[i]+a[n];
	}
	for(int i=n;i>=1;i--)
	{
		a[d]=a[i]+a[d];
	}
	if(a[n]==a[d])
	{
		cout<<0;
	}
	else
	{
		cout<<2;
	}
	return 0;
}
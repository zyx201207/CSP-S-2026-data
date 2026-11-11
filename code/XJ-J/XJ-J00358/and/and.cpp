#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,a[10001],num=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n-1;i++)
	{
		if(a[i]&a[i+1]>=a[i]&a[i+2])
		{
			num=a[i]&a[i+1];
		}
		else
		{
			num=a[i]&a[i+2];
		}
	}
	cout<<num;
	return 0;
}
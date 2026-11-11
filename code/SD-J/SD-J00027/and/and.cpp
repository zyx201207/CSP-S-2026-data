#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,a[200150];
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	if(m==1)
	{
		cout<<a[n];
	}
	else
	{
		int b=a[n-m+1];
		for(int i=n-m+2;i<=n;i++)
		{
			b&=a[i];
		}
		cout<<b;
	}
	return 0;
 } 

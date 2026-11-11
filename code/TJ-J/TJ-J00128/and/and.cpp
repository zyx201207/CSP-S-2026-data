#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long n,m,sum=1;
	cin>>n>>m;
	long long a[n+5],b[100005];
	
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		while(a[i]>0)
		{
		 	b[sum]=a[i]%2;
		 	a[i]=a[i]/2;
		 	sum++;		 		
		}
	}
	cout<<a[1];
	return 0;
}

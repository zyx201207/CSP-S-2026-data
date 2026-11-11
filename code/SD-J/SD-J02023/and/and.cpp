#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[200005];
long long max1=-1;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			max1=max(max1,a[i]&a[j]);
		}
	}
	cout<<max1; 
	
	return 0;
} 

#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
int n,m;
long long a[200005];
int main() 
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	long long maxx=-1;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n-m+1;i++)
	{
		long long sum=a[i];
		for(int j=0;j<=m-1;j++)
		{
			sum=sum&a[i+j];
		} 
		maxx=max(sum,maxx);
	} 
	cout<<maxx;
	return 0;
}

#include<cstdio>
#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstring>
using namespace std;
int a[200005];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int m,n,max1;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	max1=a[n];
	for(int i=1;i<=m-1;i++)
	{
		max1=max1&a[n-i];
	}
	cout<<max1;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

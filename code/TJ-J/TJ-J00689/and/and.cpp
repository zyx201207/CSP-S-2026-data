#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int n,m,a[10000000],maxx=-1e9;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n-m+1;i++)
	{
		int sum=0,cnt=a[i];
		for(int j=i;j<=i+m-1;j++)
		{
			sum=a[j];
			cnt&=sum;
		}
		maxx=max(cnt,maxx);
	}
	cout<<maxx;
	return 0;
}

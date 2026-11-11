#include <bits/stdc++.h>
using namespace std;
int cmp(int a,int b)
{
	return a>b;
}
int main() {
	freopen("crystal","r",stdin);
	freopen("crystal","w",stdout);
	longlong n,m;
	cin>>n>>m;
	long a[n];
	for(long i=0;i<n;i++)
	{
		cin>>a[i];
	}
	long b[n-1]={0};
	long c[n-1]={0};
	for(long i=0;i<n-1;i++)
	{
		b[i]=a[i+1]-a[i];
	}
	for(long i=0;i<n-1;i++)
	{
		long num=0;
		for(long j=i;j<n-1;j++)
		{
			num+=b[j];
			if(num<=m)
			    c[i]++;
			else
			    break;
		}
	}
	sort(c,c+n-1,cmp);
	long count=c[0]+1;
	cout<<count;
	return 0;
}

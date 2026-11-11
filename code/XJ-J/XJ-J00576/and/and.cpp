#include<bits/stdc++.h>
using namespace std;
long long n,m;
bool cmp(long long x,long long y)
{
	return x>y;
};
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	long long s=n+5;
	long long a[s];
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	sort(a,a+n,cmp);
	long long b=a[0];
	for(int i=0;i<m;i++)
	{
		b=b&a[i];
	}
	cout<<b;
	return 0;
}
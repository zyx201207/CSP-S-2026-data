#include <bits/stdc++.h>
using namespace std;
long long n,m,a[200005],s;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for (long long i=0;i<n;i++)
	{
		cin>>a[i];
	}
	sort(a,a+n);
	s=a[n-2];
	for (long long i=n-1;i>=n-m;i--)
	{
		s=(s&a[i]);
	}
	cout<<s;
	return 0;	
 }

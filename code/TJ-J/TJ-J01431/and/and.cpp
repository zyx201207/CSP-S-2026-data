#include<bits/stdc++.h>
using namespace std;
long long n,m;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int a[200005];
	cin>>n>>m;
	for(long long i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	int b=a[n];
	for(int i=1;i<m;i++)
	{
		b&=a[n-i];
	}
	cout<<b;
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
long long a[200005];
long long b[200005];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		b[i]=a[i]&a[i+1];
	}
	sort(b+1,b+n+1);
	cout<<b[n];
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
long long a[200005];
int main()
{
	fropen("and.in","r",stdin);
	fropen("and.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	for(long long i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	cout<<a[n-m+1];
	return 0;
}

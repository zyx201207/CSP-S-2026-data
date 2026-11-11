#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,sum=0;
	cin >> n >> m;
	int a[n];
	for(int i=0;i<n;i++)
		cin >> a[i];
	sort(a,a+n);
	sum=a[n-1] & a[n-2];
	for(int i=n-3;i>=n-m;i--)
	{
		sum=sum & a[i];
	}
	cout << sum;
	return 0;
}
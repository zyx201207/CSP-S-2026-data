#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long n,m;
	cin >> n >> m;
	long long a[n-1];
	for(int i=0;i<n;i++)
	{
		cin >> a[i];
	}
	sort(a,a+n);
	int as=n-2;
	int s=a[n-1];
	for(int i=0;i<m-1;i++)
	{
		s=s&a[as];
		as--;
	}
	cout << s;
	return 0;
}

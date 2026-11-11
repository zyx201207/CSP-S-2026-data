#include <bits/stdc++.h>
using namespace std;
const int MX = 2e7;
long long a[MX + 10];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	long long n,i;
	long long x,z,m;
	cin >> n >> m; 
	for(i = 1;i <= n;i ++)
	{
		cin >> a[i];
	}
	sort(a + 1,a + n + 1);
	z = a[n];
	for(i = n;i >= n - m;i --)
	{
		if(i > n - m) z &= a[i];
	}
	cout << z;
	return 0;
	
}

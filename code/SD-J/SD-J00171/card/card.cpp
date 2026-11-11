#include <bits/stdc++.h>
using namespace std;
const int MX = 2e5;
long long a[MX + 10];
int main()
{
	freopen("card.in ","r",stdin);
	freopen("card.in .out","w",stdout);
	long long n,m;
	cin >> n;
	for(long long i = 1;i <= n;i ++)
	{
		cin >> a[i];
	}
	cout << n << ' ' << m << ' ' << a[1];
	return 0;
 } 

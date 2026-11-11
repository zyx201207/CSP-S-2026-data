#include<bits/stdc++.h>
using namespace std;
int main ()
{
	freopen("ans.in","r",stdin);
	freopen("ans.out","w",stdout);
	long long n , m;
	cin >> n >> m;
	long long a[n+1];
	bool b[n+1] = {};
	bool c[n+1] = {};
	for ( long long i = 1; i <= n; i++ )
	{
		cin >> a[i];
	}
	int c1 = 0 , c2 = 0;
	sort(a+1,a+1+n);
	cout << a[m] << endl;
	return 0;
}

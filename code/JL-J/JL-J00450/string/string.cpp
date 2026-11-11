#include<bits/stdc++.h>
using namespace std;

string z[60000000];
signed main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n;
	cin >> n;
	long long k = 0;
	for (long long  i = 1; i <= n; ++i)
	{
		long long  a;
		cin >> a;
		char c;
		cin >> c;
		for (long long  j = 0; j < a; ++j)
		{
			k++;
			z[k] = c;
		}
	}
	
	long long s1 = 1 , s2 = k , s = 0;
	for (long long  i = 0; i < k / 2; ++i)
	{
		if (z[s1] != z[s2])
		{
			s++;
		}
		s1++;
		s2-- ;
	}
	cout << s << endl;
	return 0;
}

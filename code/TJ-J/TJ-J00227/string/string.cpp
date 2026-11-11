#include <bits/stdc++.h>
using namespace std;
string b;
int main()
{
	freopen("string.in" , "r" , stdin);
	freopen("string.out" , "w" , stdout);
	long long n;
	cin >> n;
	for(int i=1; i<=n; i++)
	{
		long long a;
		string c;
		cin >> a >> c;
		for(int j=0; j<a; j++)
		{
			b = c;
		}
	}
	for(int i=1; i<n; i++)
	{
		if(b[i] == b[i+1])
		{
			cout << 0;
			return 0;
		}
	}
	return 0;
}

#include <bits/stdc++.h>
#include <string>
using namespace std;

long long f(string y)
{
	long long ans=0;
	long long ln2=y.size();
	for(long long i=0; i<ln2; i++)
	{
		if((y[i]!=y[ln2-1-i]) && (i<=ln2-1-i))
		{
			ans++;
		}
	}
	return ans;
}

int main()
{
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	string l="";
	long long n;
	cin >> n;
	for(long long i=1; i<=n; i++)
	{
		long long a;
		char c;
		cin >> a >> c;
		for(long long i=1; i<=a; i++)
		{
			l += c;
		} 
	}
	cout << f(l);
	return 0;
}

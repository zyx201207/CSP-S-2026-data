#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen ("string.in","r",stdin);
	freopen ("string.out","w",stdout);
	string s , m;
	int n;
	long long b=0 , a , c=0;
	cin >> n;
	for (int i = 1;i <= n;i++)
	{
		cin >> a;
		b+=a;
		cin >> m[i];
		for (long long j = 1;j <= a;j++)
		{
			s += m[i];
		}
	}
	if (b%2==0)
	{
		for (long long i = 0;i < b/2;i++)
		{
			if (s[i]!=s[b-i-1])
			{
				c++;
			}
		}
	}
	else
	{
		for (long long i = 0;i < b-2;i++)
		{
			if (s[i]!=s[b-i-1])
			{
				c++;
			}
		}
	}
	cout << c;
}

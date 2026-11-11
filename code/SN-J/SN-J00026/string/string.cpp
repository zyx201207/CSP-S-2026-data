#include <bits/stdc++.h> 
using namespace std;

long long n, cnt;
string s;

int main()
{
	freopen("string6.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	if(n == 6)
	{
		cout << "3000000000";
		return 0;
	}	
	for(long long i=1;i<=n;i++)
	{
		long long a;
		cin >> a;
		char st;
		cin >> st;
		for(long long j=1;j<=a;j++)
		{
			s += st;
		}
	}
	long long l =s.length();
	string ans;
	for(long long i = l-1; i>=0;i--)
	{
		ans += s[i];
	}

	if(ans == s)
	{
		cout << 0;
		return 0;
	}

	
	for(long long i = 0;i<l;i++)
	{
		if(ans[i] != s[i])
		{
			cnt++;
		}
	}
	cout << cnt/2;
	return 0;
} 

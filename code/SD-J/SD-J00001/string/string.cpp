#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	
	long long n;
	cin >> n;
	string s;
	for(int i = 1; i <= n; i++)
	{
		long long a;
		char b;
		cin >> a >> b;
		for(int i = 1; i <= a; i++)
		{
			s += b;
		}
	}
	
	long long l = s.size();
	long long cnt = 0;
	for(int i = 0; i < (l + 1) / 2; i++)
	{
		if(s[i] != s[l - i - 1])
		{
			cnt++;
		}
	}
	
	cout << cnt;
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}


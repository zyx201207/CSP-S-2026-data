#include <bits/stdc++.h>
using namespace std;
int cnt = 0;
int main()
{
	preopen ("string.in","r",stdin);
	preopen ("string.out","w",stdout);
	string s;
	long long n;
	cin >> n;
	while (n--)
	{
		int a;
		string m;
		cin >> a >> m;
		for (int i = 1;i <= a;i++)
		{
			s += m;
		}
	}
	for (int i = 1;i <= s.size()/2;i++)
	{
		if (s[i] != s[s.size()-i+1])
		{
			cnt++;
		}
	}
	cout << cnt <<endl;
	return 0;
}

#include <bits/stdc++.h>
using namespace std;
int n;
string s;
int main ()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		int x;
		string a;
		cin >> x >> a;
		for (int i = 1; i <= x; i++)
		{
			s = s + a;
		}
	}
	long long cnt = 0;
	long long len = s.length() - 1;
	for (int i = 0; i <= (len + 1)/2; i++)
	{
		if(s[i] != s[len - i])
		{
			cnt++;
		}
	}
	cout <<cnt;
	return 0;
}

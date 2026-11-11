#include <bits/stdc++.h>
using namespace std;
int n,l = 0;
string s;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for (int i = 1 ; i <= n ; i++)
	{
		int a;
		char c;
		cin >> a >> c;
		for (int j = 1 ; j <= a ; j++)
		{
			s += c;
		}
		l += a;
	}
	int sum = 0;
	for (int i = 0 ; i <= n / 2 ; i++)
	{
		if (s[i] != s[l - i])
		{
			//cout << s[i] << ' ' << s[l-i] << endl;
			sum++;
		}
	}
	cout << sum;
	return 0;
}

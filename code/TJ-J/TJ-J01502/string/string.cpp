#include <bits/stdc++.h>
using namespace std;

int main()
{
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	string s = "";
	int n, a[200005];
	char c[200005];
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i] >> c[i];
		for (int j = 0; j < a[i]; j++)
		{
			s += c[i];
		}
	}
	long long L = s.length(), mint = 0;
	for (int i = 0; i < L/2; i++)
	{
		if (s[i] != s[L-1-i])
		{
			s[L+1-i] = s[i];
			mint++;
		}
	}
	cout << mint;
	return 0;
}

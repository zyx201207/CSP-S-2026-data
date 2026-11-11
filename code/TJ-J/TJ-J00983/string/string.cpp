#include <bits/stdc++.h>
using namespace std;
int n,s;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	char c;
	string x = "";
	cin >> n;
	for(int i = 1;i <= n;i++)
	{
		cin >> s >> c;
		for(int j = 1;j <= s;j++)
		{
			x += c;
		}
	}
	int sum = 0;
	int m = x.length();
	for (int i = 0;i < m/2;i++)
	{
		if (x[i] != x[m-i-1])
		{
			sum++;
		}
	}
	cout << sum;
	return 0;

}

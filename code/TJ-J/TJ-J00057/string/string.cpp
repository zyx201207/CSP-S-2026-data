#include <iostream>
using namespace std;
string s = "";
int n, l, a[200005];
char c[200005];
int main()
{
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i] >> c[i];
		l += a[i];
		for(int j = 1; j <= a[i]; j++)
		{
			s += c[i];
		}
	}
	int sum = 0;
	for(int i = 0; i < l / 2; i++)
	{
		if(s[i] != s[l - i - 1])
		{
			sum++;
		}
	}
	cout << sum;
	return 0;
}

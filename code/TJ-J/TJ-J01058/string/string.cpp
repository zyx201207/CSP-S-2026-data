#include <iostream>
using namespace std;

int a[200200];
char c[200020];

int main()
{
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	int n;
	cin >> n;
	string s = "";
	long long sum = 0;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i] >> c[i];
		sum += a[i];
		for (int j = 1; j <= a[i]; j++)
		{
			s += c[i];
		}
	}
	int cnt = 0;
	s = '?' + s;
	for (long long i = 1; i < sum / 2; i++)
	{
		if(s[i] != s[sum + 1 - i])
		{
			cnt++;
			s[sum + 1 - i] = s[i];
		}
	}
	cout << cnt;
	return 0;
}

#include <bits/stdc++.h>
using namespace std;
long long n, a[10005], lend = 0, num = 0;
string p;
int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		cin >> p;
		for (int j = 1; j <= a[i]; j++)
		{
			string s[i] = p;
		}
		lend += a[i];
	}
	int L = 0;
	int R = lend;
	while (L >= R)
	{
		if (s[L] - 10== s[R]-10)
		{
			L++;
			R--;
	    }
		else
		{
			s[R] = s[L];
			L++;
			R--;
			num += 1;
		}
	}
	cout << num;
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	return 0;
}

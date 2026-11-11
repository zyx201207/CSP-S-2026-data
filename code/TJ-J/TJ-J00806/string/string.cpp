#include<bits/stdc++.h>
using namespace std;
long long n, t, p = 1, q, sum, num;
char s[200005], a;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	while(n --)
	{
		cin >> t >> a;
		q = p + t - 1;
		for (long long i = p;i <= q;i ++)
		{
			s[i] = a;
			sum ++;
		}
		p = q + 1;
	}
	for (long long i = 1;i <= sum / 2;i ++)
	{
		if (s[i] != s[sum + 1 - i])
		{
			num ++;
		}
	}
	cout << ' ' << num;
	return 0;
}

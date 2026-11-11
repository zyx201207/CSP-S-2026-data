#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
	long long n,ans = 0,l = 0;
	cin >> n;
	long long a[n + 1],flag = 1;
	string b[n + 1];
	for (long long i = 1;i <= n;i ++){
		cin >> a[i];
		cin >> b[i];
	}
	for (long long i = 1;i <= n;i ++){
		l += a[i];
	}
	string c[l + 1];
	for (long long i = 1;i <= n;i ++){
		for (int j = 1;j <= a[i];j ++)
		{
			c[flag] = b[i];
			flag ++;
		}
	}
	for (long long i = 1;i <= l / 2;i ++)
	{
		if (c[i] != c[l + 1 - i])
		{
			ans ++;
		}
	}
	
	cout << ans;
	return 0;
 }

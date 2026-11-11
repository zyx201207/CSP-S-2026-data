#include<bits/stdc++.h>
using namespace	std;
const int N = 2e5 + 10;
int a[N];
char c[N];
int main()
{
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	int n;
	cin >> n;
	string s = "";
	long long l = 0;
	for(int i = 1; i <= n; i ++)
	{
		cin >> a[i] >> c[i];
		l += a[i];
		while(a[i] --) s += c[i];
	}
	long long ans = 0;
	for(int i = 0; i < l / 2; i ++)
	{
		if(s[i] != s[l - 1 - i]) ans ++;
	}
	cout << ans;
	return 0;
}
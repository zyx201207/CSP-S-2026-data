#include <bits/stdc++.h>
using namespace std;
long long n;
string s;
long long x;
int main()
{
	freopen("string3.in", "r", stdin);
	freopen("string.out", "w", stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin>> n;
	for(long long i = 1ll; i <= n; i++)
	{
		char a;
		cin >> x >> a;
		while(x--) s += a;
	}
	x = 0;
	for(long long i = 0ll; i < s.size() / 2; i++)
	{
		if(s[i] != s[s.size() - i - 1]) x++;
	}
	cout << x;
	return 0;
}

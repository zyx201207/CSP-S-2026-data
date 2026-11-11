#include<bits/stdc++.h>
using namespace std;
long long x;
string s = "", si;
int n, ans;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for(int i = 1;i <= n;i++)
	{
		cin >> x;
		cin >> si;
		for(int i = 1;i <= x;i++)
		{
			s += si;
		}
	}
	for (int i = 0;i < s.length() / 2;i++)
	{
		if (s[i] != s[s.length()-i-1])
		{
			ans++;
		}
	}
	cout << ans;
	return 0;
}
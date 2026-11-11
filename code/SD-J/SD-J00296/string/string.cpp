#include <bits/stdc++.h>
using namespace std;
long long n;
string s;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for(long long i = 1;i <= n;i++)
	{
		long long x;
		char c;
		cin >> x >> c;
		for(long long j = 1;j <= x;j++)
		{
			s += c;
		}
	}
	long long cnt = 0;
	long long l = 0,r = s.size() - 1;
	while(l < r)
	{
		if(s[l] != s[r])
		{
			cnt++;
		}
		l++;
		r--;
	}
	cout <<cnt;
	return 0;
}


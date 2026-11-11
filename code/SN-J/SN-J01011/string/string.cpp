#include <bits/stdc++.h>
using namespace std;
long long  n,a[100005],c[100005],cnt;
string s,s2;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for(int i = 1;i <= n;i++)
	{
		cin >> a[i];
		cin >> c[i];
	}
	for(int i =1;i <= c[i];i++)
	{
		s += a[i];
	}
	for(int i = s.length()-1;i >= 0;i--)
	{
		s2 += s[i];
	}
	if(s2 == s)
		cout << 0;
	for(int i = 0;i <= s.length()-1;i++)
	{
		if(s[i] != s[n-i+1])
		{
			cnt++;
		}
	}
	cout << cnt;
	return 0;
}

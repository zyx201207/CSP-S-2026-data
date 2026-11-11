#include <bits/stdc++.h>
using namespace std;
long long n,a[20005],sum;
string b[20005];
string s;
int cnt;
bool check(string t)
{
	int mid;
	string s1;
	for (int i = t.length()-1;i>=0;i--)
	{
		s1 += t[i];
	}
	if (t == s1) return true;
	return false;
	
}
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for (int i = 1;i<=n;i++)
	{
		cin >> a[i] >> b[i];
	}
	for (int i = 1;i<=n;i++)
	{
		for (int j = 1;j<=a[i];j++)
		{
			s+=b[i];
		}
	}
	if (check(s)) cout << 0;
	else
	{
		for (int i = 0;i<=s.length()/2;i++)
		{
			if (s[i]!=s[s.length()-i-1]) cnt++;
		}
		cout << cnt;
	}
	return 0;
}

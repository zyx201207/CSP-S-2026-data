#include <bits/stdc++.h>
using namespace std;
int n,a[1000005];
char c[1000005];
string s;
bool huiwen()
{
	int cnt = 0;
	int l = s.length();
	for (int i = 1;i <= n;i++)
	{
		if (s[i] == s[l+1-i])
		{
			cnt++;
		}
	}
	if (cnt == n) return 1;
	else return 0;
}
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int cou = 0;
	cin >> n;
	for (int i = 1;i <= n;i++)
	{
		cin >> a[i];
		cin >> c[i];
	}
	for (int i = 1;i <= n;i++)
	{
		s[i] = c[i];
	} 
	int ll = s.length();
	for (int i = 1;i <= n;i++)
	{
		if (huiwen())
		{
			cout << 0;
			return 0;
		}
		else 
		{
			if (s[i] != s[ll+1-i])
			{
				cou++;
			    s[ll+1-i] = s[i];
			}
		}
	}
	cout << cou;
	return 0;
}

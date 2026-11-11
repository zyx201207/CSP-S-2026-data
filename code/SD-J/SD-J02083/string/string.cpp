#include <bits/stdc++.h>
using namespace std;

long long a[2000005],cnt,ans;
char c[2000005];
string s;

int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n;
	cin >> n;
	for(int i = 1;i <= n;i++)
	{
		cin >> a[i] >> c[i];
		if(c[i] == c[1]) cnt++;
		for(int j = 1;j <= a[i];j++)
		{
			s += c[i];
		}
	}
	if(cnt == n)
	{
		cout << 0;
		return 0;
	}
	long long x;
	for(int i = 0;i < floor(s.size() / 2);i++)
	{
		if(s[i] != s[s.size() - x]) ans++;
		x++;
	}
	cout << ans;
	return 0;
} 

#include <bits/stdc++.h>
using namespace std;
int n,a[200005],cnt=0;
char s[200005];
set<char> k;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i] >> s[i];
		k.insert(s[i]);
	}
	if(n == 1)
	{
		cout << 0;
		return 0;
	}
	if(n == 2&&s[1] != s[2])
	{
		sort(a,a + n + 1);
		cout << a[1];
		return 0;
	}
	for (int i = 1; i <= n; i++)
	{
		if(s[i] == s[i + 1] && i + 1 <= n)
		{
			cnt++;
		}
	}
	if(cnt == n - 1)
	{
		cout << 0;
		return 0;
	}
	sort(a + 1,a + n + 1);
	if(a[n] == 1)
	{
		if(k.size() % 2 == 0)
		{
			cout << k.size() - 1;
		}
		else
		{
			cout << k.size() - 2;
		}
		return 0;
	}
	return 0;
}

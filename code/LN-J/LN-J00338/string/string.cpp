#include<bits/stdc++.h>
using namespace std;

int n, ans;
string s;

int main()
{
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	for(int i = 0; i < n; i++)
	{
		int a;
		char c;
		cin >> a >> c;
		for(int i = 0; i < a; i++)
		{
			s += c;
		}
	}
	int p = 0, q = s.length() - 1;
	while(p <= q)
	{
		if(s[p] == s[q])
		{
			p++;
			q--;
		}
		else
		{
			ans++;
			s[q] = s[p];
		}
	}
	cout << ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

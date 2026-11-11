#include<bits/stdc++.h>
using namespace std;
int ans;
string s;
int main()
{
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	int n;
	cin >> n;
	int k = 1;
	for(int i = 1; i <= n; i++)
	{
		int a;
		char c;
		cin >> a >> c;
		while(a--)
		{
			s[k] = c;
			k++;
		}
	}
	int l = 1, r = k - 1;
	while(l <= r)
	{
		if(s[l] != s[r])
		{
			ans++;
		}
		l++;
		r--;
	}
	cout << ans;
	return 0;
}

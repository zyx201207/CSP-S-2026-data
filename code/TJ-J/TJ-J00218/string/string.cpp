#include <bits/stdc++.h>
using namespace std;
int n, a[200005];
string s[200005];
int main()
{
	freopen("sting.in", "r", stdin);
	freopen("sting.out", "w", stdout);
	cin >> n;
	if(n <= 1)
	{
		cout << "0";
		return 0;
	}
	for(int i = 0;i < n;i++)
		cin >> a[i] >> s[i];
	if(n <= 2)
	{
		if(s[0] != s[1])
			cout << min(a[0], a[1]);
		else
			cout << 0;
		return 0;
	}
	return 0;
}

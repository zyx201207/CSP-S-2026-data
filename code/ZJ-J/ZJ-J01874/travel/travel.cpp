#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	string a, b, c, d;
	cin >> a >> b >> c >> d;
	if(a == c) cout << 1;
	else 
	{
		cout << 0 << 0 << 0 << 0;
		return 0;
	}
	string s = "", k = "";
	for(int i = 0; i < 2; i ++) s += b[i];
	for(int i = 0; i < 2; i ++) k += d[i];
	if(k == s) cout << 1;
	else 
	{
		cout << 0 << 0 << 0;
		return 0;
	}
	if(b[2] == 'A' || b[2] == 'B' || b[2] == 'C')
	{
		if(d[2] == 'A' || d[2] == 'B' || d[2] == 'C')
		{
			cout << 1;
			if(!((d[2] == 'C' && b[2] == 'A') || (d[2] == 'A'&& b[2] == 'C'))) cout << 1;
			else cout << 0;
		}
		else {
			cout << 0 << 0;
		}
	}
	if(b[2] == 'D' || b[2] == 'E')
	{
		if(d[2] == 'D' || d[2] == 'E')
		{
			cout << 1 << 1;
		}
		else cout << 0 << 0;
	}
	return 0;
}
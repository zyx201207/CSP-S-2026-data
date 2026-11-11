#include<bits/stdc++.h>
using namespace std;
string c, s, x, y;
int main()
{
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin >> c >> s >> x >> y;
	if(c != x)
	{
		cout << "0000" << endl;
	}
	else if(s[0] != y[0] || s[1] != y[1])
	{
		cout <<"1000" << endl;
	}
	else
	{
		if(s[2] > y[2])
		{
			char c = s[2];
			s[2] = y[2];
			y[2] = c;
		}
		if(s[2] + 1 == y[2] && s[2] != 'C') cout <<"1111" << endl;
		else if(s[2] != 'C') cout <<"1110" << endl;
		else cout << "1100" << endl;
	}
	return 0;
}

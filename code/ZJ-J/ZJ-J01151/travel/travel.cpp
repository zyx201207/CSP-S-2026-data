#include <bits/stdc++.h>
using namespace std;

int main()
{
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	string a, b, c, d;
	cin >> a >> b >> c >> d;
	if(a == c)cout << "1";
	else
	{
		cout << "0000";
		return 0;
	} 
	if(b[0] + b[1] != d[0] + d[1])
	{
		cout << "000";
		return 0;
	}
	else
	{
		cout << "1";
		if((b[2] <= 'C' && 'A' <= b[2] && 'A' <= d[2] && d[2] <= 'C') || (b[2] == 'F'  && d[2] == 'D') || (b[2] == 'D'  && d[2] == 'F'))
		{
			cout << "1";
			if(abs(b[2] - d[2]) == 1 || (b[2] == 'F'  && d[2] == 'D') || (b[2] == 'D'  && d[2] == 'F'))cout << "1";
			else cout << "0";
		}
		else
		{
			cout << "00";
			return 0;
		}
	}
	return 0;
}
//Trick||Treat!

#include<bits/stdc++.h>
using namespace std;
int n, m, a, b;
char c, d;
int main()
{
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin >> n >> m >> c >> a >> b >> d;
	if(n == a)cout << 1;
	else
	{
		cout << "0000";
		return 0;
	}
	if(m == b)cout << 1;
	else 
	{
		cout << "000";
		return 0;
	}
	if((c >= 'A' && c <= 'C' && d >= 'A' && d <= 'C') || ((c == 'D' && d == 'F') || (d == 'D' && c == 'F')))cout << 1;
	else
	{
		cout << "00";
		return 0;
	} 
	if((c == 'A' && d == 'B') || (c == 'B' && d == 'A') || (c == 'B' && d == 'C') || (c == 'C' && d == 'B') || (c == 'D' && d == 'F') || (c == 'F' && d == 'D'))cout << 1;
	else cout << 0;

	return 0;
}


#include <bits/stdc++.h>
using namespace std;

struct Node
{
	string c;
	string s;
} pos[2];

bool getSide(char c)
{
	if(c >= 'A' && c <= 'C')
		return true;
	return false;
}

int main ()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
#ifndef DEBUG
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
#endif // DEBUG
	for(int i = 0; i < 2; i++)
		cin >> pos[i].c >> pos[i].s;
	if(pos[0].c != pos[1].c)
	{
		cout << "0000\n";
		return 0;
	}
	cout << 1;
	if(pos[0].s[0] != pos[1].s[0] || pos[0].s[1] != pos[1].s[1])
	{
		cout << "000\n";
		return 0;
	}
	cout << 1;
	if(getSide(pos[0].s[2]) != getSide(pos[1].s[2]))
	{
		cout << "00\n";
		return 0;
	}
	cout << 1;
	if(abs(pos[0].s[2] - pos[1].s[2]) > 1)
	{
		cout << "0\n";
		return 0;
	}
	cout << "1\n";

	return 0;
}


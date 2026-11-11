#include<bits/stdc++.h>
using namespace std;
bool Check1(char, char);
bool Check2(char, char);
int main()
{
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	string s, t, x, y;
	cin >> s >> t >> x >> y;
	int a = (t[0] - '0') * 10 + (t[1] - '0'), c = (y[0] - '0') * 10 + (y[1] - '0');
	char b = t[2], d = y[2];
	if(s == x) cout << 1;
	else cout << 0;
	if(s == x && a == c) cout << 1;
	else cout << 0;
	if(s == x && a == c && Check1(b, d)) cout << 1;
	else cout << 0;
	if(s == x && a == c && Check1(b, d) && Check2(b, d)) cout << 1;
	else cout << 0;
	return 0;
}
bool Check1(char x, char y)
{
	if(x <= 'C' && y <= 'C') return true;
	else if(x >= 'D' && y >= 'D') return true;
	return false;
}
bool Check2(char x, char y)
{
	if(x > y) swap(x, y);
	if(x == 'A' && y == 'B') return true;
	else if(x == 'B' && y == 'C') return true;
	else if(x == 'D' && y == 'F') return true;
	return false;
}

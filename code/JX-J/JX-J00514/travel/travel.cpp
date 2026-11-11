#include <bits/stdc++.h>
using namespace std;

int pl(string s)
{
	char ch = s[2];
	if (ch == 'A') return 1;
	if (ch == 'B') return 2;
	if (ch == 'C') return 3;
	if (ch == 'D') return 5;
	if (ch == 'F') return 6;
	else return -1;
}

int id(string s)
{
	char c1 = s[1], c2 = s[0];
	int x1 = (int)(c1 - '0');
	int x2 = (int)(c2 - '0');
	return 10 * x2 + x1;
}

bool sam(int a, int b)
{
	if (a < 4 && b < 4) return 1;
	if (a > 4 && b > 4) return 1;
	return 0;
}

bool nxt(int a, int b)
{
	return (abs(a - b) == 1);
}

int main()
{
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	
	int x1, x2; string s1, s2;
	cin >> x1 >> s1 >> x2 >> s2;
	bool f1 = 0, f2 = 0, f3 = 0, f4 = 0;
	
	f1 = (x1 == x2);
	f2 = (id(s1) == id(s2)) & f1;
	f3 = sam(pl(s1), pl(s2)) & f2;
	f4 = nxt(pl(s1), pl(s2)) & f3;
	
	cout << f1 << f2 << f3 << f4;
	return 0;
}

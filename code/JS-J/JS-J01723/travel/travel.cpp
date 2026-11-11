#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MAXN = 1e5 + 5;
ll a, b;
string aa, bb;
char a2, b2;
ll a1, b1;
unordered_map<char, bool> mp;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin >> a >> aa >> b >> bb;
	a2 = aa[2], b2 = bb[2];
	if (a2 == 'F')
	{
		a2--;
	}
	if (b2 == 'F')
	{
		b2--;
	}
	a1 = ((aa[0] - '0') * 10) + (aa[1] - '0');
	b1 = ((bb[0] - '0') * 10) + (bb[1] - '0');
	mp['A'] = 0;
	mp['B'] = 0;
	mp['C'] = 0;
	mp['D'] = 1;
	mp['E'] = 1;
	if (a != b)
	{
		cout << "0000\n";
		return 0;
	}
	else if (a1 != b1)
	{
		cout << "1000\n";
		return 0;
	}
	else if (mp[a2] != mp[b2])
	{
		cout << "1100\n";
		return 0;
	}
	else if (abs(a2 - b2) > 1)
	{
		cout << "1110\n";
		return 0;
	}
	else
	{
		cout << "1111\n";
		return 0;
	}

	return 0;
}
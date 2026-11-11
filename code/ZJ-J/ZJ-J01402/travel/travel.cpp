#include <bits/stdc++.h>
using namespace std;

int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	string c1,s1,c2,s2;
	cin >> c1 >> s1 >> c2 >> s2;
	if(c1 != c2)
	{
		cout << "0000";
		return 0;
	}
	cout << 1;
	int a = (s1[0] - '0') * 10 + s1[1] - '0';
	int b = (s2[0] - '0') * 10 + s2[1] - '0';
	if(a != b)
	{
		cout << "000";
		return 0;
	}
	cout << 1;
	char x = s1[2],y = s2[2];
	if((x > 'C' && y <= 'C') || (y > 'C' && x <= 'C'))
	{
		cout << "00";
		return 0;
	}
	cout << 1;
	if(abs(x-y) == 1 && min(x,y) != 'C')
	{
		cout << 1;
		return 0;
	}
	cout << 0;
	return 0;
}

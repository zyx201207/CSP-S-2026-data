#include<bits/stdc++.h>
using namespace std;

int check(char x)
{
	if(x >= 'A' && x <= 'C') return 1;
	else if(x == 'D' || x == 'F') return 2;
}
int main()
{
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	string c1, s1, c2, s2;
	cin >> c1 >> s1 >> c2 >> s2;
	if(c1 == c2)
	{
		cout << "1";
		string a = s1.substr(0, 2), b = s2.substr(0, 2);
		if(a == b)
		{
			cout << "1";
			if(check(s1[2]) == check(s2[2]))
			{
				cout << "1";
				if(abs(s1[2] - s2[2]) == 1) cout << "1";
				else cout << "0";
			}
			else cout << "00";
		}
		else cout << "000";
	}
	else cout << "0000";
	puts("");
	return 0;
}

#include <bits/stdc++.h>
using namespace std;
string a = "ABC", b = "DF";
int main()
{
	freopen("travel.in", "r", stdin);
	freopen("travel.out","w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	string c1, s1, c2, s2;
	cin >> c1 >> s1 >> c2 >> s2;
	if (c1 == c2)
	{
		cout << "1";
		string a1 = s1.substr(0, 2);
		string b1 = s1.substr(2, 1);
		string a2 = s2.substr(0, 2);
		string b2 = s2.substr(2, 1);
		if (a1 == a2) 
		{
			cout << "1";
			int checka1 = a.find(b1);
			int checka2 = a.find(b2);
			int checkb1 = b.find(b1);
			int checkb2 = b.find(b2);
			if (checka1 != -1 && checka2 != -1) 
			{
				cout << "1";
				if (abs(checka1 - checka2) == 1) cout << "1";
				else cout << "0";
			}
			else if (checkb1 != -1 && checkb2 != -1) 
			{
				cout << "1"; 
				if (abs(checkb1 - checkb2) == 1) cout << "1";
				else cout << "0";
			}
			else cout << "00" << endl;
		}
		else cout << "000" << endl;
	}
	else cout << "0000" << endl;
	return 0;
} 

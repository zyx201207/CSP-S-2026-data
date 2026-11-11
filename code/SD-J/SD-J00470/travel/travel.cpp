#include<bits/stdc++.h>
using namespace std;
#define ll long long
string s[4] = {"AB", "BC", "CB", "BA"};
int main()
{
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	string c1, s1, c2, s2;
	cin >> c1 >> s1 >> c2 >> s2;
	if(c1 == c2)
	{
		cout << "1";
		int r1 = (s1[0] - '0') * 10 + s1[1] - '0';
		int r2 = (s2[0] - '0') * 10 + s2[1] - '0';
		if(r1 == r2) cout << "1";
		else
		{
			cout << "000";
			return 0;
		}
		char z1 = s1[2];
		char z2 = s2[2];
		string w1 = "";
		string w2 = "";
		w1 += z1;
		w2 += z2;
		if(z1 <= 'F' && z1 >= 'D' && z2 <= 'F' && z2 >= 'D')
		{
			cout << "11";
			return 0;
		}
		else if(z1 <= 'C' && z1 >= 'A' && z2 <= 'C' && z2 >= 'A')
		{
			cout << "1";
			bool shifou = 0;
			for(string ss : s)
			{
				if(w1 + w2 == ss) shifou = 1;
			}
			if(shifou) cout << "1";
			else cout << "0";
			return 0;
		}
		else cout << "00";
	}
	else cout << "0000";
	return 0;
}

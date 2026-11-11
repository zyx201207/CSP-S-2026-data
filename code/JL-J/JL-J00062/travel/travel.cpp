#include <bits/stdc++.h>
using namespace std;


string s1, c1, c2, s2;
bool b = false;
bool b1 = false;

int main()
{
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin >> c1 >> s1 >> c2 >> s2;
	string S, C;
	S = s1[1];
	C = s2[1];
	if(c1 == c2)
		cout << "1";
	else if(c1 != c2)
		cout << "0";
	if(c1 == c2 && S == C)
		cout << "1";
	else cout << "0";
	if(c1 == c2 && S == C)
	{
		if(s1[2] == 'A' || s1[2] == 'B' || s1[2] == 'C')
		{
			b = true;
		}
		else if(s1[2] == 'D' || s1[2] == 'F') b = false;
		if(s2[2] == 'A' || s2[2] == 'B' || s2[2] == 'C')
		{
			b1 = true;
		} 
		else if(s2[2] == 'D' || s2[2] == 'F') b1 = false;
		if(b == b1)
			cout << "1";
		if(b != b1)
			cout << "0";
	}
	else cout << "0";
	if(s1[2] == 'A' && s2[2] == 'B')
		cout << "1";
	else if(s1[2] == 'B' && s2[2] == 'C') 
		cout << "1";
	else if(s2[2] == 'D' && s2[2] == 'F')
		cout << "1";
	else cout << "0";
	return 0;
}

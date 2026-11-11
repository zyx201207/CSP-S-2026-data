#include <bits/stdc++.h>
using namespace std;
const int MX = 1e5;
string  c1, s1, c2, s2;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> c1 >> s1 >> c2 >> s2;
	if(c1 == c2)
	{
		cout << 1;
		
	}
	else 
	{
		cout << "0000" << "\n";
		return 0;
	}
	if(s1[0] == s2[0] && s1[1] == s2[1])
	{
		cout << 1;
	}
	else
	{
		cout << "000" << "\n";
		return 0;
	}
	if(s1[2] >= 'A' && s1[2] <= 'C' && s2[2] <= 'C' && s2[2] >= 'A'  || s1[2] == 'F' && s2[2] =='D' || s1[2] == 'D' && s2[2] == 'F')
	{
		cout << 1;
	}
	else
	{
		cout << "00" << "\n";
		return 0;
	}
	int a,b;
	a = s1[2];
	b = s2[2];
	if(abs(a - b) == 1)
	{
		cout << 1;
	}
	else
	{
		cout << "0" << "\n";
	}
	return 0;
 } 

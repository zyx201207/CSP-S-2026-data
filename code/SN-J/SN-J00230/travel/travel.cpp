#include<bits/stdc++.h>
using namespace std;
string c1, s1, c2, s2;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin >> c1 >> s1 >> c2 >> s2;
	for(int i = 0; i < 1; i++)
	{
		if (c1 == c2)
		{
			cout << "1";
		}
		else
		{
			cout << "0000";
			break;
		}
		if(s1[0] == s2[0] && s1[1] == s2[1])
		{
			cout << "1";
		}
		else
		{
			cout << "000";
			break;
		}
		if((s1[2] == 'C' || s1[2] == 'D') && (s2[2] == 'C' || s2[2] == 'D'))
		{
			cout << "00";
			break;
		}
		else
		{
			cout << "1";
		}
		if((s1[2] == 'C' || s1[2] == 'A') && (s2[2] == 'C' || s2[2] == 'A'))
		{
			cout << "0";
		}
		else
		{
			cout << "1";
		}
	}
	return 0;
} 

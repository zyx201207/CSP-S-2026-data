#include<bits/stdc++.h> 
using namespace std;
int main()
{
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
    int c_1, c_2;
    string s_1, s_2;
	cin >> c_1 >> s_1 >> c_2 >> s_2;
	c_1 = c_2;
	s_1[2] == s_2[2] && s_1[1] == s_2[1];
	(s_1[3] == 'A' && s_2[3] == 'A'+ 1) || (s_1[3] == 'B' && s_2[3] == 'B'+ 1) || (s_1[3] == 'D' && s_2[3] == 'D'+ 2);
	if(c_1 == c_2)
	{
		cout << 1;
	}
	else
	{
		cout << 0;
	}
	if(s_1[3] == s_2[3])
	{
		cout << 1;
	}
	else
	{
		cout << 0;
	}
	if(s_1[2] == s_2[2] && s_1[1] == s_2[1])
	{
		cout << 1;
	}
	else
	{
		cout << 0;
	}
	if((s_1[3] == 'A' && s_2[3] == 'A'+ 1) || (s_1[3] == 'B' && s_2[3] == 'B'+ 1) || (s_1[3] == 'D' && s_2[3] == 'D'+ 2))
	{
		cout << 1;
	}
	else if((s_2[3] == 'A' && s_1[3] == 'A'+ 1) || (s_2[3] == 'B' && s_1[3] == 'B'+ 1) || (s_2[3] == 'D' && s_1[3] == 'D'+ 2))
	{
		cout << 1;
	}
	else
	{
		cout << 0;
	}
	
	
	return 0;
}

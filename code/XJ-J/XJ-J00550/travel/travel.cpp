#include <bits/stdc++.h>
using namespace std;
string s_1, s_2, s_3, s_4;
int main()
{
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin>>s_1>>s_2>>s_3>>s_4;
	if (s_1 == "01" || s_1 == "16" || s_3 == "01" || s_3 == "16")
	{
		cout<<"0000";
		return 0;
	}
	if (s_1 == s_3)
	{
		cout<<"1";
	}
	else 
	{
		cout<<"0000";
		return 0;
	}
	if (s_2[0] == s_4[0] && s_2[1] == s_4[1])
	{
		cout<<"1";
	}
	else 
	{
		cout<<"000";
		return 0;
	}
	if (((s_2[2] >= 'A' && s_2[2]<='C') && (s_4[2] >= 'A' && s_4[2] <= 'C')) || ((s_2[2] >= 'D' && s_2[2]<='F') && (s_4[2] >= 'D' || s_4[2] <= 'F')))
	{
		cout<<"1";
	}
	else
	{
		cout<<"00";
		return 0;
	}
	if (s_4[2] - s_2[2] == 1 || s_2[2] - s_4[2] == 1 || ((s_2[2] >= 'D' && s_2[2]<='F') && (s_4[2] >= 'D' || s_4[2] <= 'F')))
	{
		cout<<"1";
	}
	else 
	{
		cout<<"0";
		return 0;
	}
	return 0;
}
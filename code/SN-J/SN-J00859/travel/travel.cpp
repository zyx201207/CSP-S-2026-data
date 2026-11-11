#include <bits/stdc++.h>
using namespace std;
string c1,c2,s1,s2;
string num(string s)
{
	string ans;
	ans[0] = s[0];
	ans[1] = s[1];
	return ans;
}
char cha(string s)
{
	return s[2];
}
bool check(char x,char y)
{
	if(x == 'A')
	{
		if(y == 'B' || y == 'C') return 1;
	}
	if(x == 'B')
	{
		if(y == 'A' || y == 'C') return 1;
	}
	if(x == 'C')
	{
		if(y == 'B' || y == 'A') return 1;
	}
	if(x == 'D')
	{
		if(y == 'F') return 1;
	}
	if(x == 'F')
	{
		if(y == 'D') return 1;
	}
	return 0;
}
bool check2(char x,char y)
{
	if(x == 'A')
	{
		if(y == 'B') return 1;
	}
	if(x == 'B')
	{
		if(y == 'A' || y == 'C') return 1;
	}
	if(x == 'C')
	{
		if(y == 'B') return 1;
	}
	if(x == 'D')
	{
		if(y == 'F') return 1;
	}
	if(x == 'F')
	{
		if(y == 'D') return 1;
	}
	return 0;
}
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> c1 >> s1 >> c2 >> s2;
	if(c1 == c2) cout << 1;
	else
	{
		cout << "0000";
		return 0;
	}
	if(s1[0] == s2[0] && s1[1] == s2[1]) cout << 1;
	else
	{
		cout << "000";
		return 0;
	}
	if(check(cha(s1),cha(s2))) cout << 1;
	else
	{
		cout << "00";
		return 0;
	}
	if(check2(cha(s1),cha(s2))) cout << 1;
	else cout << 0;
	return 0;
}

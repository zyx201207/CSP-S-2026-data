#include<bits/stdc++.h>
using namespace std;
char s1[3], s2[4], c1[3], c2[4];
bool check_1(char ss1[], char ss2[])
{
	if(ss1[1] != ss2[1]) return 0;
	if(ss1[2] != ss2[2]) return 0;
	return 1;
}
bool check_2(char ss1[], char ss2[])
{
	if(ss1[1] != ss2[1]) return 0;
	if(ss1[2] != ss2[2]) return 0;
	return 1;
}
bool check_3(char ss1[], char ss2[])
{
	bool a, b;
	if((ss1[3] == 'A') || (ss1[3] == 'B') || (ss1[3] == 'C')) a = 1;
	else a = 0;
	if((ss2[3] == 'A') || (ss2[3] == 'B') || (ss2[3] == 'C')) b = 1;
	else b = 0;
	if(a == b) return 1;
	return 0;
}
bool check(char ss1[], char ss2[])
{
	if(ss1[3] == 'A')
	{
		if(ss2[3] == 'B') return 1;
		return 0;
	}
	if(ss1[3] == 'B') return 1;
	if(ss1[3] == 'C')
	{
		if(ss2[3] == 'B') return 1;
		return 0;
	}
	if(ss1[3] == 'D')
	{
		if(ss2[3] == 'F') return 1;
		return 0;
	}
	if(ss1[3] == 'F')
	{
		if(ss2[3] == 'D') return 1;
		return 0;
	}
}
int main()
{
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	scanf("%s", s1 + 1);
	scanf("%s", s2 + 1);
	scanf("%s", c1 + 1);
	scanf("%s", c2 + 1);
	if(check_1(s1, c1))
		cout << 1;
	else
	{
		cout << "0000";
		return 0;
	}
	if(check_2(s2, c2))
		cout << 1;
	else
	{
		cout << "000";
		return 0;
	}
	if(check_3(s2, c2))
		cout << 1;
	else
	{
		cout << "00";
		return 0;
	}
	if(check(s2, c2))
		cout << 1;
	else cout << 0;
	return 0;
} 

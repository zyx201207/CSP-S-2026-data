#include <bits/stdc++.h>
#define yes 1
#define no 0
using namespace std;

int main()
{
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);

	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	int s1hang=0,s2hang=0;
	s1hang = (s1[0] - '0') *10 + (s1[1] - '0');
	s2hang = (s2[0] - '0') *10 + (s2[1] - '0');

	if(c1==c2)
	{
		cout<<yes;
	}
	else
	{
		cout<<no<<no<<no<<no;
		exit(0);
	}

	if(s1hang == s2hang)
	{
		cout<<yes;
	}
	else
	{
		cout<<no<<no<<no;
		exit(0);
	}
	bool tongce =((s1[2] == 'F' && s2[2] == 'D') || (s1[2] == 'D' && s2[2] == 'F')) || ( (s1[2] == 'A' && (s2[2] == 'B' || s2[2] == 'C')) || (s1[2] == 'B' && (s2[2] == 'A' || s2[2] == 'C')) || (s1[2] == 'C' && (s2[2] == 'B' || s2[2] == 'A')));
	if(tongce)
	{
		cout<<yes;
	}
	else
	{
		cout<<no<<no;
		exit(0);
	}

	bool xianglin = (s1[2] == 'F' && s2[2] == 'D') || (s1[2] == 'D' && s2[2] == 'F') || (s1[2]=='A' && s2[2] == 'B') || (s1[2]=='B' && s2[2] == 'A') || (s1[2] =='C' && s2[2] == 'B') || (s1[2] =='B' && s2[2] == 'C');
	if(xianglin)
	{
		cout<<yes;
	}
	else
	{
		cout<<no;
	}
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
string c1, s1, c2, s2;
int main()
{
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin >> c1 >> s1 >> c2 >> s2;
	if(c1==c2)
		cout << "1";
	else
	{
		cout << "0000";
		return 0;
	}
	if(s1[0]==s2[0]&&s1[1]==s2[1])
		cout << "1";
	else
	{
		cout << "000";
		return 0;
	}
	int a=s1[2]-'A';
	int b=s2[2]-'A';
	if(((a!=2||b!=3)&&(a!=3||b!=2))&&((a-b)==1||(a-b)==-1||(a==0&&b==2)||(a==2&&b==0)||(a==3&&b==5)||(a==5&&b==3)))
		cout << "1";
	else
	{
		cout << "00";
		return 0;
	}
	if((a-b)==1||(a-b)==-1||(a==3&&b==5)||(a==5&&b==3))
		cout << "1";
	else
		cout << "0";
	return 0;
}

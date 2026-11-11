#include<bits/stdc++.h>
using namespace std;
int a[10];
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","W",stdout);
	string c1,c2,s1,s2;
	cin >> c1 >>s1>>c2>>s2;
	if(c1==c2)//≥µœ· 
	{
		a[1]==1;
	}
	else
	{
		cout << "0000";
		return 0;
	}
	if(s1[0]+s1[1]==s2[0]+s2[1])//≈≈ 
	{
		a[2]==1;
	}
	else
	{
		cout <<"1000";
		return 0;
	}
	if(((s1[2]=='A'||s1[2]=='B'||s1[2]=='C')&&(s2[2]=='A'||s2[2]=='B'||s2[2]=='C')) || ((s1[2]=='D'||s1[2]=='F')&&(s2[2]=='D'||s2[2]=='F')))              
	{
			a[3]==1;
	}
	else//≤‡
	{
			cout << "1100";
			return 0;
	}
	if((s1[2]=='A'&&s2[2]=='B')||(s1[2]=='B'&&s2[2]=='C')||(s1[2]=='B'&&s2[2]=='A') ||(s1[2]=='C'&&s2[2]=='B')||(s1[2]=='D'&&s2[2]=='F')||(s1[2]=='F'&&s2[2]=='D'))
	{
		a[4]==1;
	}
	else
	{
		cout << "1110";
		return 0;
	}
	cout << "1111";
	return 0;
} 

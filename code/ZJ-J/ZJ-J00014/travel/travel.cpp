#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin >> c1 >> s1 >> c2 >> s2;
	if(c1!=c2)
	{
		cout << "0000";
		return 0;
	}
	char p1=s1[0],p2=s2[0],p3=s1[1],p4=s2[1];
	if(p1!=p2||p3!=p4)
	{
		cout << "1000";
		return 0;
	}
	char q1=s1[2],q2=s2[2];
	if((q1=='A'&&q2=='B')||(q1=='A'&&q2=='C')||(q1=='B'&&q2=='C')||(q1=='B'&&q2=='A')||(q1=='C'&&q2=='A')||(q1=='C'&&q2=='B')||(q1=='D'&&q2=='F')||(q1=='F'&&q2=='D'))
	{
		if((q1=='A'&&q2=='B')||(q1=='B'&&q2=='C')||(q1=='B'&&q2=='A')||(q1=='C'&&q2=='B')||(q1=='D'&&q2=='F')||(q1=='F'&&q2=='D'))
		{
			cout << "1111";
			return 0;
		}
		else
		{
			cout << "1110";
		}
	}
	else
	{
		cout << "1100";
		return 0;
	}
}
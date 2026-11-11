#include<iostream>
#include<cstdio>
using namespace std;
int main(){
	freopen("travel1.in","r",stdin);
	freopen("travel1.out","w",stdout);
	string c1,s1,c2,s2;
	cin >> c1 >> s1 >> c2 >> s2;
	int dai1,dai2;
	if(c1==c2)
	{
		cout << "1";
		if(s1[0]==s2[0] && s1[1]==s2[1])
		{
			cout << "1";
			if(s1[2]=='A' || s1[2]=='B' || s1[2]=='C')
			{
				dai1=1;
			}
			if(s1[2]=='D' || s1[2]=='F')
			{
				dai1=2;
			}
			if(s2[2]=='A' || s2[2]=='B' || s2[2]=='C')
			{
				dai2=1;
			}
			if(s2[2]=='D' || s2[2]=='F')
			{
				dai2=2;
			}
			if(dai1==dai2)
			{
				cout << '1';
				if(s1[2]=='D' && s2[2]=='F' || s1[2]=='F' && s2[2]=='D')
				{
					cout << "1";
				}
				if(s1[2]=='A' && s2[2]=='B' || s1[2]=='B' && s2[2]=='A')
				{
					cout << "1";
				}
				if(s1[2]=='B' && s2[2]=='C' || s1[2]=='C' && s2[2]=='B')
				{
					cout << "1";
				}
				if(s1[2]=='A' && s2[2]=='C' || s1[2]=='C' && s2[2]=='A')
				{
					cout << "0";
				}
				
			}
			else
			{
				cout << "00";
			}
		}
		else
		{
			cout << "000";
		}
	}
	else
	{
		cout << "0000";
	}
}

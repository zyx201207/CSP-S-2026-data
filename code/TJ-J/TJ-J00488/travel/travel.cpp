#include<bits/stdc++.h>
using namespace std;

int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin >> c1 >> s1 >> c2 >> s2;
	if(c1==c2)
	{
		cout << '1';
		if(s1[0]==s2[0]&&s1[1]==s2[1])
		{
			cout << '1';
			bool a=s1[2]=='A'&&s2[2]=='B';
			bool b=s1[2]=='B'&&s2[2]=='C';
			bool c=s1[2]=='A'&&s2[2]=='C';
			bool d=s1[2]=='D'&&s2[2]=='F'; 
			bool e=s2[2]=='A'&&s1[2]=='B';
			bool f=s2[2]=='B'&&s1[2]=='C';
			bool g=s2[2]=='A'&&s1[2]=='C';
			bool h=s2[2]=='D'&&s1[2]=='F'; 
			if(a||b||c||d||e||f||g||h)
			{
				cout << '1';
				if(a||b||d||e||f||h)
				{
					cout << '1';
				}
				else
				{
					cout << '0';
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
	return 0;
}

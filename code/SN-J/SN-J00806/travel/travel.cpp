//严禹皓 西安交通大学附属中学 SN-J00806 
#include<bits/stdc++.h>
using namespace std;

int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin >> c1 >> s1 >> c2 >> s2;
	int a,b;
	if(s1[2]=='A')a=1;
	if(s1[2]=='B')a=2;
	if(s1[2]=='C')a=3;
	if(s1[2]=='D')a=4;
	if(s1[2]=='E')a=5;
	if(s2[2]=='A')b=1;
	if(s2[2]=='B')b=2;
	if(s2[2]=='C')b=3;
	if(s2[2]=='D')b=4;
	if(s2[2]=='E')b=5;
	if(c1==c2)
	{
		cout << "1";
		if(s1[1]==s2[1])
		{
			cout << "1";
			if((a<=3&&b<=3)||(a>3&&b>3))
			{
				cout<<"1";
				if(abs(a-b)==1)cout<<"1";
				else cout << "0";
			}
			else cout << "00";
		}
		else cout << "000";
	}
	else cout << "0000";
	
	return 0;
}

#include<bits/stdc++.h>
using namespace std;

string c1,s1,c2,s2;
string res;

bool check(char a, char b)
{
	if(a=='A'&&b=='B')return 1;
	if(a=='B'&&b=='C')return 1;
	if(a=='D'&&b=='F')return 1;
	return 0;
}

int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2)
	{
		res+='1';
		string r1,r2;
		r1=s1.substr(0,2),r2=s2.substr(0,2);
		if(r1==r2)
		{
			res+='1';
			char k1,k2;
			k1=s1[2],k2=s2[2];
			if((k1<='C'&&k2<='C')||(k1>='D'&&k2>='D'))
			{
				res+='1';
				if(check(k1,k2))res+='1';
				else res+='0';
			}
			else res+="00";
		}
		else res+="000";
	}
	else res="0000";
	cout<<res;
	return 0;
}


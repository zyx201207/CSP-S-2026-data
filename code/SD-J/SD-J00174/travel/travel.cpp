#include<bits/stdc++.h>
#define IOS ios::sync_with_stdio(0);cin.tie(0),cout.tie(0);

using namespace std;

string c1,s1,c2,s2;

bool check1(string s1,string s2)
{
	char a=s1[2],b=s2[2];
	if(a=='F'&&b=='D'||a=='D'&&b=='F'||
	a=='A'&&b=='B'||a=='B'&&b=='A'||
	a=='B'&&b=='C'||a=='C'&&b=='B'||
	a=='A'&&b=='C'||a=='C'&&b=='A')
	return true;
	
	return false;
}

bool check2(string x,string y)
{
	int a=int(x[2]),b=int(y[2]);
	if((abs(a-b)==1)||(x[2]=='F'&&y[2]=='D')||(x[2]=='D'&&y[2]=='F'))
	return true;
	return false;
}

int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	IOS
	
	cin>>c1>>s1>>c2>>s2;
	
	if(c1==c2)
	{
		cout<<"1";
		if(s1[0]==s2[0]&&s1[1]==s2[1])
		{
			cout<<"1";
			if(check1(s1,s2))
			{
				cout<<"1";
				if(check2(s1,s2))
				{
					cout<<"1";
				}
				else cout<<"0";
			}
			else cout<<"00";
		}
		else cout<<"000";
	}
	else cout<<"0000";
		
	return 0;
}

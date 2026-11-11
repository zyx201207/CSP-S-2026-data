#include<bits/stdc++.h>
using namespace std;
bool yice(char a,char b)
{
	if(a=='D'&&b=='F') return true;
	if(a=='F'&&b=='D') return true;
	if(a=='C'&&(b=='A'||b=='B')) return true;
	if(a=='A'&&(b=='C'||b=='B')) return true;
	if(a=='B'&&(b=='A'||b=='C')) return true;
	return false;
}
bool xianglin(char a,char b)
{
	if(a=='D'&&b=='F') return true;
	if(a=='F'&&b=='D') return true;
	if(a=='C'&&b=='B') return true;
	if(a=='A'&&b=='B') return true;
	if(a=='B'&&(b=='A'||b=='C')) return true;
	return false;
}
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,c2,s1,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2)
	{
		cout<<1;
		if(s1[0]==s2[0]&&s1[1]==s2[1])
		{
			cout<<1;
			if(yice(s1[2],s2[2]))
			{
				cout<<1;
				if(xianglin(s1[2],s2[2]))
				{
					cout<<1;
				}
				else cout<<0;
			}
			else cout<<"00";
		}
		else cout<<"000";
	}
	else cout<<"0000";
	return 0;
} 
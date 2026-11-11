#include<bits/stdc++.h>
using namespace std;
int check(char a,char b)
{
	if((a<='C'&&a>='A')&&(b<='C'&&b>='A'))return 1;
	else if((a=='F'||a=='D')&&(b=='D'||b=='F'))return 1;
	else return 0;
}
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,c2;
	int a1,a2;
	char s1,s2;
	cin>>c1>>a1>>s1>>c2>>a2>>s2;
	if(c1==c2)
	{
		cout<<"1";
		if(a1==a2)
		{
			cout<<"1";
			if(check(s1,s2)==1)
			{
				cout<<"1";
				if(s1+1==s2||s1-1==s2)cout<<"1";
				else cout<<"0";
			}
			else cout<<"00";
		}
		else cout<<"000";
	}
	else cout<<"0000";
	return 0;
} 

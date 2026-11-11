#include <iostream>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int c1,c2;
	string s1,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2)
	{
		cout<<"1";
		int a=(s1[0]-'0')*10+s1[1]-'0';
		int b=(s2[0]-'0')*10+s2[1]-'0';
		if(a==b)
		{
			cout<<"1";
			if(s1[2]=='A'&&s2[2]=='B'||s1[2]=='A'&&s2[2]=='C'||s1[2]=='B'&&s2[2]=='C')
			{
				cout<<"1";
			}else if(s1[2]=='B'&&s2[2]=='A'||s1[2]=='C'&&s2[2]=='A'||s1[2]=='C'&&s2[2]=='B')
			{
				cout<<"1";
			}else if(s1[2]=='D'&&s2[2]=='F'||s1[2]=='F'&&s2[2]=='D')
			{
				cout<<"1";
			}else
			{
				cout<<"0";
			}
			if(s1[2]=='A'&&s2[2]=='B'||s1[2]=='B'&&s2[2]=='A')
			{
				cout<<"1";
			}else if(s1[2]=='B'&&s2[2]=='C'||s1[2]=='C'&&s2[2]=='B')
			{
				cout<<"1";
			}else if(s1[2]=='D'&&s2[2]=='F'||s1[2]=='F'&&s2[2]=='D')
			{
				cout<<"1";
			}else
			{
				cout<<"0";
			}
		}else
		{
			cout<<"000";
		}
	}else
	{
		cout<<"0000";
		return 0;
	}
	
	return 0;
}
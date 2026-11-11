#include<iostream>
#include<cstdio>
using namespace std;
string c1,s1,c2,s2;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1.size()!=c2.size())
	{
		cout<<"0000";
		return 0;
	}
	if(c1.size()==3&&c2.size()==3&&c1[2]!=c2[2])
	{
		cout<<"0000";
		return 0;
	}
	if(c1.size()==2&&c2.size()==2&&c1[1]!=c2[1])
	{
		cout<<"0000";
		return 0;
	}
	int x,y;
	x=int(s1[1]-'0')*10+int(s1[0]-'0');
	y=int(s2[1]-'0')*10+int(s2[0]-'0');
	if(x!=y)
	{
		cout<<"1000";
		return 0;
	}
	else
	{
		if(s1[2]-s2[2]==1||s2[2]-s1[2]==1)
		{
			if((s1[2]=='C'&&s2[2]=='D')||(s1[2]=='D'&&s2[2]=='C'))
			{
				cout<<"1100";
				return 0;
			}
			cout<<"1111";
		}
		else if((s1[2]-s2[2]>1||s2[2]-s1[2]>1)&&(s1[2]=='A'||s2[2]=='A')) cout<<"1110";
		else cout<<"1100";
	}
	return 0;
}

#include <iostream>
#include <cstdio>
using namespace std;
string s1,s2;
int x,y;
bool flag1,flag2,flag3;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>x>>s1>>y>>s2;
	if(x==y)
	{
		flag1=true;
		cout<<1;
	}
	else{
		flag1=false;
		cout<<0;
	}
	if(flag1&&s1[0]==s2[0]&&s1[1]==s2[1])
	{
		flag2=true;
		cout<<1;
	}
	else{
		flag2=false;
		cout<<0;
	}
	if(flag2&&((s1[2]=='F'&&s2[2]=='D')||(s1[2]=='D'&&s2[2]=='F')
	||(s1[2]=='C'&&s2[2]=='B')||(s1[2]=='B'&&s2[2]=='C')||(s1[2]=='C'&&s2[2]=='A')
	||(s1[2]=='A'&&s2[2]=='C')||(s1[2]=='B'&&s2[2]=='A')||(s1[2]=='A'&&s2[2]=='B')))
	{
		flag3=true;
		cout<<1;
	}
	else{
		flag3=false;
		cout<<0;
	}
	if(flag3&&!((s1[2]=='A'&&s2[2]=='C')||(s1[2]=='C'&&s2[2]=='A')))
	{
		cout<<1;
	}
	else{
		cout<<0;
	} 
	return 0;
}
//FD  CB CA BA

#include<iostream>
#include<cstring>
using namespace std;
string c1,s1,c2,s2;
int x,r,f;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);	
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c1>>s1>>c2>>s2;
	f=1;
	if(c1[0]==c2[0]&&c1[1]==c2[1])
	{
		cout<<1;
	}
	else
	{
		cout<<0;
		f=0;
	}
	if(s1[0]==s2[0]&&s1[1]==s2[1]&&f==1)
	{
		cout<<1;
	}
	else
	{
		cout<<0;
		f=0;
	}
	if(s1[2]=='F')
	{
		r=6;
	}
	else if(s1[2]=='D')
	{
		r=5;
	}
	else
	{
		r=s1[2]-'A'+1;
	}
	if(s2[2]=='F')
	{
		x=6;
	}
	else if(s2[2]=='D')
	{
		x=5;
	}
	else
	{
		x=s2[2]-'A'+1;
	}
	if(((r<=3&&x<=3)||(r>=5&&x>=5))&&f==1)
	{
		cout<<1;
	}
	else
	{
		cout<<0;
		f=0;
	}
	if((x-r==1||x-r==-1)&&f==1)
	{
		cout<<1;
	}
	else
	{
		cout<<0;
	}
	return 0;
} 

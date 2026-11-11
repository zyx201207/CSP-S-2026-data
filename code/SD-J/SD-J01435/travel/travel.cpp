#include<bits/stdc++.h>
using namespace std;
int c[5];
string s;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c[1];
	for(int i=1;i<4;i++)
	{
		cin>>s[i];
	}
	cin>>c[2];
	for(int i=4;i<7;i++)
	{
		cin>>s[i];
	}
	if(c[1]==c[2])
	{
		cout<<"1";
	}
	else
	{
		cout<<"0";
	}
	if(s[1]==s[4]&&s[2]==s[5])
	{
		cout<<"1";
	}
	else
	{
		cout<<"0";
	}
	if((s[1]==s[4]&&s[2]==s[5]&&s[3]=='A'&&s[6]!='D'&&s[6]!='F')||(s[1]==s[4]&&s[2]==s[5]&&s[3]=='B'&&s[6]!='D'&&s[6]!='F')||(s[1]==s[4]&&s[2]==s[5]&&s[3]=='C'&&s[6]!='D'&&s[6]!='F')||(s[1]==s[4]&&s[2]==s[5]&&s[3]=='D'&&s[6]!='A'&&s[6]!='B'&&s[6]!='C')||(s[1]==s[4]&&s[2]==s[5]&&s[3]=='F'&&s[6]!='A'&&s[6]!='B'&&s[6]!='C'))
	{
		cout<<"1";
	}
	else
	{
		cout<<"0";
	}
	if((s[1]==s[4]&&s[2]==s[5]&&s[3]=='A'&&s[6]=='B')||(s[1]==s[4]&&s[2]==s[5]&&s[3]=='B'&&s[6]=='C')||(s[1]==s[4]&&s[2]==s[5]&&s[3]=='D'&&s[6]=='F')||(s[1]==s[4]&&s[2]==s[5]&&s[3]=='B'&&s[6]=='A')||(s[1]==s[4]&&s[2]==s[5]&&s[3]=='C'&&s[6]=='B')||(s[1]==s[4]&&s[2]==s[5]&&s[3]=='F'&&s[6]=='D'))
	{
		cout<<"1";
	}
	else
	{
		cout<<"0";
	}	
	fclose(stdin);
	fclose(stdout);
	return 0;
}

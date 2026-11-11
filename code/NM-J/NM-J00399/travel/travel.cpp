#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	string s,s1,c,c1;
	long long i;
	cin>>s>>s1>>c>>c1;
	if(s==c) 
	{
		cout<<1;
	}
	else cout<<0;
	int len=s1.length();
	for(i=0;i<len;i++)
	{
		if(s1[0]==c1[0]&&s1[1]==c1[1]&&s==c)
		{
			cout<<1;
			break;
		}
		else 
		{
			cout<<0;
			break;
		}
	}
	for(i=0;i<len;i++)
	{
		if(s1[0]==c1[0]&&s1[1]==c1[1]&&s==c&&(s1[2]>='A'&&s1[2]<='C'&&c1[2]>='A'&&c1[2]<='C')||(s1[2]=='D'&&s1[2]=='F'&&c1[2]>='D'&&c1[2]<='F'&&s1[2]!='E'&&c1[2]!='E'))
		{
			cout<<1;
			break;
		}
		else 
		{
			cout<<0;
			break;
		}
	}
	for(i=0;i<len;i++)
	{
		if(s1[0]!=c1[0]||s1[1]!=c1[1]||(s1[0]!=c1[0]&&s1[1]!=c1[1]))
		{
			cout<<0;
			break;
		}
		if(s1[0]==c1[0]&&s1[1]==c1[1]&&s==c&&(s1[2]=='A'&&c1[2]=='B')||(s1[2]=='B'&&c1[2]=='A')||(s1[2]=='B'&&c1[2]=='C')||(s1[2]=='C'&&c1[2]=='B')||(s1[2]=='D'&&c1[2]=='F')||(s1[2]=='F'&&c1[2]=='D')&&(s1[2]>='A'&&s1[2]<='C'&&c1[2]>='A'&&c1[2]<='C'))
		{
			cout<<1;
			break;
		}
		else 
		{
			cout<<0;
			break;
		}
	}
	return 0;
}

#include<bits/stdc++.h>
using namespace std;

string b1,s1,b2,s2;

int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>b1>>s1>>b2>>s2;
	if(b1==b2)
	{
		cout<<1;
		if(s1[0]==s2[0]&&s1[1]==s2[1])
		{
			cout<<1;
			if(s1[2]>='D'&&s2[2]>='D'||s1[2]<='C'&&s2[2]<='C')
			cout<<1;
			else cout<<0;
		}
		else cout<<"00";
	}
	else cout<<"000";
	if(s1[2]=='A'&&s2[2]=='B'||s1[2]=='B'&&s2[2]=='C'||s2[2]=='D'&&s2[2]=='F'||s1[2]=='B'&&s2[2]=='a'||s1[2]=='C'&&s2[2]=='B'||s2[2]=='F'&&s2[2]=='D')cout<<1;
	else cout<<0;
 }
 
 //菲林斯生日快乐 
 //菲林斯等我比赛完着，生日快乐 

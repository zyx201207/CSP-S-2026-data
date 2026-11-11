#include<bits/stdc++.h>
using namespace std;
int a,b;
string s1,s2;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>s1>>b>>s2;
	if(a==b)
	{
		cout<<1;
		if(s1.substr(0,2)==s2.substr(0,2))
		{
			cout<<1;
			if(s1[2]<='C'&&s2[2]<='C' || s1[2]>='D'&&s2[2]>='D')
			{
				cout<<1;
			}
			else cout<<0;
			if((s1[2]=='F'||s2[2]=='F')&&(s1[2]=='D'||s2[2]=='D'))
			{
				cout<<1;
				return 0;
			}
			if(abs((s1[2]-'A')-(s2[2]-'A'))==1 && ((s1[2]!='C'&&s2[2]!='C')&&(s1[2]!='D'&&s2[2]!='D')))
			{
				cout<<1;
			}
			else cout<<0;
		}
		else cout<<"000";
	}
	else cout<<"0000";
	return 0;
} 

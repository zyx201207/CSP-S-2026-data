#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c,d;
	string s,t;
	cin>>c>>s>>d>>t;
	if((c=="01"||c=="16"||d=="01"||d=="16")||(c!=d))
	{
		cout<<"0000";
	}
	else if(c==d&&(s[0]!=t[0]||s[1]!=t[1]))
	{
		cout<<"1000";
	}
	else if(((s[2]>='A'&&s[2]<'D')&&(t[2]=='D'||t[2]=='F'))||((s[2]=='D'||s[2]=='F')&&(t[2]>='A'&&t[2]<'D')))
	{
		cout<<"1100";
	}
	else if((s[2]=='A'&&t[2]=='C')||(t[2]=='A'&&s[2]=='C'))
	{
		cout<<"1110";
	}
	else
	{
		cout<<"1111";
	}
	return 0;
}

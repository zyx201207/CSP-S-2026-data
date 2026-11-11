#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,b,s,t;
	cin>>a>>s>>b>>t;
	if(a==b)cout<<1;
	else cout<<0;
	if(s[0]==t[0]&&s[1]==t[1])cout<<1;
	else cout<<0;
	if(s[0]==t[0]&&s[1]==t[1])
	{
		if(s[2]>='A'&&s[2]<='C'&&t[2]<='C'&&t[2]>='A')
			cout<<1;
		else if(s[2]>='D'&&s[2]<='F'&&t[2]<='F'&&t[2]>='D')
			cout<<1;
		else cout<<0;
	}	
	else cout<<0;
	if(s[0]==t[0]&&s[1]==t[1])
	{
		if(s[2]>='A'&&s[2]<='C'&&t[2]<='C'&&t[2]>='A')
			if(s[2]-t[2]==1||t[2]-s[2]==1)
			{
				cout<<1;
				return 0;
			}
	    if(s[2]>='D'&&s[2]<='F'&&t[2]<='F'&&t[2]>='D')
				{
					cout<<1;
					return 0;
				}
		cout<<0;
	}
	else cout<<0;
	return 0;
}

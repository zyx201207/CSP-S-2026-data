#include <bits/stdc++.h>
using namespace std;

typedef int itn;

int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int c1,c2;
	string s1,s2;
	cin>>c1>>s1>>c2>>s2;
	string ans;
	if(c1==c2)ans+='1';
	else return cout<<"0000",0;
	if(s1[0]==s2[0]&&s1[1]==s2[1])ans+='1';
	else return cout<<"1000",0;
	if('A'<=s1[2]&&s1[2]<='C'&&'A'<=s2[2]&&s2[2]<='C'||'D'<=s1[2]&&s1[2]<='F'&&'D'<=s1[2]&&s1[2]<='F')ans+='1';
	else return cout<<"1100",0;
	if(abs(s1[2]-s2[2])==1)ans+='1';
	else return cout<<"1110",0;
	cout<<ans;
	return 0;
}
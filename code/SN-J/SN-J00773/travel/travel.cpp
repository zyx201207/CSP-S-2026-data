//SN-J00773 林靖轩 西安辅轮中学
#include<bits/stdc++.h>
#define int long long
using namespace std;
bool p1=true,p2=true;
string c1,c2,s1,s2;
bool p(string s1,string s2)
{
	if((s1[2]=='A' || s1[2]=='B' || s1[2]=='C') && (s2[2]=='A' || s2[2]=='B' || s2[2]=='C'))
		return true;
	else if((s1[2]=='D' || s1[2]=='E') && (s2[2]=='D' || s2[2]=='E'))
		return true;
	else 
	return false;
}
bool pp(string s1,string s2)
{
	if(s1[2]=='A' && s2[2]=='B' ||
	   s1[2]=='B' && (s2[2]=='A' || s2[2]=='C') ||
	   s1[2]=='C' && s2[2]=='B' ||
	   s1[2]=='D' && s2[2]=='E' ||
	   s1[2]=='E' && s2[2]=='D')
	return true;
	else return false;
}
signed main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2)
		cout<<1;
	else cout<<0,p1=false;
	if(s1[0]==s2[0] && s1[1]==s2[1] && p1==true)
		cout<<1;
	else cout<<0,p2=false;
	if(p(s1,s2)==true && p2==true)
		cout<<1;
	else cout<<0;
	if(pp(s1,s2)==true && s1[0]==s2[0] && s1[1]==s2[1])
		cout<<1;
	else cout<<0;
	return 0;
}

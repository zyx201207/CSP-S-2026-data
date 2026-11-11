#include<bits/stdc++.h>
using namespace std;
string s;
int cxr,pr,zyr,cxx,px,zyx;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>s;
	cxr=(s[0]-'0')*10+s[1]-'0';
	cin>>s;
	pr=(s[0]-'0')*10+s[1]-'0';
	zyr=s[2];
	
	cin>>s;
	cxx=(s[0]-'0')*10+s[1]-'0';
	cin>>s;
	px=(s[0]-'0')*10+s[1]-'0';
	zyx=s[2];
	
	if(cxr==cxx) cout<<1;
	else {cout<<"0000";return 0;}
	
	if(pr==px) cout<<1;
	else {cout<<"000";return 0;}
	
	if(((zyr=='A'||zyr=='B'||zyr=='C')&&(zyx=='A'||zyx=='B'||zyx=='C'))||((zyr=='D'||zyr=='F')&&(zyx=='D'||zyx=='F'))) cout<<1;
	else {cout<<"00";return 0;}
	
	if(zyr=='A'&&zyx=='B'||zyr=='B'&&zyx=='A'||zyr=='B'&&zyx=='C'||zyr=='C'&&zyx=='B'||zyr=='D'&&zyx=='F'||zyr=='F'&&zyx=='D') cout<<1;
	else cout<<0;
}
//Trick||Treat!
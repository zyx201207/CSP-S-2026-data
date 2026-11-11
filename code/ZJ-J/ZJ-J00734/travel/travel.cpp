#include<bits/stdc++.h>
using namespace std;
int che1,che2;
string s1,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>che1>>s1>>che2>>s2;
	if(che1==che2)cout<<1;
	else cout<<0;
	if(che1==che2&&s1[0]==s2[0]&&s1[1]==s2[1])cout<<1;
	else cout<<0;
	if(che1==che2&&(s1[0]==s2[0]&&s1[1]==s2[1])&&(((s1[2]=='A'||s1[2]=='B'||s1[2]=='C')&&(s2[2]=='A'||s2[2]=='B'||s2[2]=='C')) || ((s1[2]=='D'||s1[2]=='F')&&(s2[2]=='D'||s2[2]=='F'))))cout<<1;
	else cout<<0;
	if(che1==che2&&(s1[0]==s2[0]&&s1[1]==s2[1])&&((s1[2]=='A'&&s2[2]=='B')||(s1[2]=='B'&&s2[2]=='A')||(s1[2]=='B'&&s2[2]=='C')||(s1[2]=='C'&&s2[2]=='B')||(s1[2]=='D'&&s2[2]=='F')||(s1[2]=='F'&&s2[2]=='D')))cout<<1;
	else cout<<0;
	return 0;
}/*
02 01A 02 01B
02 01C 02 01A
02 01C 02 01D
02 02B 02 01A
02 01A 03 01A
*/
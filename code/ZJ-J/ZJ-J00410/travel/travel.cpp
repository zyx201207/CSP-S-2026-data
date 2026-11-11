#include<bits/stdc++.h>
using namespace std;
int a1,a2;
string s1,s2;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a1>>s1>>a2>>s2;
	if(a1!=a2)cout<<"0000";
	else if(s1[0]!=s2[0]||s1[1]!=s2[1])cout<<"1000";
	else if(((s1[2]=='A'||s1[2]=='B'||s1[2]=='C')&&(s2[2]=='D'||s2[2]=='F'))||((s2[2]=='A'||s2[2]=='B'||s2[2]=='C')&&(s1[2]=='D'||s1[2]=='F')))cout<<"1100";
	else if(abs(s1[2]-s2[2])!=1)cout<<"1110";
	else cout<<"1111";
	return 0;
}
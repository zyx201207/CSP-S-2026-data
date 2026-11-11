#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int a,b,c,d;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","r",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2) a=1;
	else a=0;
	if(s1[0]==s2[0] && s1[1]==s2[1] && a==1) b=1;
	else b=0;
	if(((s1[2]=='A' && s2[2]=='B') || (s1[2]=='A' && s2[2]=='C') || (s1[2]=='B' && s2[2]=='C') || (s1[2]=='D' && s2[2]=='F') || (s1[2]=='C' && s2[2]=='A') ||(s1[2]=='C' && s2[2]=='B') || (s1[2]=='F' && s2[2]=='D'))&& b==1) c=1;
	else c=0;
	if(c==1 && abs(s1[2]-s2[2])==1) d=1;
	else d=0;
	cout<<a<<b<<c<<d;
	return 0;
} 

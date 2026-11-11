#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
bool a,b,c,d;
int solve(string s){
	if(s[2]=='A'||s[2]=='B'||s[2]=='C')
		return 1;
	else return 2;
}
int solve2(string s11,string s22){
	if(s11[2]=='A'&&s22[2]=='B')
		return 1;
	else if(s11[2]=='B'&&s22[2]=='A')
		return 1;
	else if(s11[2]=='B'&&s22[2]=='C')
		return 1;
	else if(s11[2]=='C'&&s22[2]=='B')
		return 1;
	else if(s11[2]=='D'&&s22[2]=='F')
		return 1;
	else if(s11[2]=='F'&&s22[2]=='D')
		return 1;
	else return 0;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2)
		a=1;
	if(a==1&&s1[0]==s2[0]&&s1[1]==s2[1])
		b=1;
	if(b==1&&solve(s1)==solve(s2)){
		c=1;
	}
	if(c==1&&solve2(s1,s2)){
		d=1;
	}
	cout<<a<<b<<c<<d;
	return 0;
}


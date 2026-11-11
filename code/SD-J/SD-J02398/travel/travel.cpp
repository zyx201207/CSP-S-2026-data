#include<bits/stdc++.h>
using namespace std;
int c1,c2;string s1,s2;
int s1c,s2c;
bool ck3(){
	if((s1[2]=='A'||s1[2]=='B'||s1[2]=='C')&&s2[2]=='D')
		return 0;
	if((s1[2]=='A'||s1[2]=='B'||s1[2]=='C')&&s2[2]=='F')
		return 0;
	return 1;
}
bool ck4(){
	if(s1[2]=='A'&&(s2[2]=='C'||s2[2]=='D'||s2[2]=='F'))
		return 0;
	if(s1[2]=='B'&&(s2[2]=='D'||s2[2]=='F'))
		return 0;
	if(s1[2]=='C'&&(s2[2]=='A'||s2[2]=='D'||s2[2]=='F'))
		return 0;
	if((s1[2]=='D'||s1[2]=='F')&&(s2[2]=='A'||s2[2]=='B'||s2[2]=='C'))
		return 0;
	return 1;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;	
	s1c=s1[1]-'0'+(s1[0]-'0')*10;
	s2c=s2[1]-'0'+(s2[0]-'0')*10;
	
	if(c1==c2)cout<<1;
	else cout<<0;
	if(c1==c2&&s1c==s2c)cout<<1;
	else cout<<0;
	if(c1==c2&&s1c==s2c&&ck3())cout<<1;
	else cout<<0;
	if(c1==c2&&s1c==s2c&&ck4())cout<<1;
	else cout<<0;
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
string s="0000";
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		s[0]='1';
		string s11=s1.substr(0,2);
		string s21=s2.substr(0,2);
		if(s11==s21){
			s[1]='1';
			if((s1[2]=='A'&&s2[2]=='B')||(s1[2]=='B'&&s2[2]=='A')){
				s[2]='1';
				s[3]='1';
			}else if((s1[2]=='A'&&s2[2]=='C')||(s1[2]=='C'&&s2[2]=='A')){
				s[2]='1';
			}else if((s1[2]=='C'&&s2[2]=='B')||(s1[2]=='B'&&s2[2]=='C')){
				s[2]='1';
			}else if((s1[2]=='D'&&s2[2]=='F')||(s1[2]=='F'&&s2[2]=='D')){
				s[2]='1';
				s[3]='1';
			}
		} 
	}
	cout<<s;
	return 0;
}

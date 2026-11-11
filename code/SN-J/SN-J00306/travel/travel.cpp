#include<bits/stdc++.h>
using namespace std;
string s1,c1,s2,c2,s;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		s[0]='1';
	}
	else{
		s[0]='0';
		s[1]='0';
		s[2]='0';
		s[3]='0';
	}
	if(s[0]=='1'){
		for(int i=1;i<=2;i++){
		if(s1[0]==s2[0] && s1[1]==s2[1]){
			s[1]='1';
		}
		else{
			s[0]='1';
			s[1]='0';
			s[2]='0';
			s[3]='0';
		}
	}
	}
	if(s[1]=='1'){
		if((s2[2]=='A' && s1[2]=='B') || (s1[2]=='A' && s2[2]=='B') || (s2[2]=='B' && s1[2]=='C') || (s2[2]=='C' && s1[2]=='B') || (s1[2]=='F' && s2[2]=='D') || (s1[2]=='D' && s2[2]=='F')){
			s[0]='1';
			s[1]='1';
			s[2]='1';
			s[3]='1';
		}
		else{
			s[0]='1';
			s[1]='1';
			s[2]='1';
			s[3]='0';
		}
	}
	cout<<s[0]<<s[1]<<s[2]<<s[3];
	return 0;
} 

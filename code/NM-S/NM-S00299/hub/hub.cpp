#include<bits/stdc++.h>
using namespace std;
string c1,c2,s2,s1;
int s[3];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1[0]-'0'==c2[0]-'0' && c1[1]-'0'==c2[1]-'0') cout<<1;
	else{
		cout<<"0000";
		return 0;
	}
	if(s1[0]-'0'==s2[0]-'0' && s1[1]-'0'==s2[1]-'0') {
		cout<<1;
		if(s1[2]=='A' and (s2[2]=='B' or s2[2]=='C')) {
			cout<<1;
			s[2]=1;
			if(s1[2]=='A' and s2[2]=='B') cout<<1;
			else cout<<0;
		}
		if(s1[2]=='B' and (s2[2]=='A' or s2[2]=='C')){
			cout<<"11";
			s[2]=1;	
		}
		if(s1[2]=='C' and (s2[2]=='B' or s2[2]=='A')){
			cout<<1;
			s[2]=1;
			if(s1[2]=='C' and s2[2]=='B') cout<<1;
			else cout<<0;
		}
		if(s1[2]=='D' and s2[2]=='E'){
			cout<<"11";
			s[2]=1;	
		}
		if(s1[2]=='E' and s2[2]=='D'){
			cout<<"11";
			s[2]=1;
		}
		if(s[2]!=1){
			cout<<"00";
			return 0;
		}
	}
	else {
		cout<<"000";
		return 0;	
	}
	return 0;
} 

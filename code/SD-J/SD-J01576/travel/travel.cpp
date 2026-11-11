#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
string s="0000";
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>c1>>s1>>c2>>s2; 
	if(c1==c2){
		s[0]='1';
	}else{
		cout<<s;
		return 0;
	}
	if(s1[0]==s2[0] && s1[1]==s2[1]){
		s[1]='1';
	}else{
		cout<<s;
		return 0;
	}
	if(s1[2]=='A' || s1[2]=='B' || s1[2]=='C'){
		if(s2[2]=='A' || s2[2]=='B' || s2[2]=='C'){
			s[2]='1';
		}else{
			cout<<s;
			return 0;
		}
	}else if(s1[2]=='D' || s1[2]=='F'){
		if(s2[2]=='D' || s2[2]=='F'){
			s[2]='1';
		}else{
			cout<<s;
			return 0;
		}
	}
	if(s1[2]=='A' && s2[2]=='B'){
		s[3]='1';
	}else if(s1[2]=='B' && s2[2]=='C'){
		s[3]='1';
	}else if(s1[2]=='D' && s2[2]=='F'){
		s[3]='1';
	}else if(s1[2]=='B' && s2[2]=='A'){
		s[3]='1';
	}else if(s1[2]=='C' && s2[2]=='B'){
		s[3]='1';
	}else if(s1[2]=='F' && s2[2]=='D'){
		s[3]='1';
	}else{
		cout<<s;
		return 0;
	}
	cout<<s;
	return 0;
} 

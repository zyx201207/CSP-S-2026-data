#include<bits/stdc++.h>
using namespace std;
int main(){
	string c1,s1,c2,s2;
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1[0]!=c2[0]||c1[1]!=c2[1]){
		cout<<"0000";
	}
	else if(s1[0]!=s2[0]||s1[1]!=s2[1]){
		cout<<"1000";
	}
	else if(s1[2]=='A'&&s2[2]!='B'&&s1[2]=='A'&&s2[2]!='C'||s1[2]=='B'&&s2[2]!='A'&&s1[2]=='B'&&s2[2]!='C'||s1[2]=='C'&&s2[2]!='A'&&s1[2]=='C'&&s2[2]!='B'){
		cout<<"1100";
	}
	else if(s1[2]=='D'&&s2[2]!='F'||s2[2]=='D'&&s1[2]!='F'){
		cout<<"1100";
	}
	else if(s1[2]=='A'&&s2[2]!='B'||s1[2]=='B'&&s2[2]!='C'||s1[2]=='B'&&s2[2]!='A'||s1[2]=='D'&&s2[2]!='F'){
		cout<<"1110";
	}
	else if(s2[2]=='A'&&s1[2]!='B'||s2[2]=='B'&&s1[2]!='A'||s2[2]=='B'&&s1[2]!='C'||s2[2]=='D'&&s1[2]!='F'){
		cout<<"1110";
	}
	else{
		cout<<"1111";
	} 
	return 0;
}

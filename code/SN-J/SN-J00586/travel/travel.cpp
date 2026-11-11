#include<bits/stdc++.h>
using namespace std;

int main(){
	int c1,c2;
	string s1,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<1;
	}else{
		cout<<0;
	}
	if(s1[0]==s2[0]&&s1[1]==s2[1]){
		cout<<1;
	}else{
		cout<<0;
	}
	char a=s1[2];
	char b=s2[2];
	if(a<='C'&&b<='C'||a>='D'&&b>='D'&&a<='E'&&b<='E'){
		cout<<1;
	}else{
		cout<<0;
	}
	if(a=='A'&&b=='B'||a=='B'&&b=='A'||a=='B'&&b=='C'||a=='C'&&b=='B'||a=='D'&&b=='E'||a=='E'&&b=='D'){
		cout<<1;
	}else{
		cout<<0;
	}
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
string s1,s2;
int c1,c2,s1_l,s2_l;
char s1_h,s2_h;
bool sa;
int main(){
	freopen("travel.in","stdin");
	freopen("travel.out","stdout");
	cin>>c1>>s1>>c2>>s2;
	s1_h=s1[2];
	s2_h=s2[2];
	s1_l=(s1[0]-'0')*10+(s1[1]-'0');
	s2_l=(s2[0]-'0')*10+(s2[1]-'0');
	if(c1==c2){
		cout<<"1";
		
	}else{
		cout<<"0";	
	}
	//
	
	if(c1==c2&&s1_l==s2_l) cout<<"1";
	else cout<<"0";
	//
	
	if(s1_h>='D'&&s2_h>='D'){
		sa=1;
	}else if(s1_h<='C'&&s2_h<='C'){
		sa=1;
	}
	//
	
	if(c1==c2&&s1_l==s2_l&&sa==1) cout<<"1";
	else cout<<"0";
	//
	
	if(c1==c2&&s1_l==s2_l&&sa==1&&(s1_h-1==s2_h||s2_h-1==s1_h)){
		cout<<"1";
	}else{
		cout<<"0";
	}
	return 0;
} 

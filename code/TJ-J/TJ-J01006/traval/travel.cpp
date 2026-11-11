#include<bits/stdc++.h>
using namespace std;
bool check1(char a,char b){
	if((a=='A'&&(b=='B'||b=='C'))
	||(a=='B'&&(b=='A'||b=='C'))
	||(a=='C'&&(b=='A'||b=='B'))
	||(a=='D'&&b=='F')
	||(a=='F'&&b=='D'))
	{return true;}
	return false;
}
bool check2(char a,char b){
	if((a=='A'&&b=='C')||(a=='C'&b=='A')){return false;}
	return true;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	string s1,s2,s3,s4;
	cin>>s1>>s2>>s3>>s4;
	if(s1==s3){cout<<1;}
	else{cout<<0<<0<<0<<0; return 0;}
	
	if((s2[0]-'0')*10+(s2[1]-'0')==(s4[0]-'0')*10+(s4[1]-'0')){cout<<1;}
	else{cout<<0<<0<<0; return 0;}
	
	if(check1(s2[2],s4[2])){cout<<1;}
	else{cout<<0<<0; return 0;}
	
	if(check2(s2[2],s4[2])){cout<<1;}
	else{cout<<0;}
	return 0;
} 

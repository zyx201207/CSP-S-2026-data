#include<bits/stdc++.h>
using namespace std;
bool check(string s1,string s2){
	if(s1[2]>='A' && s1[2]<='C' && s2[2]>='A' && s2[2]<='C') return 1;
	else if((s1[2]=='D' && s2[2]=='D') || (s1[2]=='F' && s2[2]=='F')) return 1;
	return 0;
}
bool check2(string s1,string s2){
	if(s1[2]=='D'){
		if(s2[2]=='F')return 1;
		else return 0;
	}
	else if(s2[2]=='D'){
		if(s1[2]=='F')return 1;
		else return 0;
	}
	int diff=abs(s2[2]-s1[2]);
	if(diff==1){
		if(s1[2]=='C'){
			if(s2[2]=='B')return 1;
			else return 0;
		}
		else if(s2[2]=='C'){
			if(s1[2]=='B')return 1;
			else return 0;
		}
		return 1;
	}else return 0;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string s1,s2,s3,s4;
	cin>>s1>>s2>>s3>>s4;
	if(s1==s3)cout<<1;
	else{
		cout<<"0000";
		return 0;	
	}
	if(s2[0]==s4[0] && s2[1]==s4[1])cout<<1;
	else cout<<0;
	if(s2[0]==s4[0] && s2[1]==s4[1] && check(s2,s4))cout<<1;
	else cout<<0;
	if(s2[0]==s4[0] && s2[1]==s4[1] && check2(s2,s4))cout<<1;
	else cout<<0;
	return 0;
}
//Trick||Treat!

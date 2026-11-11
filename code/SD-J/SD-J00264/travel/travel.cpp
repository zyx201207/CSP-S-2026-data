#include<bits/stdc++.h>
using namespace std;
bool check_side(string s1,string s2){
	int ck1,ck2;
	if(s1[2]=='A'||s1[2]=='B'||s1[2]=='C'){
		ck1=1;
	}
	else{
		ck1=2;
	}
	if(s2[2]=='A'||s2[2]=='B'||s2[2]=='C'){
		ck2=1;
	}
	else{
		ck2=2;
	}
	if(ck1==ck2){
		return true;
	}
	return false;
}
bool check_by(string s1,string s2){
	int ck1,ck2;
	if(s1[2]=='A'||s1[2]=='B'||s1[2]=='C'){
		ck1=1;
	}
	else{
		ck1=2;
	}
	if(s2[2]=='A'||s2[2]=='B'||s2[2]=='C'){
		ck2=1;
	}
	else{
		ck2=2;
	}
	if(ck1==ck2&&ck1==1){
		if((s1[2]=='A'&&s2[2]=='C')||(s2[2]=='A'&&s1[2]=='C')){
			return false;
		}
	}
	return true;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<1;
	}
	else{
		cout<<"0000";
		return 0;
	}
	
	if(s1[0]==s2[0]&&s1[1]==s2[1]){
		cout<<1;
	}
	else{
		cout<<"000";
		return 0;
	}
	
	if(check_side(s1,s2)){
		cout<<1;
	}
	else{
		cout<<"00";
		return 0;
	}
	
	if(check_by(s1,s2)){
		cout<<1;
	}
	else{
		cout<<0;
	}
	return 0;
}

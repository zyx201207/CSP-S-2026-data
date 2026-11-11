#include<bits/stdc++.h> 
using namespace std;
char s[10];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	for(int i=0;i<=9;i++){
		cin>>s[i];
	}
	if(s[0]==s[5] && s[1]==s[6]){
		cout<<"1";
	}
	else{
		cout<<"0000";
		return 0;
	}
	if(s[2]==s[7] && s[3]==s[8]){
		cout<<"1";
	}
	else{
		cout<<"000";
		return 0;
	}
	if(s[4]=='A'||s[4]=='B'||s[4]=='C' && s[9]=='A'||s[9]=='B'||s[9]=='C'){
		cout<<"1";
	}
	else{
		cout<<"00";
		return 0;
	}
	if(s[4]+1==s[9] || s[4]-1==s[9]){
		cout<<"1";
	}
	else{
		cout<<"0";
		return 0;
	}
}

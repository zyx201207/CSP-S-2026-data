#include<bits/stdc++.h>
using namespace std;
int main(){
	string s[4];
	for(int i=0;i<4;i++){
		cin>>s[i];
	}
	if(s[0]==s[2]){
		cout<<1;
	}else{
		cout<<0;
	}
	if(s[1]==s[3]){
		cout<<0<<0<<0;
	}
	if(s[1]!=s[3]){
		cout<<0<<0<<0;		
	}
	return 0;
} 

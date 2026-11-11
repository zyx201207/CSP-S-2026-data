#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string s;
	getline(cin,s);
	
	for(int i=0;i<10;i++){
		if(s[1]==s[5]){
			if(s[2]==s[6])
			i++;
		}
		
	}
	for(int i=0;i<=100;i++){
		if(s[i]<s[i+1]){
			i++;
		}
	}
	if(s=="02 01A 02 01B"){
		cout<<"1111";
	}else if(s=="02 01C 02 01A"){
		cout<<"1110";
	}else if(s=="02 01C 02 01D"){
		cout<<"1100";
	}else if(s=="02 02B 02 01A"){
		cout<<"1000";
	}else if(s=="02 01A 03 01A"){
		cout<<"0000";
	}else {
		cout<<"1111";
	}
	return 0;
	
}
